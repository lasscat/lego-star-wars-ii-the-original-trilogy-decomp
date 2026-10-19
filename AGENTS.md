# Instructions for AI agents

Matching decompilation of LEGO Star Wars II: The Original Trilogy (USA, `AL7E`, NDS): C
compiled with the original mwccarm must rebuild a **byte-identical ROM**. A function counts
only when the full ROM still verifies.

## Hard rules

1. The build decides. `python tools/match.py verify` must print `VERIFY PASSED` with ROM SHA1
   `7c1afa070797945ba5a2577c7ddfded5cf2fc443`. Masked compares do not count. Never commit
   otherwise, never weaken verification, never change the expected hash.
2. Never alter the global compiler flags in `tools/configure.py` to make something pass.
3. Clean room: only the game binary and public projects; never leaked sources or Nintendo SDK
   source. Do not contribute AI-generated code to projects that forbid it.
4. Natural C; `asm` only for instructions compilers never generate. ASCII only in `src/` and
   `include/` (sjiswrap fails on non-ASCII).
5. Never commit the ROM, BIOS, `extract/`, or `build/`. Stage explicit paths; never
   `git add .` or `git add -u`.

## Build / verify

```shell
python tools/configure.py usa      # add --compiler <path to mwccarm> if not in tools/mwccarm
ninja                              # build ROM
ninja dis                          # write build/usa/asm/*.s (needed by the diff tools)
python tools/match.py verify       # the only source of truth
```

- `tools/configure.py` also accepts `--dsd`, `--objdiff` and `--sjiswrap` to use pre-installed
  tools instead of downloading them.
- Regenerate the README progress with `python tools/match.py progress` after every
  integration, and commit it as its own `Update README progress to X%` commit.

## Layout / how a function is matched

- `src/auto/<name>.c`: reconstructed C, one file per function (raw m2c style using
  `M2C_FIELD`/`M2C_UNK` is accepted here).
- `config/usa/arm9/delinks.txt`: one block per matched file:
  `src/auto/<name>.c:` / `    complete` / `    .text       start:0x... end:0x...`. Only functions
  not already covered by a delink range are candidates.
- `config/usa/compilers.txt`: per-file override `<source> <version> [extra flags]`, only when
  a function is not built by the default `2.0/sp1p5`.
- `config/usa/arm9/symbols.txt`: addresses/sizes (`kind:function(arm,size=0x..)`).
- `include/m2c_protos.h`: generated context; restore it (`git checkout -- include/m2c_protos.h`)
  if tooling rewrites it.
- Compiler versions live in the mwccarm folder (`1.2`, `2.0`, `dsi`). About 220 functions
  (mostly `0x0200xxxx`, `0x0201xxxx`, `0x020bxxxx`) need **1.2**, not 2.0; see `docs/compiler.md`.

## Gotchas that waste time

- `clang-format` does not see untracked files: `git add` new `src/auto/*.c` before running
  `pre-commit run --all-files`.
- Always run `ninja dis` first; the diff tools read `build/usa/asm/`.
- Only the full-ROM `verify` is authoritative: it also catches wrong `compilers.txt` entries,
  overlapping delink ranges, and link-order/literal-pool issues.
- `ninja apply` copies compiler-generated names (`@43`, `name$37`) into `symbols.txt` when a
  `complete` file trips the symbol-name check.
- `docs/troubleshooting.md` has the Shift-JIS, anonymous-symbol, and assertion-string
  symptoms; `docs/compiler.md` has the compiler/flag identification findings.
