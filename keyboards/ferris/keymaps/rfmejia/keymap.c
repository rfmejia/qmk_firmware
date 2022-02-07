#include QMK_KEYBOARD_H

enum layers {
    _DEF, // Default Colemak layoup
    _NUM, // Numbers (including shifted-number symbols)
    _SYM, // Symbols
    _NAV, // Navigation keys
    _ADJ  // System and layer-hold keys
};

// Home row mod tap keys (GACS)
#define XT_A LGUI_T(KC_A)
#define XT_R LALT_T(KC_R)
#define XT_S LCTL_T(KC_S)
#define XT_T LSFT_T(KC_T)
#define XT_N RSFT_T(KC_N)
#define XT_E RCTL_T(KC_E)
#define XT_I RALT_T(KC_I)
#define XT_O RGUI_T(KC_O)

// Home row mod tap keys for _NUM
#define XT_1 LGUI_T(KC_1)
#define XT_2 LALT_T(KC_2)
#define XT_3 LCTL_T(KC_3)
#define XT_4 LSFT_T(KC_4)
#define XT_7 RSFT_T(KC_7)
#define XT_8 RCTL_T(KC_8)
#define XT_9 RALT_T(KC_9)
#define XT_0 RGUI_T(KC_0)

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

// Layer tap keys
#define XT_D    LT(_NAV, KC_D)
#define XT_H    LT(_NAV, KC_H)
#define XT_Z    LT(_SYM, KC_Z)
#define XT_SLSH LT(_SYM, KC_SLSH)
#define XT_SPC  LT(_NUM, KC_SPC)
#define XT_BSPC LT(_NUM, KC_BSPC)
#define XT_ENT  LT(_ADJ, KC_ENT)
#define XT_ESC  LT(_ADJ, KC_ESC)

// Layer switching
#define TO_DEF TO(_DEF)
#define TO_NUM TO(_NUM)
#define TO_SYM TO(_SYM)
#define TO_NAV TO(_NAV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_DEF] =  LAYOUT(
KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,        KC_J,    KC_L,    KC_U,    KC_Y,    KC_COLN,
XT_A,    XT_R,    XT_S,    XT_T,    KC_G,        KC_M,    XT_N,    XT_E,    XT_I,    XT_O,
XT_Z,    KC_X,    KC_C,    XT_D,    KC_V,        KC_K,    XT_H,    KC_COMM, KC_DOT,  XT_SLSH,
                           XT_ENT,  XT_BSPC,     XT_SPC,  XT_ESC
),

[_NUM] = LAYOUT(
KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
XT_1,    XT_2,    XT_3,    XT_4,    KC_5,        KC_6,    XT_7,    XT_8,    XT_9,    XT_0,
XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX,     XXXXXXX, KC_BRIU, KC_BRID, XXXXXXX, XXXXXXX,
                           TO_DEF,  _______,     _______, TO_DEF
),

// Since mod tap keys can only use regular keycodes, the home row mods are sandwiched between symbols
[_SYM] = LAYOUT(
KC_LBRC, KC_RBRC, KC_DQUO, KC_QUOT, XXXXXXX,     KC_SCLN, KC_MINS, KC_EQL , KC_LPRN, KC_RPRN,
KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,     XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI,
KC_LT,   KC_GT,   KC_GRV,  KC_TILD, KC_BSLS,     KC_PIPE, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR,
                           TO_DEF,  _______,     _______, TO_DEF
),

[_NAV] = LAYOUT(
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     KC_DOWN, KC_RGHT, XXXXXXX, KC_INS,  KC_DEL,
XT_TAB,  KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,     KC_HOME, XT_PGDN, XT_PGUP, XT_END,  KC_RGUI,
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     KC_UP,   KC_LEFT, XXXXXXX, XXXXXXX, XXXXXXX,
                           TO_DEF,  _______,     _______, TO_DEF
),

[_ADJ] = LAYOUT(
LALT_1,  LALT_2,  LALT_3,  LALT_4,  LALT_5,      LALT_6,  LALT_7,  LALT_8,  LALT_9,  LALT_0,
LGUI_1,  LGUI_2,  LGUI_3,  LGUI_4,  LGUI_5,      LGUI_6,  LGUI_7,  LGUI_8,  LGUI_9,  LGUI_0,
TO_SYM,  XXXXXXX, XXXXXXX, TO_NAV,  XXXXXXX,     XXXXXXX, TO_NAV,  XXXXXXX, XXXXXXX, TO_SYM,
                           XXXXXXX, TO_NUM,      TO_NUM,  XXXXXXX
)
};

/* Combos
+-------+-------+-------+-------+-------+     +-------+-------+-------+-------+-------+
|       |       |       |       |       |     |       |       |       |       |       |
+KC_LBRC+KC_RBRC+KC_DQUO+KC_QUOT+KC_TAB-+     +KC_SCLN+KC_MINS+KC_EQL-+KC_LPRN+KC_RPRN+
|       |       |       |    KC_INS     |     |     KC_DEL    |       |       |       |
+KC_LT--+KC_GT--+KC_GRV-+KC_TILD+KC_BSLS+     +KC_PIPE+KC_UNDS+KC_PLUS+KC_LCBR+KC_RCBR+
|       |     KC_MUT  KC_VOLD KC_VOLU   |     |     KC_BRIU KC_BRID   |       |       |
+-------+-------+-------+-------+-------+     +-------+-------+-------+-------+-------+
                        |       |       |     |       |       |
                        +-------+-------+     +-------+-------+
*/

#ifdef COMBO_ENABLE
enum combos {
  COMBO_LBRC,
  COMBO_RBRC,
  COMBO_QUOT,
  COMBO_DQUO,
  COMBO_TAB,

  COMBO_LT,
  COMBO_GT,
  COMBO_GRV,
  COMBO_TILD,
  COMBO_BSLS,

  COMBO_SCLN,
  COMBO_MINS,
  COMBO_EQL,
  COMBO_LPRN,
  COMBO_RPRN,

  COMBO_PIPE,
  COMBO_UNDS,
  COMBO_PLUS,
  COMBO_LCBR,
  COMBO_RCBR,

  COMBO_INS,
  COMBO_DEL,
  COMBO_MUTE,
  COMBO_VOLD,
  COMBO_VOLU,
  COMBO_BRID,
  COMBO_BRIU,
};

// Left vertical top
const uint16_t PROGMEM combo_qa[] = {KC_Q, XT_A, COMBO_END};
const uint16_t PROGMEM combo_wr[] = {KC_W, XT_R, COMBO_END};
const uint16_t PROGMEM combo_fs[] = {KC_F, XT_S, COMBO_END};
const uint16_t PROGMEM combo_pt[] = {KC_P, XT_T, COMBO_END};
const uint16_t PROGMEM combo_bg[] = {KC_B, KC_G, COMBO_END};

// Left vertical bottom
const uint16_t PROGMEM combo_az[] = {XT_A, XT_Z, COMBO_END};
const uint16_t PROGMEM combo_rx[] = {XT_R, KC_X, COMBO_END};
const uint16_t PROGMEM combo_sc[] = {XT_S, KC_C, COMBO_END};
const uint16_t PROGMEM combo_td[] = {XT_T, XT_D, COMBO_END};
const uint16_t PROGMEM combo_gv[] = {KC_G, KC_V, COMBO_END};

// Right vertical top
const uint16_t PROGMEM combo_jm[] = {KC_J, KC_M, COMBO_END};
const uint16_t PROGMEM combo_ln[] = {KC_L, XT_N, COMBO_END};
const uint16_t PROGMEM combo_ue[] = {KC_U, XT_E, COMBO_END};
const uint16_t PROGMEM combo_yi[] = {KC_Y, XT_I, COMBO_END};
const uint16_t PROGMEM combo_sclno[] = {KC_SCLN, XT_O, COMBO_END};

// Right vertical bottom
const uint16_t PROGMEM combo_nh[] = {XT_N, XT_H, COMBO_END};
const uint16_t PROGMEM combo_ecomm[] = {XT_E, KC_COMM, COMBO_END};
const uint16_t PROGMEM combo_idot[] = {XT_I, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_oslsh[] = {XT_O, XT_SLSH, COMBO_END};
const uint16_t PROGMEM combo_mk[] = {KC_M, KC_K, COMBO_END};

// Left horizontal combos
const uint16_t PROGMEM combo_qw[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_wf[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM combo_fp[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM combo_pb[] = {KC_P, KC_B, COMBO_END};

const uint16_t PROGMEM combo_ar[] = {XT_A, XT_R, COMBO_END};
const uint16_t PROGMEM combo_rs[] = {XT_R, XT_S, COMBO_END};
const uint16_t PROGMEM combo_st[] = {XT_S, XT_T, COMBO_END};
const uint16_t PROGMEM combo_tg[] = {XT_T, KC_G, COMBO_END};

const uint16_t PROGMEM combo_zx[] = {XT_Z, KC_X, COMBO_END};
const uint16_t PROGMEM combo_xc[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM combo_cd[] = {KC_C, XT_D, COMBO_END};
const uint16_t PROGMEM combo_dv[] = {XT_D, KC_V, COMBO_END};

// Right horizontal combos
const uint16_t PROGMEM combo_jl[] = {KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM combo_lu[] = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM combo_uy[] = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM combo_yscln[] = {KC_Y, KC_SCLN, COMBO_END};

const uint16_t PROGMEM combo_mn[] = {KC_M, XT_N, COMBO_END};
const uint16_t PROGMEM combo_ne[] = {XT_N, XT_E, COMBO_END};
const uint16_t PROGMEM combo_ei[] = {XT_E, XT_I, COMBO_END};
const uint16_t PROGMEM combo_io[] = {XT_I, XT_O, COMBO_END};

const uint16_t PROGMEM combo_kh[] = {KC_K, XT_H, COMBO_END};
const uint16_t PROGMEM combo_hcomm[] = {XT_H, KC_COMM, COMBO_END};
const uint16_t PROGMEM combo_commdot[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_dotslsh[] = {KC_DOT, XT_SLSH, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [COMBO_LBRC] = COMBO(combo_qa, KC_LBRC),
    [COMBO_RBRC] = COMBO(combo_wr, KC_RBRC),
    [COMBO_DQUO] = COMBO(combo_fs, KC_DQUO),
    [COMBO_QUOT] = COMBO(combo_pt, KC_QUOT),
    [COMBO_TAB]  = COMBO(combo_bg, KC_TAB),

    [COMBO_LT]   = COMBO(combo_az, KC_LT),
    [COMBO_GT]   = COMBO(combo_rx, KC_GT),
    [COMBO_GRV]  = COMBO(combo_sc, KC_GRV),
    [COMBO_TILD] = COMBO(combo_td, KC_TILD),
    [COMBO_BSLS] = COMBO(combo_gv, KC_BSLS),

    [COMBO_SCLN] = COMBO(combo_jm, KC_SCLN),
    [COMBO_MINS] = COMBO(combo_ln, KC_MINS),
    [COMBO_EQL]  = COMBO(combo_ue, KC_EQL),
    [COMBO_LPRN] = COMBO(combo_yi, KC_LPRN),
    [COMBO_RPRN] = COMBO(combo_sclno, KC_RPRN),

    [COMBO_PIPE] = COMBO(combo_mk, KC_PIPE),
    [COMBO_UNDS] = COMBO(combo_nh, KC_UNDS),
    [COMBO_PLUS] = COMBO(combo_ecomm, KC_PLUS),
    [COMBO_LCBR] = COMBO(combo_idot, KC_LCBR),
    [COMBO_RCBR] = COMBO(combo_oslsh, KC_RCBR),

    [COMBO_INS]  = COMBO(combo_tg, KC_INS),
    [COMBO_DEL]  = COMBO(combo_mn, KC_DEL),
    [COMBO_MUTE] = COMBO(combo_xc, KC_MUTE),
    [COMBO_VOLD] = COMBO(combo_cd, KC_VOLD),
    [COMBO_VOLU] = COMBO(combo_dv, KC_VOLU),
    [COMBO_BRIU] = COMBO(combo_kh, KC_BRIU),
    [COMBO_BRID] = COMBO(combo_hcomm, KC_BRID),
};
#endif
