# Matching exceptions

Natural C (or natural C++, see [cpp.md](cpp.md)) is always the goal. The constructs below are accepted only
when a function matches byte-for-byte and no natural source has been found. Each one must be marked in the
source so it can be found and replaced later, and each category goes in its own PR.

## Hand-written assembly

Accepted for functions the compiler cannot produce from C, for example:

- predicated 8-register `ldm`/`stm`;
- zero loaded from an unrelocated literal-pool word;
- the assembly-only instructions listed in [automation.md](automation.md).

Rules:

- an `asm` function in its usual one-function source (`src/auto/<name>.c`), like `DC_FlushRange`, wrapped in
  `// clang-format off` / `// clang-format on` (see [troubleshooting.md](troubleshooting.md));
- an `// ASM:` comment above it that names the instruction or pattern C cannot produce;
- report it as an approved assembly exception, not as C (see [cpp.md](cpp.md#integration-and-verification)).

## Constructors and `operator new`

Accepted in `.cpp` when the binary shows C++: a vptr store in the constructor, a call to the game's
`operator new`/allocator followed by a constructor call, or mangled names. The no-construction rule in
[cpp.md](cpp.md#no-accidental-vtables-or-initialization) still applies to everything the function does not
need: the object must not emit vtables, RTTI, `.ctor`/`.init` or other extra sections. Inspect it with
`readelf -SWs` before integration.

## Steering constructs (fakematches)

Dead stores, a duplicated compare and an always-true null test are accepted with a `// FAKE:` comment on
the line that explains what the construct forces. First try an `inline` helper or a macro: an always-true
null test or a repeated compare is often an inlined function in the original.

## `volatile` against load merging

Last resort only. Put `volatile` on a local cast or a local variable, never on a struct field (it changes
every other function that uses the field), and add a `// FAKE:` comment. Hardware registers stay
`volatile` as usual (see [compiler.md](compiler.md)).
