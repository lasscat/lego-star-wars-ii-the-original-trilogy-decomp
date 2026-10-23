# Natural C++ translation units

C is the default reconstruction language. Use natural C++ where the binary and
compiler probes support C++ constructs; do not replace difficult C with assembly.
Upstream accepted natural `.cpp` translation units for evidenced C++ routines in
the review of PR #3 and requested the small function-only pilot as a separate PR.

## When to try C++

- Prioritize virtual-dispatch candidates: an object pointer in `r0`, its vptr
  loaded from `[r0]`, a method loaded from a consistent vtable slot, and `blx`
  through that method. For example, a four-argument member call often uses
  `ldr ip, [r0]; ldr ip, [ip, #slot]; blx ip`.
- Check surrounding functions, object offsets, argument forwarding and vtable
  data. An indirect call alone is not proof of C++: ordinary C callbacks and
  function-pointer tables should remain C unless there is stronger evidence.
- A this-adjusting tail thunk can suggest multiple inheritance. Treat this as
  a separate compiler-generated-thunk investigation, not an automatic use of
  the function-only template below. Prove its class layout and all emitted
  methods/data before proposing integration. No such thunk is validated here.
- Do not claim that a pattern is impossible in C just because previous C
  attempts failed. C++ is a source-language hypothesis to test, not an escape
  hatch for register-allocation or control-flow mismatches.
- Do not convert working C files wholesale. Start with one representative of an
  evidenced family; retain its successful compiler command, source and diff.

## Build contract

`tools/configure.py` chooses language by extension on each Ninja edge:

| Source | Per-file selector |
|---|---|
| `.c` | `-lang=` the language from `game.toml` (default `c`) |
| `.cpp` | `-lang=c++` |

There must be **exactly one** language selector in a compilation command. Keep
it out of global `CC_FLAGS`, `extra_cc_flags` and per-file compiler overrides.
The `game.toml` `lang` key applies to `.c` files; `.cpp` files always select C++.
This project's ordinary reconstruction language remains C.
Do not change any other global compiler flag to match a target.

With the original `2.0/sp1p5` compiler, conflicting selectors resolve to C in
both orders. Adding `-lang=c++` to `config/usa/compilers.txt` therefore is not
an override for a global `-lang=c`. Do not work around this by changing flag
order, renaming C++ to `.c`, or injecting compiler directives.

The initial global-selector removal was checked with a full-ROM build and
whole-object hashes: all 3,097 pre-existing C ELF objects were byte-identical.
This is evidence for that exact change, not permission for future global flag
changes. `tools/tests/test_configure.py` protects the flag/extension contract
without needing the compiler or ROM; it does not replace binary verification.

## Plain symbols and partial interfaces

Use `extern "C"` on a plain-name ROM entry point and on declarations of plain-name
external functions/data referenced from C++. Without it, C++ functions are
mangled (for example `_Z7mangledP5Probe`). Do not rename symbols or add aliases
to accommodate accidental mangling. C++ declarations need real parameter types;
`f()` means no parameters, not the C meaning of unspecified parameters.

Use the validated source `src/auto/func_02020a9c.cpp` as the initial template.
Its virtual methods are **declarations only**. Unknown methods preserve the
observed slot positions; their names and unused signatures are provisional.
Do not add definitions, a virtual destructor or a guessed base class. Keep
repeated class declarations consistent across translation units; extract a
shared header only once the common interface is evidenced and verified.

The vptr points at the method address point: slot zero is offset zero. Do not
add the two-word vtable header to observed call-slot offsets. The pilot declares
nine preceding virtuals for offset `0x24` and eleven for offset `0x2c`.

## No accidental vtables or initialization

For the function-only pattern:

- Declare virtual methods, but do not define them, even as empty methods.
- Dispatch through existing object pointers; do not construct or destroy objects.
- Do not create global/static class instances, RTTI, exception machinery or
  replacement vtable arrays. `-RTTI off` alone does not prevent vtable emission.
- Inspect object sections and symbols before integration. The desired object
  has only the assigned function's allocatable `.text`; normal debug, string,
  symbol and comment metadata is expected and is not ROM data.

Probes showed that defining a non-inline virtual emitted `_ZTV5Probe` in `.data`.
A global class instance added `.bss`, `.ctor` and `.init`, with a vtable reference.
Declaration-only pointer dispatch emitted no vtable or runtime data. Do not
generalize these observations to every class shape or compiler version.

Useful read-only inspections (use installed ELF tools):

```sh
ninja -t commands build/usa/src/auto/func_02020a9c.o
readelf -SWs build/usa/src/auto/func_02020a9c.o
llvm-objdump --triple=armv5te-none-eabi -dr build/usa/src/auto/func_02020a9c.o
```

If a candidate emits additional runtime sections or helpers, stop the mechanical
integration. The coordinator must investigate them and either reconstruct their
original ownership/ranges explicitly or leave the candidate unfinished. Never
discard emitted sections, hide data, or weaken verification to force a match.

## Integration and verification

Use one source per function, a plain existing symbol, and an exclusive end:

```text
src/auto/func_02020a9c.cpp:
    complete
    .text       start:0x02020a9c end:0x02020ad4
```

The corresponding existing symbol stays:

```text
func_02020a9c kind:function(arm,size=0x38) addr:0x02020a9c
```

Before adding a block, check all existing source-owned ranges for overlaps. For
an existing assembly-to-C++ repair, replace the old source/delink ownership in
one coordinated change; do not append a second owner. Do not leave `.c` and
`.cpp` files with the same basename: both map to the same object path.

```sh
python tools/match.py verify
sha1sum lego_star_wars_ii_the_original_trilogy_usa.nds
```

Review the complete contribution for natural source and correct range ownership,
in addition to running binary verification. A byte match alone does not establish
that source is a natural reconstruction.

Only `VERIFY PASSED` from the unchanged full-ROM verifier establishes an
integrated match. The ROM SHA1 must remain
`7c1afa070797945ba5a2577c7ddfded5cf2fc443`. Standalone/masked comparisons and
objdiff percentages are candidate diagnostics, not this gate. Stage explicit
intended paths before the staged policy check; rerun full verification after
any formatter changes to source. Regenerate progress with the unchanged tool.

Report C, natural C++, and approved assembly exceptions separately. The generated
progress is mechanical binary coverage, not a pure-C reconstruction count. Do not
hand-edit generated values.

The first validated pilot is three C++ functions / 168 bytes:
`func_02020a9c`, `func_02020ad4`, and `func_02020e4c`. None requires extra data,
symbol changes, compiler overrides or assembly approvals.

## Tooling limits and role boundaries

Many existing draft/probe/transplant tools assume `.c` and hardcode `-lang=c`.
Extension support in configure.py does **not** make those tools C++-aware.
Do not feed `.cpp` into them without inspecting the actual compiler invocation.
For C++ scratch probes, use the exact coordinator-supplied compiler command
with one `-lang=c++`, otherwise unchanged profile flags, and a unique scratch
output. Missing prerequisites are a blocker, not permission to improvise.

The coordinator owns language selection, class/slot design, symbol and section
probes, range ownership, and the first full-ROM verification of a new pattern.
Workers use only assigned scratch directories and the assigned language/profile;
they do not change global flags or shared source/configuration. Escalation may
propose a C++ hypothesis but must not silently change the assignment's scope.

After a pattern is designed and fully verified, an explicitly authorized
mechanical integrator may receive exact `.cpp` contents, delink blocks, permitted
commands and log paths. Only that role may perform the specified shared-write /
full-verification loop while it exclusively owns the build. On any failure it
preserves the candidate and complete stdout/stderr and reports FAILED; only the
coordinator decides a fix. Reconstruction workers do not gain those privileges.
No role may commit, push, launch further work or change policy without the
current user's authorization. Local agent prompts and status records stay out
of contribution diffs.
