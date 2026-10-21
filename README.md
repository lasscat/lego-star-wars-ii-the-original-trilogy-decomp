# LEGO Star Wars II decompilation (USA)

<!-- bytematch:start -->
[![Code](https://bytematch.dev/liolu/lego-star-wars-ii-the-original-trilogy-decomp.svg?label=Code&measure=matched_code_percent)](https://bytematch.dev/liolu/lego-star-wars-ii-the-original-trilogy-decomp) [![Data](https://bytematch.dev/liolu/lego-star-wars-ii-the-original-trilogy-decomp.svg?label=Data&measure=matched_data_percent)](https://bytematch.dev/liolu/lego-star-wars-ii-the-original-trilogy-decomp) [![Functions](https://bytematch.dev/liolu/lego-star-wars-ii-the-original-trilogy-decomp.svg?label=Functions&measure=matched_functions)](https://bytematch.dev/liolu/lego-star-wars-ii-the-original-trilogy-decomp)
<!-- bytematch:end -->

Nintendo DS, game code `AL7E`. Matching decompilation with Metrowerks mwccarm (compiler version still to be identified: `python tools/probe_compiler.py`).

No game assets in this repository: see `extract/README.md`.

## C++ translation units

The `cpp-infrastructure` branch supports evidenced natural C++ alongside C,
with per-source language selection and the unchanged full-ROM matching gate.
See [the C++ build and source guide](docs/cpp.md) before adding a `.cpp` file.

## Progress

<!-- progress:start -->
`██████░░░░░░░░░░░░░░` **30.67%** of the code matched · data 0.00% · 3507/4764 functions
**C-only source coverage:** 30.18% of code · 3450/4764 functions (assembly-bearing source units excluded)

| Part of the code | Files | Functions | Share of all code |
|---|---|---|---|
| Auto-matched (raw m2c output, to clean up) | 3508 | 3507/3508 | 30.67% |

*Updated 2026-10-21 by `python tools/match.py progress` ([DS Decomp Studio](https://github.com/liolu/ds-decomp-studio)). A function counts only when it compiles to the exact same bytes and the ROM still rebuilds byte for byte.*
<!-- progress:end -->

```shell
python tools/configure.py usa
ninja
python tools/match.py status
```

Created from the rayman-rr template. See `AGENTS.md` for the rules.
