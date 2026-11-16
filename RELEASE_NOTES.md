Lode Runner (Xbox 360 XBLA, 2009) - native **Windows and Linux (Steam Deck / SteamOS)** builds via ReXGlue static recompilation.

**New in v1.1.0:** Linux build for Steam Deck / SteamOS and desktop Linux (tested on the Deck). The Windows game is unchanged from v1.0.1; only its README text was corrected (controls and credits).

**Game files are not included.** Put your own Lode Runner XBLA package (the LIVE file, or the whole `Content\0000000000000000\5841085B\...` folder copied from your console) next to the game and run it: the first start builds the `assets` folder from it. Other versions of the game are refused with a message naming the supported one (default.xex 0.0.1.2).

**Windows:** `lode_runner-v1.1.0-win-amd64.zip` - unzip, add your package, run `lode_runner.exe`. Needs 64-bit Windows 10/11 and the Microsoft Visual C++ Redistributable 2015-2022 (x64).

**Linux / Steam Deck:** `lode_runner-v1.1.0-linux-amd64.tar.gz` - extract, put your package in the `lode_runner` folder, run `./lode_runner`. On the Deck, add it in Desktop Mode with "Add a Non-Steam Game" and play it from Game Mode. Needs a Vulkan driver (the Deck and current Mesa / NVIDIA drivers have one).

- F1 / Esc: settings (display mode, window size, render resolution, VSync, aspect ratio, texture filtering, audio buffer, keyboard on/off, key rebinding). F11: fullscreen. F3: performance overlay.
- Keyboard: arrow keys move (D-pad and stick); Z = dig left (A), X = dig right (B); A / S = X / Y buttons; C / V = triggers; Q / W = bumpers; Enter = Start; Backspace = Back. All rebindable.
- Controllers work out of the box. Runs as the full game.

Unofficial fan project, not affiliated with or endorsed by Tozai Games, Southend Interactive or Microsoft.
