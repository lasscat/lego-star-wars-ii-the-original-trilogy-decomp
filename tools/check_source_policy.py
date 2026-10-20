#!/usr/bin/env python3
"""Reject changed assembly sources without a hash-bound human approval.

This source-policy tripwire is separate from, and never replaces, ROM verification.
"""

import argparse
import hashlib
import json
import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
APPROVALS = "config/asm_approvals.json"
SOURCE_SUFFIXES = {".c", ".h", ".cc", ".cpp", ".cxx", ".hpp", ".s", ".asm", ".inc"}
ASSEMBLER_SUFFIXES = {".s", ".asm", ".inc"}
NON_CODE = re.compile(
    r'//[^\n]*|/\*.*?\*/|"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\''
    r"|\b[0-9](?:[0-9A-Za-z_.]|'[0-9A-Za-z_])*",
    re.DOTALL,
)
ASM_KEYWORD = re.compile(r"\b(?:asm|__asm|__asm__)\b")


def needs_approval(path: str, source: bytes) -> bool:
    suffix = Path(path).suffix.lower()
    if suffix not in SOURCE_SUFFIXES:
        return False
    if suffix in ASSEMBLER_SUFFIXES:
        return True
    # C line splicing occurs before tokenization, including in comments.
    text = re.sub(r"\\\r?\n", "", source.decode("utf-8", errors="replace"))
    return ASM_KEYWORD.search(NON_CODE.sub(" ", text)) is not None


def approval_error(path: str, source: bytes, approvals: dict) -> str | None:
    if not needs_approval(path, source):
        return None
    entry = approvals.get(path)
    if not isinstance(entry, dict):
        return "assembly requires explicit human approval"
    for field in ("reason", "approved_by", "approval"):
        if not isinstance(entry.get(field), str) or not entry[field].strip():
            return f"approval is missing {field}"
    digest = hashlib.sha256(source).hexdigest()
    if entry.get("sha256") != digest:
        return f"approval does not cover these exact source bytes (sha256: {digest})"
    return None


def git(root: Path, *args: str) -> bytes:
    result = subprocess.run(["git", *args], cwd=root, capture_output=True)
    if result.returncode:
        raise ValueError(result.stderr.decode(errors="replace").strip())
    return result.stdout


def read_source(root: Path, path: str, staged: bool) -> bytes:
    if staged:
        return git(root, "show", f":{path}")
    return (root / path).read_bytes()


def read_approvals(root: Path, staged: bool) -> dict:
    if staged:
        # An absent manifest means no approvals, not permission to skip the check.
        present = git(root, "ls-files", "--", APPROVALS).strip()
        data = read_source(root, APPROVALS, True) if present else b"{}"
    else:
        path = root / APPROVALS
        data = path.read_bytes() if path.exists() else b"{}"
    result = json.loads(data)
    if not isinstance(result, dict):
        raise ValueError(f"{APPROVALS} must be a JSON object")
    return result


def check(root: Path, base: str = "HEAD", staged: bool = False) -> list[str]:
    if not base or base.startswith("-"):
        raise ValueError("a valid comparison base is required")
    # Fail closed if CI supplied a missing/shallow/unavailable base.
    git(root, "rev-parse", "--verify", f"{base}^{{tree}}")
    args = ["diff", "--name-only", "--diff-filter=ACMRT", "-z"]
    if staged:
        args.append("--cached")
    paths = git(root, *args, base, "--").split(b"\0")
    if not staged:
        paths += git(root, "ls-files", "--others", "--exclude-standard", "-z").split(b"\0")
    approvals = read_approvals(root, staged)
    errors = []
    for raw_path in sorted(set(paths) - {b""}):
        path = raw_path.decode("utf-8")
        if Path(path).suffix.lower() not in SOURCE_SUFFIXES:
            continue
        source = read_source(root, path, staged)
        error = approval_error(path, source, approvals)
        if error:
            errors.append(f"{path}: {error}")
    return errors


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--base", default="HEAD", help="Review base (CI uses the PR base/previous push tip)")
    parser.add_argument("--staged", action="store_true", help="Check index content, including staged approvals")
    args = parser.parse_args()
    try:
        errors = check(ROOT, args.base, args.staged)
    except (ValueError, OSError) as error:
        print(f"SOURCE POLICY FAILED: {error}", file=sys.stderr)
        return 1
    if errors:
        print("SOURCE POLICY FAILED:")
        for error in errors:
            print(f"  {error}")
        print("Leave the function unfinished or obtain per-source human approval.")
        print("See AGENTS.md and docs/source-policy.md. ROM verification is a separate gate.")
        return 1
    print("SOURCE POLICY PASSED (changed sources only; human approval/provenance still require review)")
    return 0


if __name__ == "__main__":
    sys.exit(main())
