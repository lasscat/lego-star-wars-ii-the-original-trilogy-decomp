# LEGO Star Wars II decompilation (USA)

<!-- bytematch:start -->
[![Code](https://bytematch.dev/liolu/lego-star-wars-ii-the-original-trilogy-decomp.svg?label=Code&measure=matched_code_percent)](https://bytematch.dev/liolu/lego-star-wars-ii-the-original-trilogy-decomp) [![Data](https://bytematch.dev/liolu/lego-star-wars-ii-the-original-trilogy-decomp.svg?label=Data&measure=matched_data_percent)](https://bytematch.dev/liolu/lego-star-wars-ii-the-original-trilogy-decomp) [![Functions](https://bytematch.dev/liolu/lego-star-wars-ii-the-original-trilogy-decomp.svg?label=Functions&measure=matched_functions)](https://bytematch.dev/liolu/lego-star-wars-ii-the-original-trilogy-decomp)
<!-- bytematch:end -->

Nintendo DS, game code `AL7E`. Matching decompilation with Metrowerks mwccarm (compiler version still to be identified: `python tools/probe_compiler.py`).

No game assets in this repository: see `extract/README.md`.

## Progress

<!-- progress:start -->
`███████░░░░░░░░░░░░░` **33.51%** of the code matched · data 0.00% · 3726/4764 functions
**C-only source coverage:** 22.84% of code · 3019/4764 functions (assembly-bearing source units excluded)

| Part of the code | Files | Functions | Share of all code |
|---|---|---|---|
| Auto-matched (raw m2c output, to clean up) | 3727 | 3726/3727 | 33.51% |

*Updated 2026-10-19 by `python tools/match.py progress` ([DS Decomp Studio](https://github.com/liolu/ds-decomp-studio)). A function counts only when it compiles to the exact same bytes and the ROM still rebuilds byte for byte.*
<!-- progress:end -->

```shell
python tools/configure.py usa
ninja
python tools/match.py status
```

Created from the rayman-rr template. See `AGENTS.md` for the rules.
