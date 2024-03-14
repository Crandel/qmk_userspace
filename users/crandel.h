#pragma once

enum layers {
  COLMAK_L = 0,
  NUM_L = 1,
  CHARS_L = 2,
  MOUSE_L = 3,
  GAME_L = 4,
};

enum virtual_keycodes {
    V_US = QK_KB_0,
    V_UK,
};

#define TO_CLM DF(COLMAK_L)
#define TO_NMB DF(NUM_L)
#define TO_CHR DF(CHARS_L)
#define TO_MOS DF(MOUSE_L)
#define TO_GAM DF(GAME_L)
#define SLS_TD TD(3)

#define __THUMB1__          QK_LEAD, KC_SPC,   TD(0)
#define __THUMB2__           KC_ENT, KC_TAB, KC_BSPC
#define ____COLEMAK_L11____ LGUI_T(KC_Q), LALT_T(KC_W), LCTL_T(KC_F), LSFT_T(KC_P),            KC_B
#define ____COLEMAK_L12____         KC_E, LSFT_T(KC_I), LCTL_T(KC_U), RALT_T(KC_Y), LGUI_T(KC_SCLN)
#define ____COLEMAK_L21____         KC_A,         KC_R,        KC_S,          KC_T,            KC_G
#define ____COLEMAK_L22____         KC_M,         KC_H,        KC_J,          KC_K,            KC_L
#define ____COLEMAK_L31____         KC_Z,         KC_X,        KC_C,          KC_D,            KC_V
#define ____COLEMAK_L32____         KC_O,         KC_N,     KC_COMM,        KC_DOT,          SLS_TD

#define ____NUMBERS_L11____ LGUI_T(KC_F5),   LALT_T(KC_7),    LCTL_T(KC_4),    LSFT_T(KC_2),        KC_MINS
#define ____NUMBERS_L12____       KC_HOME, LSFT_T(KC_END), LCTL_T(KC_PGDN), RALT_T(KC_PGUP), LGUI_T(KC_DOT)
#define ____NUMBERS_L21____         KC_F4,           KC_8,            KC_5,            KC_1,           KC_3
#define ____NUMBERS_L22____        KC_DOT,        KC_LEFT,         KC_DOWN,           KC_UP,       KC_RIGHT
#define ____NUMBERS_L31____         KC_F3,           KC_9,            KC_6,            KC_0,          KC_F2
#define ____NUMBERS_L32____       KC_BTN4,        KC_BTN1,         KC_BTN2,         KC_BTN3,        KC_BSLS

#define ____CHARCTS_L11____        KC_F7,    LSFT(KC_7),    LSFT(KC_4),   LSFT(KC_2),         KC_F8
#define ____CHARCTS_L12____       KC_EQL, LSFT(KC_BSLS),        KC_GRV, LSFT(KC_GRV), LSFT(KC_SCLN)
#define ____CHARCTS_L21____      XXXXXXX,    LSFT(KC_8),    LSFT(KC_5),   LSFT(KC_1),    LSFT(KC_3)
#define ____CHARCTS_L22____      KC_LCTL,       KC_LBRC,    LSFT(KC_9),   LSFT(KC_0),       KC_RBRC
#define ____CHARCTS_L31____      XXXXXXX,        KC_CUT,    LSFT(KC_6),       KC_APP,       KC_PSTE
#define ____CHARCTS_L32____ LSFT(KC_EQL), LSFT(KC_LBRC), LSFT(KC_COMM), LSFT(KC_DOT), LSFT(KC_RBRC)

#define ____MOUSESS_L11____ KC_BRID, KC_BRIU,  KC_VOLD, KC_VOLU,   KC_F9
#define ____MOUSESS_L12____  KC_F10,  KC_F11,  KC_WH_D, KC_WH_U, KC_PSCR
#define ____MOUSESS_L21____ XXXXXXX, KC_BTN4,  KC_BTN2, KC_BTN1, KC_BTN3
#define ____MOUSESS_L22____  KC_F12, KC_MS_L,  KC_MS_D, KC_MS_U, KC_MS_R
#define ____MOUSESS_L31____ XXXXXXX,  KC_CUT,  KC_COPY,  KC_APP, KC_PSTE
#define ____MOUSESS_L32____  KC_INS, KC_WBAK,  KC_PGDN, KC_PGUP, KC_WFWD

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)
