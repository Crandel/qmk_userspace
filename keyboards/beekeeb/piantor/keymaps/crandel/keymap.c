// Copyright 2022 beekeeb
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "vial.h"

#include "crandel.c"

#ifdef OLED_ENABLE
#  include <stdio.h>
#  include "crd_oled.c"
#endif

#ifdef LEADER_ENABLE
#  include "crd_leader.c"
#endif

#ifdef TAP_DANCE_ENABLE
#  include "crd_tapdance.c"
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case V_US:
    if (record->event.pressed) {
      set_lang(true);
    }
    break;
  case V_UK:
    if (record->event.pressed) {
      set_lang(false);
    }
    break;
  }
  return true;
}

void keyboard_post_init_user(void) {
  // Call the post init code.
  #ifdef TAP_DANCE_ENABLE
  install_tap_dance_entries();
  #endif
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │GUI├───┐           ┌───┤Alt│
      *           └───┤Bsp├───┐   ┌───┤Ent├───┘
      *               └───┤   │   │   ├───┘
      *                   └───┘   └───┘
      */

  [COLMAK_L] = LAYOUT_split_3x5_3_wrapper(
  //,----------------------.    ,------------------.
     ____COLEMAK_L11____,       ____COLEMAK_L12____,
  //|-------+-------+------|    |------+-------+---|
     ____COLEMAK_L21____,       ____COLEMAK_L22____,
  //|-------+-------+------|    |------+-------+---|
     ____COLEMAK_L31____,       ____COLEMAK_L32____,
  //|-------+-------+------|    |------+-------+---|
                 __THUMB1__,     __THUMB2__
               //`---------'    `----------'
  ),

  [NUM_L] = LAYOUT_split_3x5_3_wrapper(
  //,----------------------.    ,------------------.
     ____NUMBERS_L11____,       ____NUMBERS_L12____,
  //|-------+-------+------|    |------+-------+---|
     ____NUMBERS_L21____,       ____NUMBERS_L22____,
  //|-------+-------+------|    |------+-------+---|
     ____NUMBERS_L31____,       ____NUMBERS_L32____,
  //|-------+-------+------|    |------+-------+---|
                 __THUMB1__,     __THUMB2__
               //`---------'    `----------'
  ),

  [CHARS_L] = LAYOUT_split_3x5_3_wrapper(
  //,----------------------.    ,------------------.
     ____CHARCTS_L11____,       ____CHARCTS_L12____,
  //|-------+-------+------|    |------+-------+---|
     ____CHARCTS_L21____,       ____CHARCTS_L22____,
  //|-------+-------+------|    |------+-------+---|
     ____CHARCTS_L31____,       ____CHARCTS_L32____,
  //|-------+-------+------|    |------+-------+---|
                 __THUMB1__,     __THUMB2__
               //`---------'    `----------'
  ),

  [MOUSE_L] = LAYOUT_split_3x5_3_wrapper(
  //,----------------------.    ,------------------.
     ____MOUSESS_L11____,       ____MOUSESS_L12____,
  //|-------+-------+------|    |------+-------+---|
     ____MOUSESS_L21____,       ____MOUSESS_L22____,
  //|-------+-------+------|    |------+-------+---|
     ____MOUSESS_L31____,       ____MOUSESS_L32____,
  //|-------+-------+------|    |------+-------+---|
                 __THUMB1__,     __THUMB2__
               //`---------'    `----------'
  ),

  [GAME_L] = LAYOUT_split_3x5_3(
  //,-------------------------------------.    ,-------------------------------------------.
        KC_G, KC_Q,   KC_W,   KC_E,   KC_H,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------+-----+-------+-------+-------|    |------+---------+--------+--------+--------|
     KC_LSFT, KC_A,   KC_S,   KC_D,   KC_F,       KC_1,     KC_2,    KC_3,    KC_4,    KC_5,
  //|-------+-----+-------+-------+-------|    |------+---------+--------+--------+--------|
     KC_LCTL, KC_Z,   KC_X,   KC_C,   KC_V,       KC_6,     KC_7,    KC_8,    KC_9,    KC_0,
  //|-------+-----+-------+-------+-------|    |------+---------+--------+--------+--------|
                    KC_ENT, KC_SPC,  TD(0),     KC_ENT,   KC_TAB, KC_BSPC
                   //`--------------------'    `-------------------------'
  ),
};
