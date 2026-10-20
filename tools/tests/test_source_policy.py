"""Unit and isolated-git regression tests for the source-policy tripwire."""

import hashlib
import json
import subprocess
import sys
import tempfile
import unittest
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
import check_source_policy as policy


class SourcePolicyTests(unittest.TestCase):
    def test_natural_c_allowed(self):
        self.assertFalse(policy.needs_approval("src/f.c", b"int f(int x) { return x + 1; }"))

    def test_comments_and_strings_are_not_assembly(self):
        source = b'/* asm {} */\n// __asm__\nchar *s = "asm and \\\"__asm__";\n'
        self.assertFalse(policy.needs_approval("src/f.c", source))

    def test_assembly_spellings(self):
        for keyword in (b"asm", b"__asm", b"__asm__", b"a\\\nsm"):
            with self.subTest(keyword=keyword):
                self.assertTrue(policy.needs_approval("src/f.c", keyword + b" void f() { bx lr }"))

    def test_mixed_inline_assembly_and_header(self):
        self.assertTrue(policy.needs_approval("include/f.h", b"void f() { asm(\"nop\"); }"))

    def test_standalone_assembly_requires_approval(self):
        for suffix in ("s", "S", "asm", "inc"):
            self.assertTrue(policy.needs_approval(f"src/f.{suffix}", b"bx lr\n"))

    def test_cpp_digit_separators_cannot_hide_assembly(self):
        source = b'auto n = 1\'000; asm("nop"); auto m = 0x2\'000;'
        self.assertTrue(policy.needs_approval("src/f.cpp", source))

    def test_digit_separators_and_character_literals_without_assembly(self):
        source = b'auto n = 1\'000; char c = \'a\'; auto m = 0x2\'000;'
        self.assertFalse(policy.needs_approval("src/f.cpp", source))

    def test_approval_requires_reason_and_exact_hash(self):
        source = b"asm void f() { bx lr }"
        path = "src/f.c"
        self.assertIsNotNone(policy.approval_error(path, source, {}))
        entry = {
            "sha256": hashlib.sha256(source).hexdigest(),
            "reason": "Test-only evidence",
            "approved_by": "Test human",
            "approval": "Test review reference",
        }
        self.assertIsNone(policy.approval_error(path, source, {path: entry}))
        self.assertIsNotNone(policy.approval_error(path, source + b"\n", {path: entry}))
        for field in ("reason", "approved_by", "approval"):
            bad = dict(entry, **{field: " "})
            self.assertIsNotNone(policy.approval_error(path, source, {path: bad}))


class GitPolicyTests(unittest.TestCase):
    def setUp(self):
        self.scratch = tempfile.TemporaryDirectory()
        self.addCleanup(self.scratch.cleanup)
        self.root = Path(self.scratch.name)
        self.run_git("init", "-q")
        self.run_git("config", "user.name", "Source policy test")
        self.run_git("config", "user.email", "test@example.invalid")
        self.write("src/legacy.c", b"asm void legacy() { bx lr }\n")
        self.write(policy.APPROVALS, b"{}\n")
        self.run_git("add", "src/legacy.c", policy.APPROVALS)
        self.run_git("commit", "-qm", "Test baseline")
        self.base = self.run_git("rev-parse", "HEAD").decode().strip()

    def run_git(self, *args):
        return subprocess.check_output(["git", *args], cwd=self.root, stderr=subprocess.STDOUT)

    def write(self, name, data):
        path = self.root / name
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_bytes(data)

    def test_unchanged_legacy_is_not_retroactively_approved_or_rejected(self):
        self.assertEqual(policy.check(self.root), [])

    def test_untracked_assembly_rejected(self):
        self.write("src/new.c", b"asm void f() { bx lr }")
        self.assertEqual(len(policy.check(self.root)), 1)

    def test_c_replacement_allowed(self):
        self.write("src/legacy.c", b"void legacy(void) {}\n")
        self.assertEqual(policy.check(self.root), [])

    def test_changed_legacy_requires_review(self):
        self.write("src/legacy.c", b"asm void legacy() { nop; bx lr }\n")
        self.assertEqual(len(policy.check(self.root)), 1)

    def test_index_cannot_be_hidden_by_worktree_edits_or_unstaged_approval(self):
        source = b"asm void f() { bx lr }\n"
        self.write("src/new.c", source)
        self.run_git("add", "src/new.c")
        self.write("src/new.c", b"void f(void) {}\n")
        manifest = {"src/new.c": {
            "sha256": hashlib.sha256(source).hexdigest(),
            "reason": "Test evidence", "approved_by": "Test human", "approval": "Test review",
        }}
        self.write(policy.APPROVALS, json.dumps(manifest).encode())
        self.assertEqual(len(policy.check(self.root, staged=True)), 1)
        self.run_git("add", policy.APPROVALS)
        self.assertEqual(policy.check(self.root, staged=True), [])

    def test_ci_checks_intermediate_commits(self):
        self.write("src/new.c", b"asm void f() { bx lr }\n")
        self.run_git("add", "src/new.c")
        self.run_git("commit", "-qm", "Unapproved assembly")
        self.assertEqual(policy.check(self.root), [])
        self.assertEqual(len(policy.check(self.root, base=self.base)), 1)

    def test_missing_base_fails_closed(self):
        with self.assertRaises(ValueError):
            policy.check(self.root, base="nonexistent-review-base")

    def test_malformed_manifest_fails_closed(self):
        self.write(policy.APPROVALS, b"[]")
        with self.assertRaises(ValueError):
            policy.check(self.root)


if __name__ == "__main__":
    unittest.main()
