# Assembly-to-C repair status

The mechanical matching percentage includes legacy assembly transcriptions. This
repair effort replaces those transcriptions with natural C without changing the
ROM. A failed C reconstruction is unfinished, not evidence that assembly is required.

Audit baseline: additions/changes relative to upstream commit `10ca260`.
Initial backlog: **680 unreviewed assembly sources / 99,524 function bytes**.

## Verified C repairs

**6 functions / 264 bytes converted to C.** No assembly exceptions approved.
Remaining backlog: **674 sources / 99,260 function bytes**. Remaining sources
are unaudited; this does not claim that all of them should be rewritten in C.

| Function | Bytes | C reconstruction technique |
|---|---:|---|
| `func_02074c7c` | 32 | Volatile byte access, branch-local loads and a shared store |
| `func_02075fe0` | 40 | Struct-array indexing with an explicit increment in a do loop |
| `func_02086558` | 48 | Separate clear/set compound assignments with a signed word index |
| `func_020865ac` | 48 | Same bitset idiom, table at object offset 0x44EC |
| `func_02086600` | 48 | Same bitset idiom, table at object offset 0x450C |
| `func_02086e1c` | 48 | Same bitset idiom, table at object offset 0x451C |

All six use default `2.0/sp1p5` without extra flags. Each candidate was independently
rechecked, then integrated and verified in the full linked ROM after formatting:

```
INFO: 3716/4764 functions, 33.24% code
VERIFY PASSED
```

ROM SHA1 remains `7c1afa070797945ba5a2577c7ddfded5cf2fc443`.
These repairs do not add newly matched functions or increase the matching percentage.

## Checks still outstanding

The whole-branch source-policy gate still rejects the remaining unapproved
assembly additions. The staged-source policy check passes these C replacements;
that is not a declaration that the entire branch is source-policy compliant.

Full-repository formatting also finds 10 pre-existing issues in unrelated sources.
Those edits were restored instead of being mixed into the repair. Scoped hooks
for the repaired sources pass. No verifier, global compiler flags, delink ranges,
or generated prototypes were changed by these repairs.
