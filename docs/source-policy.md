# C reconstruction and assembly exceptions

The goal is matching, natural C, not a disassembly transcription that happens to live in
a `.c` file. `AGENTS.md` is authoritative. Both source-policy review and the unchanged
byte-identical ROM verifier are required.

## When C does not match

Keep the best C draft, profile, attempted hypotheses and diff in scratch. Report the
function as unfinished. Escalate or select another function. Failure to find the right
types, volatility, source structure or compiler profile is not evidence of impossibility.

An audit found exact default-profile C matches for `func_02074c7c` (volatile byte access)
and `func_02075fe0` (a struct-array `do` loop), despite both assembly implementations
claiming the compiler could never generate their instructions. Do not repeat that inference.

## Exceptional assembly

Before integrating a new or changed assembly source, request explicit approval from the
user or upstream maintainer. Provide the function, exact exceptional instructions or
independent evidence of original hand-written assembly, and why natural C is unsuitable.
An opcode screen, SDK name, previous assembly example or exhausted search is not approval.
Public availability alone does not establish that a donor is clean-room or licensed for
reuse; the existing clean-room rule still applies.

After human approval, record a per-source entry in `config/asm_approvals.json`:

```json
{
  "src/auto/example.c": {
    "sha256": "SHA256 of the exact final source bytes",
    "reason": "Specific instructions/evidence and why natural C is unsuitable",
    "approved_by": "Human user or upstream maintainer",
    "approval": "Review URL or explicit user instruction identifying this source"
  }
}
```

Agents must not invent approval, self-approve, batch-approve unspecified functions or
change the checker to accommodate a rejected candidate. Formatting changes invalidate a
source hash: obtain approval for the final source. Existing assembly is not automatically
approved by its presence in the repository. This change does not rewrite existing sources.

## Automated guard and review

```sh
venv/bin/python tools/check_source_policy.py --staged
venv/bin/python tools/check_source_policy.py --base origin/main
venv/bin/python -m unittest discover -s tools/tests -p 'test_source_policy.py'
```

The pre-commit hook checks staged content and staged approvals against HEAD. CI checks
all changed sources against the PR base or previous push tip, including intermediate
commits. Without `--staged`, the checker includes working-tree changes and untracked
sources. New/changed asm-bearing C/C++ headers and sources, standalone assembler files,
and `.inc` files (conservatively treated as assembly includes) need a matching approval
entry. It ignores comments and string literals when
looking for asm keywords. Existing unchanged assembly is outside the diff, not certified.

This is a conservative tripwire, not a C parser, proof of provenance, or protection against
a deliberately evasive author. Review source changes and approval-file/checker changes.
Do not hide opcodes in macros, data arrays, binary includes, alternate extensions or build
rules. Repository owners should require this CI check in branch protection; a local hook
alone can be skipped. ROM matching does not authorize a source-policy exception.

Report newly reconstructed C functions/bytes separately from approved assembly
functions/bytes. The existing mechanical progress percentage may include both; do not
present it as a C-only percentage.
