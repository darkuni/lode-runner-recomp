# Lode Runner Recompiled (private)

Static recompilation of **Lode Runner** (Xbox 360 XBLA, Tozai Games / Southend Interactive, 2009;
Title ID 5841085B, default.xex 0.0.1.2 built 2009-02-24, 6,205,440 bytes, SHA-1 `3d0c8354…`) to native
Windows with the [ReXGlue SDK](https://github.com/rexglue/rexglue-sdk) v0.9.0. Same treatment as the
Poker Smash / After Burner Climax / OutRun recomps.

**No game data is included.** Put your own Lode Runner XBLA package (the LIVE file, or the `5841085B`
folder from the console) next to `lode_runner.exe` and run it: the first start builds the `assets` folder.
Other versions of `default.xex` are refused with a message naming the supported one.

## Building
GitHub Actions (`.github/workflows/build-windows.yml`) builds on every push to `main` against the prebuilt
stock SDK from `darkuni/rexglue-sdk-builds`. Run it by hand with `release_tag` set to publish a prerelease.

## Codegen
`lode_runner_manifest.toml` + `lode_runner_overrides.toml` -> `generated/`:
- 8 shared `li r3,1; blr` tails that the next function branches into, plus 1 branch-only thunk
- 79 functions reachable only through data pointers (`tools/scan_pointer_funcs.py`; import stubs excluded)
- 14 functions whose address is built in code (`tools/scan_code_addr_funcs.py`, which now follows every addi from a lis base)

Known latent spot (same as After Burner Climax): one shared engine routine around 0x822F21C0 has
cross-function branches that end in a fatal error if ever taken.

## In-game settings (F1 or Esc)
Display mode (also F11), window size, render resolution, VSync, aspect ratio, texture filtering, audio
buffer, keyboard on/off, per-button key rebinding, quit. F3 = performance overlay. Runs as the full game.
Crash reports: `crash-*.txt` + `.dmp` next to the exe; `lode_runner.map` decodes them.

Not affiliated with or endorsed by Tozai Games, Southend Interactive or Microsoft.
