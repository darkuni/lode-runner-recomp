// Lode Runner keyboard layout (used by game_menu.cpp).
// Arrow keys drive both the D-pad and the left stick, so movement and menus
// work whichever the game reads. Buttons keep their controller names -
// rebind them from F1 > Edit keyboard keys.
#pragma once

namespace recomp_ui::game_keys {

struct KeyBind {
  const char* cvar;
  const char* label;
  const char* default_key;
};

inline const KeyBind kKeyBinds[] = {
    {"keybind_dpad_up", "Up (D-pad)", "Up"},
    {"keybind_dpad_down", "Down (D-pad)", "Down"},
    {"keybind_dpad_left", "Left (D-pad)", "Left"},
    {"keybind_dpad_right", "Right (D-pad)", "Right"},
    {"keybind_lstick_up", "Up (stick)", "Up"},
    {"keybind_lstick_down", "Down (stick)", "Down"},
    {"keybind_lstick_left", "Left (stick)", "Left"},
    {"keybind_lstick_right", "Right (stick)", "Right"},
    {"keybind_a", "Dig left (A)", "Z"},
    {"keybind_b", "Dig right (B)", "X"},
    {"keybind_x", "X button", "A"},
    {"keybind_y", "Y button", "S"},
    {"keybind_left_trigger", "Left trigger (LT)", "C"},
    {"keybind_right_trigger", "Right trigger (RT)", "V"},
    {"keybind_left_shoulder", "Left bumper (LB)", "Q"},
    {"keybind_right_shoulder", "Right bumper (RB)", "W"},
    {"keybind_start", "Start / pause", "Return"},
    {"keybind_back", "Back", "Backspace"},
};

// Audio frames to buffer by default.
inline constexpr int kDefaultAudioFrames = 16;

inline const char* const kUnbound[] = {"keybind_lstick_press", "keybind_rstick_press",
                                       "keybind_guide"};

}  // namespace recomp_ui::game_keys
