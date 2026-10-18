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
5. Never commit the ROM, BIOS, `extract/`, or `build/`. Preserve the uncommitted personal
   `.gitignore` edit. Stage explicit paths; never `git add .` or `git add -u`.

## Build / verify (this machine)

`mwccarm.exe`/`sjiswrap.exe` are PE32 (32-bit Windows) and run through `wibo` (a 32-bit Linux
ELF). This host executes wibo **natively**, which is ~15x faster than `qemu-i386`; the native
and emulated paths emit **byte-identical** objects, so the runner never affects matching.
`tools/configure.py`'s default runner is native `./wibo`, so no override is needed:

```shell
REPO=/home/luke/Documents/lsw2/lsw2-contribution
MWCC=/home/luke/Documents/lsw2/lego-star-wars-ii-the-original-trilogy-decomp/tools/mwccarm
export M2C_PATH=/home/luke/Documents/lsw2/lsw2-first-function/tools/m2c
cd "$REPO"
./venv/bin/python tools/configure.py usa --compiler "$MWCC"   # native ./wibo by default
ninja                 # build ROM
ninja dis             # write build/usa/asm/*.s  (needed by every diff tool)
./venv/bin/python tools/match.py verify
```

- If a host cannot execute 32-bit ELFs, add `-w build/local/wibo-native`: it prefers native
  and falls back to `qemu-i386` (`WIBO_FORCE_QEMU=1` forces emulation). `build/local/wibo-qemu`
  is a backwards-compatible alias. Both are created by `build-contribution.sh` and the
  multi-agent kit; do not commit them (`build/` is gitignored).
- `tools/auto_match.py` invokes `mwccarm.exe` directly; on Linux use the driver
  `build/local/auto_match_run.py`, which prefixes the native runner.
- Pre-commit must pass: `PRE_COMMIT_HOME=build/local/pre-commit-cached ./venv/bin/python -m
  pre_commit run --all-files`.
- Regenerate the README progress with `./venv/bin/python tools/match.py progress` **after every
  integration** (not only at the end), and commit it as its own `Update README progress to X%`
  commit. Forgetting this is a recurring mistake.

## Layout / how a function is matched

- `src/auto/<name>.c` — reconstructed C, one file per function (raw m2c style using
  `M2C_FIELD`/`M2C_UNK` is accepted here).
- `config/usa/arm9/delinks.txt` — one block per matched file:
  `src/auto/<name>.c:` / `    complete` / `    .text       start:0x… end:0x…`. Only functions
  not already covered by a delink range are candidates.
- `config/usa/compilers.txt` — per-file override `<source> <version> [extra flags]`, only when
  a function is not built by the default `2.0/sp1p5`.
- `config/usa/arm9/symbols.txt` — addresses/sizes (`kind:function(arm,size=0x..)`).
- `include/m2c_protos.h` — generated context; **restore it** (`git checkout --
  include/m2c_protos.h`) if tooling rewrites it.
- Compiler versions live in `$MWCC/{1.2,2.0,dsi}`. ~220 functions (mostly `0x0200xxxx`/
  `0x0201xxxx`/`0x020bxxxx`) need **1.2**, not 2.0 — see `docs/compiler.md`.

## Gotchas that waste time

- **`clang-format` does not see untracked files.** `git add` new `src/auto/*.c` *before*
  `pre_commit run --all-files`, or the hook silently skips them and reformats on the next run
  (forcing an amend and a re-verify).
- Always `ninja dis` first; the diff tools read `build/usa/asm/`.
- A resolved-relocation local check (`tools/wip_support.py::resolved_function`) is a good
  pre-filter, but **only the full-ROM `verify` is authoritative** — it also catches wrong
  `compilers.txt` entries, overlapping delink ranges, and link-order/literal-pool issues.
- `ninja apply` copies compiler-generated names (`@43`, `name$37`) into `symbols.txt` when a
  `complete` file trips the symbol-name check.
- `docs/troubleshooting.md` has the Shift-JIS, anonymous-symbol, and assertion-string
  symptoms; `docs/compiler.md` has the compiler/flag identification findings.

## Workflow

```shell
./venv/bin/python tools/match.py status     # progress + worklist
./venv/bin/python tools/match.py verify     # the only source of truth
# integrate: src/auto/<name>.c + delinks.txt block (+ compilers.txt override if needed)
./venv/bin/python tools/match.py progress   # update README table
```
