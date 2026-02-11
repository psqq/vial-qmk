// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum sofle_layers {
    _LAYER_0 = 0,
    _LAYER_1 = 1,
    _LOWER = 2,
    _UPPER = 3,
    _ADJUST = 4,
};

enum custom_keycodes {
    KC_PRVWD = QK_USER,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    // Smart arrows
    KC_STOGGLE, // toggles isKbArrows
    KC_SLEFT,   // Smart left: if isKbArrows then KC_LEFT else MS_LEFT
    KC_SRIGHT,  // same for right
    KC_SUP,     // same for up
    KC_SDOWN,   // same for down
};

bool isKbArrows = true;

#define KC_PDF_0 PDF(_LAYER_0)
#define KC_PDF_1 PDF(_LAYER_1)
#define KC_PDF_L PDF(_LOWER)
#define KC_PDF_U PDF(_UPPER)
#define KC_PDF_A PDF(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_LAYER_0] = LAYOUT(
//--- begin of auto align
  KC_ESC,   KC_1,        KC_2,     KC_3,     KC_4,     KC_5,                              KC_6,        KC_7,           KC_8,           KC_9,           KC_0,      KC_MINS,
  KC_GRV,   KC_Q,        KC_W,     KC_E,     KC_R,     KC_T,                              KC_Y,        KC_U,           KC_I,           KC_O,           KC_P,      KC_LBRC,
  KC_TAB,   KC_A,        KC_S,     KC_D,     KC_F,     KC_G,                              KC_H,        KC_J,           KC_K,           KC_L,           KC_SCLN,   KC_QUOT,
  KC_BSLS,  KC_Z,        KC_X,     KC_C,     KC_V,     KC_B,          KC_MUTE,  KC_MSTP,  KC_N,        KC_M,           KC_COMM,        KC_DOT,         KC_SLSH,   KC_RBRC,
                         KC_LGUI,  KC_LALT,  KC_LCTL,  TL_LOWR,       KC_LSFT,  KC_RSFT,  TL_UPPR,     KC_RCTL,        KC_RALT,        KC_RGUI
//--- end of auto align
),
[_LAYER_1] = LAYOUT(
//--- begin of auto align
  _______,  _______,     _______,  _______,  _______,  _______,                           _______,     _______,        _______,        _______,        _______,   _______,
  _______,  _______,     _______,  _______,  _______,  _______,                           _______,     _______,        _______,        _______,        _______,   _______,
  _______,  _______,     _______,  _______,  _______,  _______,                           _______,     _______,        _______,        _______,        _______,   _______,
  _______,  _______,     _______,  _______,  _______,  _______,       _______,  _______,  _______,     _______,        _______,        _______,        _______,   _______,
                         _______,  _______,  _______,  _______,       _______,  _______,  _______,     _______,        _______,        _______
//--- end of auto align
),
[_LOWER] = LAYOUT(
//--- begin of auto align
  KC_F1,    KC_F2,       KC_F3,    KC_F4,    KC_F5,    KC_F6,                             KC_F7,       KC_F8,          KC_F9,          KC_F10,         KC_F11,    KC_F12,
  KC_PSCR,  _______,     _______,  _______,  _______,  KC_EQL,                            _______,     KC_P7,          KC_P8,          KC_P9,          _______,   KC_SCRL,
  KC_CAPS,  KC_PSLS,     KC_PAST,  KC_PMNS,  KC_PPLS,  KC_PEQL,                           KC_ENT,      KC_P4,          KC_P5,          KC_P6,          KC_P0,     KC_NUM,
  KC_INS,   KC_DEL,      _______,  _______,  _______,  _______,       _______,  _______,  _______,     KC_P1,          KC_P2,          KC_P3,          _______,   KC_PAUSE,
                         _______,  _______,  _______,  _______,       _______,  _______,  _______,     _______,        _______,        _______
//--- end of auto align
),
[_UPPER] = LAYOUT(
//--- begin of auto align
  _______,  _______,     MS_BTN4,  MS_BTN5,  MS_WHLL,  MS_WHLR,                           KC_STOGGLE,  KC_PDF_0,       KC_PDF_L,       KC_PDF_U,       KC_PDF_A,  _______,
  _______,  C(KC_BSPC),  MS_BTN3,  MS_BTN2,  MS_BTN1,  MS_WHLU,                           KC_PGUP,     KC_PRVWD,       KC_SUP,         KC_NXTWD,       KC_HOME,   _______,
  _______,  KC_DEL,      KC_BSPC,  KC_PEQL,  KC_SPC,   MS_WHLD,                           KC_PGDN,     KC_SLEFT,       KC_SDOWN,       KC_SRIGHT,      KC_END,    OSM(MOD_LGUI),
  _______,  C(KC_Z),     C(KC_X),  C(KC_C),  C(KC_V),  LGUI(KC_SPC),  _______,  _______,  KC_ENT,      OSM(MOD_LSFT),  OSM(MOD_LCTL),  OSM(MOD_LALT),  _______,   _______,
                         _______,  _______,  _______,  _______,       _______,  _______,  _______,     _______,        _______,        _______
//--- end of auto align
),
  [_ADJUST] = LAYOUT(
//--- begin of auto align
  _______,  _______,     _______,  _______,  _______,  _______,                           _______,     _______,        _______,        _______,        _______,   _______,
  _______,  _______,     _______,  _______,  _______,  _______,                           _______,     MS_BTN4,        MS_UP,          MS_BTN5,        _______,   _______,
  _______,  _______,     _______,  _______,  _______,  _______,                           _______,     MS_LEFT,        MS_DOWN,        MS_RGHT,        _______,   _______,
  _______,  _______,     _______,  _______,  _______,  _______,       _______,  _______,  _______,     _______,        _______,        _______,        _______,   _______,
                         _______,  _______,  _______,  _______,       _______,  _______,  _______,     _______,        _______,        _______
//--- end of auto align
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_STOGGLE:
            if (!record->event.pressed) {
                isKbArrows = !isKbArrows;
            }
            break;
        case KC_SLEFT:
            if (record->event.pressed) {
                if (isKbArrows) {
                    register_code(KC_LEFT);
                } else {
                    register_code(MS_LEFT);
                }
            } else {
                if (isKbArrows) {
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(MS_LEFT);
                }
            }
            break;
        case KC_SRIGHT:
            if (record->event.pressed) {
                if (isKbArrows) {
                    register_code(KC_RIGHT);
                } else {
                    register_code(MS_RGHT);
                }
            } else {
                if (isKbArrows) {
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(MS_RGHT);
                }
            }
            break;
        case KC_SDOWN:
            if (record->event.pressed) {
                if (isKbArrows) {
                    register_code(KC_DOWN);
                } else {
                    register_code(MS_DOWN);
                }
            } else {
                if (isKbArrows) {
                    unregister_code(KC_DOWN);
                } else {
                    unregister_code(MS_DOWN);
                }
            }
            break;
        case KC_SUP:
            if (record->event.pressed) {
                if (isKbArrows) {
                    register_code(KC_UP);
                } else {
                    register_code(MS_UP);
                }
            } else {
                if (isKbArrows) {
                    unregister_code(KC_UP);
                } else {
                    unregister_code(MS_UP);
                }
            }
            break;
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
    }
    return true;
}
