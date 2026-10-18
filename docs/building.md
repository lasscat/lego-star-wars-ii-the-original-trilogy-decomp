# Building and contributing on Linux

Install Python, Git and Ninja, then install the Python dependencies in a virtual
environment with `python -m pip install -r tools/requirements.txt`. Supply the
compilers from a lawful local installation. The configured main compiler is
Metrowerks `2.0/sp1p5`; selected existing files also require `1.2/sp2p3`.
Per-file compiler versions and options are in `config/usa/compilers.txt`.

Place your decrypted USA ROM at
`extract/baserom_lego_star_wars_ii_the_original_trilogy_usa.nds`. Verify it before
building:

```sh
python tools/sha1.py extract/baserom_lego_star_wars_ii_the_original_trilogy_usa.nds \
    -c lego_star_wars_ii_the_original_trilogy_usa.sha1
```

The expected SHA1 is `7c1afa070797945ba5a2577c7ddfded5cf2fc443`. Keep ROMs, BIOS
files, compilers, extracted data and build outputs out of commits.

## Configure and verify

Run these commands from the repository root, with the virtual environment active:

```sh
python tools/configure.py usa --compiler /path/to/mwccarm
ninja
python tools/match.py verify
python -m pre_commit run --all-files
```

The default Windows runner on Linux is `./wibo`; use `-w wine` to select Wine.
Missing helper tools are normally downloaded by Ninja. To use already installed
helpers instead, supply explicit paths:

```sh
python tools/configure.py usa --compiler /path/to/mwccarm \
    --dsd /path/to/dsd --objdiff /path/to/objdiff-cli \
    --sjiswrap /path/to/sjiswrap.exe -w /path/to/windows-runner
```

`--no-extract` uses an existing extraction. The main compiler flags stay the same
when selecting local helpers. The full verifier still checks the rebuilt ROM,
complete source sections and ASCII sources.

Without a BIOS, the ROM builder preserves the input's recorded secure-area CRC
only when the secure-area bytes, game code and ARM9 location are unchanged. It
recomputes the header CRC afterward. The final SHA1 check still covers the whole
ROM. Run the packaging checks with:

```sh
python -m unittest discover -s tools/tests -v
```

On a Linux host where native Wibo exits with `SIGSYS`, QEMU user emulation can
run Wibo. For example, a runner script in the repository root can contain:

```sh
#!/bin/sh
exec qemu-i386 "$(dirname -- "$0")/wibo" "$@"
```

Make the script executable and select it with `-w /absolute/path/to/runner`.
This runner works with the normal Shift JIS wrapper, compiler and linker; it
does not change their arguments or skip encoding checks.

## Function contributions

Follow [AGENTS.md](../AGENTS.md). Reconstruct C from the game binary; preserve
argument forwarding, field widths, pointer offsets and volatile accesses. Check
the emitted bytes, including relocated addresses and literal pools. A local
instruction comparison is useful while working, but the acceptance gate is
`python tools/match.py verify` printing `VERIFY PASSED`.

For an exactly reconstructed function, add its source and address range to
`config/usa/arm9/delinks.txt`, recording any compiler override in
`config/usa/compilers.txt`. Run the full verifier after integration. Update
progress with `python tools/match.py progress` only after verification passes.
Keep unresolved drafts outside the contribution, and do not commit when the
verifier fails.
