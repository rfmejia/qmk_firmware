#include QMK_KEYBOARD_H

enum layers {
    _DEF, // Default Colemak layoup
    _SYM, // Symbols (including shifted symbols)
    _NUM, // Numbers (including GUI and Alt-modded numbers)
    _NAV, // Key-based navigation
    _MOU, // Mouse-based navigation
    _ADJ  // System and layer-hold keys
};

// Home row mod tap keys
#define HM_A LSFT_T(KC_A)
#define HM_R LCTL_T(KC_R)
#define HM_S LALT_T(KC_S)
#define HM_T LGUI_T(KC_T)
#define HM_N RGUI_T(KC_N)
#define HM_E RALT_T(KC_E)
#define HM_I RCTL_T(KC_I)
#define HM_O RSFT_T(KC_O)

// Layer tap keys
#define LT_D    LT(_NAV, KC_D)
#define LT_H    LT(_MOU, KC_H)
#define LT_Z    LT(_SYM, KC_Z)
#define LT_SLSH LT(_SYM, KC_SLSH)
#define LT_ENT  LT(_ADJ, KC_ENT)
#define LT_BSPC LT(_NUM, KC_BSPC)
#define LT_SPC  LT(_NUM, KC_SPC)
#define LT_TAB  LT(_ADJ, KC_TAB)

// Home row mods tap keys for _NUM
#define HM_1 LSFT_T(KC_1)
#define HM_2 LCTL_T(KC_2)
#define HM_3 LALT_T(KC_3)
#define HM_4 LGUI_T(KC_4)
#define HM_7 RGUI_T(KC_7)
#define HM_8 RALT_T(KC_8)
#define HM_9 RCTL_T(KC_9)
#define HM_0 RSFT_T(KC_0)

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

// Alt-ed numbers (to jump browser tabs, etc.)
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

// Layer switching
#define TO_DEF TO(_DEF)
#define TO_SYM TO(_SYM)
#define TO_NUM TO(_NUM)
#define TO_NAV TO(_NAV)
#define TO_MOU TO(_MOU)
#define TO_ADJ TO(_ADJ)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_DEF] =  LAYOUT(
KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,        KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
HM_A,    HM_R,    HM_S,    HM_T,    KC_G,        KC_M,    HM_N,    HM_E,    HM_I,    HM_O,
LT_Z,    KC_X,    KC_C,    LT_D,    KC_V,        KC_K,    LT_H,    KC_COMM, KC_DOT,  LT_SLSH,
                           LT_ENT,  LT_BSPC,     LT_SPC,  LT_TAB
),

[_SYM] = LAYOUT(
KC_GRV,  KC_QUOT, KC_COMM, KC_DOT,  KC_SLSH,     KC_BSLS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC,
KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
KC_TILD, KC_DQUO, KC_LT,   KC_GT,   KC_QUES,     KC_PIPE, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR,
                           TO_DEF,  _______,     _______, TO_DEF
),

[_NUM] = LAYOUT(
LGUI_1,  LGUI_2,  LGUI_3,  LGUI_4,  LGUI_5,      LGUI_6,  LGUI_7,  LGUI_8,  LGUI_9, LGUI_0,
KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,   KC_0,
LALT_1,  LALT_2,  LALT_3,  LALT_4,  LALT_5,      LALT_6,  LALT_7,  LALT_8,  LALT_9, LALT_0,
                           TO_DEF,  _______,     KC_TAB, TO_DEF
),

[_NAV] = LAYOUT(
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS,
KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, XXXXXXX,     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_DEL,
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                           TO_DEF,  _______,     _______, TO_DEF
),

[_MOU] = LAYOUT(
KC_WH_U, KC_BTN2, KC_MS_U, KC_BTN1, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                           TO_DEF,  _______,     _______, TO_DEF
),

[_ADJ] = LAYOUT(
KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET,
KC_VOLD, KC_VOLU, KC_MUTE, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, KC_BRID, KC_BRIU,
TO_SYM,  XXXXXXX, XXXXXXX, TO_NAV,  XXXXXXX,     XXXXXXX, TO_MOU,  XXXXXXX, XXXXXXX, TO_SYM,
                           XXXXXXX, TO_NUM,      TO_NUM,  XXXXXXX
)
};

#ifdef COMBO_ENABLE
enum combos {
  COMBO_ESC,
  COMBO_SQUO,
  COMBO_DQUO,

  COMBO_COLN,
  COMBO_MINS,
  COMBO_EQL,

  COMBO_LCBR,
  COMBO_RCBR,
};

const uint16_t PROGMEM combo_squo[] = {KC_W, HM_R, COMBO_END};
const uint16_t PROGMEM combo_dquo[] = {KC_F, HM_S, COMBO_END};
const uint16_t PROGMEM combo_esc[]  = {KC_P, HM_T, COMBO_END};

const uint16_t PROGMEM combo_coln[] = {KC_L, HM_N, COMBO_END};
const uint16_t PROGMEM combo_mins[] = {KC_U, HM_E, COMBO_END};
const uint16_t PROGMEM combo_eql[]  = {KC_Y, HM_I, COMBO_END};

const uint16_t PROGMEM combo_lcbr[] = {KC_B, KC_G, COMBO_END};
const uint16_t PROGMEM combo_rcbr[] = {KC_J, KC_M, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [COMBO_COLN] = COMBO(combo_coln, KC_COLN),
    [COMBO_DQUO] = COMBO(combo_dquo, KC_DQUO),
    [COMBO_EQL]  = COMBO(combo_eql, KC_EQL),
    [COMBO_ESC]  = COMBO(combo_esc, KC_ESC),
    [COMBO_LCBR] = COMBO(combo_lcbr, KC_LCBR),
    [COMBO_MINS] = COMBO(combo_mins, KC_MINS),
    [COMBO_RCBR] = COMBO(combo_rcbr, KC_RCBR),
    [COMBO_SQUO] = COMBO(combo_squo, KC_QUOT),
};
#endif
