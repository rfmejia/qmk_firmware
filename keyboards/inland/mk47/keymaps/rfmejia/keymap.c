/* Copyright (C) 2023 jonylee@hfd
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

// clang-format off
enum layers {
    _DEF, // Default Colemak layout
    _NUM, // Numbers (including shifted-number symbols)
    _SYM, // Symbols
    _NAV, // Navigation keys
    _TAB, // Modifier+tab keys
    _ADJ  // System and layer-hold keys
};

// Home row mod tap keys (GACS)
#define XT_A LT(_SYM, KC_A)
#define XT_R LALT_T(KC_R)
#define XT_S LCTL_T(KC_S)
#define XT_T LSFT_T(KC_T)
#define XT_N RSFT_T(KC_N)
#define XT_E RCTL_T(KC_E)
#define XT_I LALT_T(KC_I)
#define XT_O LT(_SYM, KC_O)

// Home row mod tap keys for _NUM
#define XT_2 LALT_T(KC_2)
#define XT_3 LCTL_T(KC_3)
#define XT_4 LSFT_T(KC_4)
#define XT_7 RSFT_T(KC_7)
#define XT_8 RCTL_T(KC_8)
#define XT_9 LALT_T(KC_9)

// Home row mods tap keys for _NAV
#define XT_TAB  LGUI_T(KC_TAB)
#define XT_PGDN LSFT_T(KC_PGDN)
#define XT_PGUP LCTL_T(KC_PGUP)
#define XT_END  LALT_T(KC_END)

// GUI-ed numbers (to jump i3 workspaces, etc.)
#define LGUI_1 LGUI(KC_1)
#define LGUI_2 LGUI(KC_2)
#define LGUI_3 LGUI(KC_3)
#define LGUI_4 LGUI(KC_4)
#define LGUI_5 LGUI(KC_5)
#define LGUI_6 LGUI(KC_6)
#define LGUI_7 LGUI(KC_7)
#define LGUI_8 LGUI(KC_8)
#define LGUI_9 LGUI(KC_9)
#define LGUI_0 LGUI(KC_0)

// ALT-ed numbers (to jump tmux/browser tabs, etc.)
#define LALT_1 LALT(KC_1)
#define LALT_2 LALT(KC_2)
#define LALT_3 LALT(KC_3)
#define LALT_4 LALT(KC_4)
#define LALT_5 LALT(KC_5)
#define LALT_6 LALT(KC_6)
#define LALT_7 LALT(KC_7)
#define LALT_8 LALT(KC_8)
#define LALT_9 LALT(KC_9)
#define LALT_0 LALT(KC_0)

// Modifier+tab keys
#define TAB_SFT LSFT(KC_TAB)
#define TAB_CTL LCTL(KC_TAB)
#define TAB_ALT LALT(KC_TAB)
#define TAB_GUI LGUI(KC_TAB)

// Layer tap keys
#define XT_D    LT(_NAV, KC_D)
#define XT_H    LT(_TAB, KC_H)
#define XT_Z    LGUI_T(KC_Z)
#define XT_SLSH RGUI_T(KC_SLSH)
#define XT_SPC  LT(_NUM, KC_SPC)
#define XT_BSPC LT(_NUM, KC_BSPC)
#define XT_ENT  LT(_ADJ, KC_ENT)
#define XT_ESC  LT(_ADJ, KC_ESC)

// Layer switching
#define TO_DEF TO(_DEF)
#define TO_NUM TO(_NUM)
#define TO_SYM TO(_SYM)
#define TO_NAV TO(_NAV)
#define TO_TAB TO(_TAB)

// Custom symbol macros
enum custom_keycodes {
  M_LARR = SAFE_RANGE,
  M_RARR,
  M_BOX,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case M_LARR:
        if (record->event.pressed) {
            SEND_STRING("<-");
        }
        break;
    case M_RARR:
        if (record->event.pressed) {
            SEND_STRING("=>");
        }
        break;
    case M_BOX:
        if (record->event.pressed) {
            SEND_STRING("- [ ] ");
        }
        break;
    }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_DEF] =  LAYOUT(
KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    RGB_TOG, RGB_M_P, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
XT_A,    XT_R,    XT_S,    XT_T,    KC_G,    XXXXXXX, XXXXXXX, KC_M,    XT_N,    XT_E,    XT_I,    XT_O,
XT_Z,    KC_X,    KC_C,    XT_D,    KC_V,    XXXXXXX, XXXXXXX, KC_K,    XT_H,    KC_COMM, KC_DOT,  XT_SLSH,
XXXXXXX, XXXXXXX, XXXXXXX, XT_ENT,  XT_BSPC,     RGB_MOD,      XT_SPC,  XT_ESC,  XXXXXXX, XXXXXXX, XXXXXXX
),

[_NUM] = LAYOUT(
KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   XXXXXXX, XXXXXXX, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
KC_1,    XT_2,    XT_3,    XT_4,    KC_5,    XXXXXXX, XXXXXXX, KC_6,    XT_7,    XT_8,    XT_9,    KC_0,
KC_F11,  KC_F12,  KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX, KC_BRIU, KC_BRID, KC_COMM, KC_DOT,  XXXXXXX,
XXXXXXX, XXXXXXX, XXXXXXX, TO_DEF,  _______,     XXXXXXX,      _______, TO_DEF,  XXXXXXX, XXXXXXX, XXXXXXX
),

[_SYM] = LAYOUT(
KC_LT,   KC_GT,   KC_DQUO, KC_QUOT, M_LARR,  XXXXXXX, XXXXXXX, M_RARR,  KC_MINS, KC_EQL,  KC_LCBR, KC_RCBR,
KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, XXXXXXX, XXXXXXX, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
M_BOX,   XXXXXXX, KC_GRV,  KC_TILD, KC_BSLS, XXXXXXX, XXXXXXX, KC_PIPE, KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC,
XXXXXXX, XXXXXXX, XXXXXXX, TO_DEF,  _______,     XXXXXXX,      _______, TO_DEF,  XXXXXXX, XXXXXXX, XXXXXXX
),

[_NAV] = LAYOUT(
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DOWN, KC_RGHT, XXXXXXX, KC_INS,  KC_DEL,
KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, XT_PGDN, XT_PGUP, XT_END,  XXXXXXX,
KC_LGUI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_UP,   KC_LEFT, XXXXXXX, XXXXXXX, KC_RGUI,
XXXXXXX, XXXXXXX, XXXXXXX, TO_DEF,  _______,     XXXXXXX,      _______, TO_DEF,  XXXXXXX, XXXXXXX, XXXXXXX
),

[_TAB] = LAYOUT(
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
KC_TAB,  TAB_ALT, TAB_CTL, TAB_SFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
TAB_GUI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
XXXXXXX, XXXXXXX, XXXXXXX, TO_DEF,  _______,     XXXXXXX,      _______, TO_DEF,  XXXXXXX, XXXXXXX, XXXXXXX
),

[_ADJ] = LAYOUT(
LALT_1,  LALT_2,  LALT_3,  LALT_4,  LALT_5,  XXXXXXX, XXXXXXX, LALT_6,  LALT_7,  LALT_8,  LALT_9,  LALT_0,
LGUI_1,  LGUI_2,  LGUI_3,  LGUI_4,  LGUI_5,  XXXXXXX, XXXXXXX, LGUI_6,  LGUI_7,  LGUI_8,  LGUI_9,  LGUI_0,
TO_SYM,  XXXXXXX, XXXXXXX, TO_NAV,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO_TAB,  XXXXXXX, XXXXXXX, TO_SYM,
XXXXXXX, XXXXXXX, XXXXXXX, KC_LGUI, TO_NUM,      XXXXXXX,      TO_NUM,  KC_RGUI, XXXXXXX, XXXXXXX, XXXXXXX
)
};
// clang-format on
