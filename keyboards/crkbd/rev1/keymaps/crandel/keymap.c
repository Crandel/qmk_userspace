/*
Copyright 2022 beekeeb
Copyright 2023 Vitalii Drevenchuk <@Crandel>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
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

#ifdef RGBLIGHT_ENABLE
layer_state_t default_layer_state_set_user(layer_state_t state) {
  vd_layer_state_set(state);
  return state;
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return vd_process_record_user(keycode, record);
}

void keyboard_post_init_user(void) {
  // Call the post init code.
  #ifdef TAP_DANCE_ENABLE
  install_tap_dance_entries();
  #endif
  #ifdef OLED_ENABLE
  update_oled_layer("Colemak");
  #endif // OLED_ENABLE
  #ifdef RGBLIGHT_ENABLE
  rgblight_sethsv(CR_HSV_GREEN);
  #endif // RGBLIGHT_ENABLE
}

uint16_t keycode_config(uint16_t keycode) {
    return keycode;
}

uint8_t mod_config(uint8_t mod) {
    return mod;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [COLMAK_L] = LAYOUT_wrapper(
  //,----------------------------.    ,---------------------------.
     ____COLEMAK_L11____, XXXXXXX,    XXXXXXX, ____COLEMAK_L12____,
  //|-------+--------+-----------|    |------+-------+---+--------|
     ____COLEMAK_L21____, XXXXXXX,    XXXXXXX, ____COLEMAK_L22____,
  //|-------+--------+-----------|    |------+-------+---+--------|
     ____COLEMAK_L31____, XXXXXXX,    XXXXXXX, ____COLEMAK_L32____,
  //|-------+--------+-----------|    |------+-------+---+--------|
                       __THUMB1__,     __THUMB2__
                     //`---------'    `----------'
  ),

  [NUM_L] = LAYOUT_wrapper(
  //,----------------------------.    ,---------------------------.
     ____NUMBERS_L11____, XXXXXXX,    XXXXXXX, ____NUMBERS_L12____,
  //|-------+--------+-----------|    |------+-------+---+--------|
     ____NUMBERS_L21____, XXXXXXX,    XXXXXXX, ____NUMBERS_L22____,
  //|-------+--------+-----------|    |------+-------+---+--------|
     ____NUMBERS_L31____, XXXXXXX,    XXXXXXX, ____NUMBERS_L32____,
  //|-------+--------+-----------|    |------+-------+---+--------|
                       __THUMB1__,     __THUMB2__
                     //`---------'    `----------'
  ),

  [CHARS_L] = LAYOUT_wrapper(
  //,----------------------------.    ,---------------------------.
     ____CHARCTS_L11____, XXXXXXX,    XXXXXXX, ____CHARCTS_L12____,
  //|-------+--------+-----------|    |------+-------+---+--------|
     ____CHARCTS_L21____, XXXXXXX,    XXXXXXX, ____CHARCTS_L22____,
  //|-------+--------+-----------|    |------+-------+---+--------|
     ____CHARCTS_L31____, XXXXXXX,    XXXXXXX, ____CHARCTS_L32____,
  //|-------+--------+-----------|    |------+-------+---+--------|
                       __THUMB1__,     __THUMB2__
                     //`---------'    `----------'
  ),

  [MOUSE_L] = LAYOUT_wrapper(
  //,----------------------------.    ,---------------------------.
     ____MOUSESS_L11____, XXXXXXX,    XXXXXXX, ____MOUSESS_L12____,
  //|-------+--------+-----------|    |------+-------+---+--------|
     ____MOUSESS_L21____, XXXXXXX,    XXXXXXX, ____MOUSESS_L22____,
  //|-------+--------+-----------|    |------+-------+---+--------|
     ____MOUSESS_L31____, XXXXXXX,    XXXXXXX, ____MOUSESS_L32____,
  //|-------+--------+-----------|    |------+-------+---+--------|
                       __THUMB1__,     __THUMB2__
                     //`---------'    `----------'
  ),

  [OSL_L] = LAYOUT_split_3x6_3_wrapper(
  //,------------------------.    ,------------------------.
     ____OSL_L11____, XXXXXXX,    XXXXXXX, ____OSL_L12____,
  //|-------+---------+------|    |-------+---+------------|
     ____OSL_L21____, XXXXXXX,    XXXXXXX, ____OSL_L22____,
  //|-------+---------+------|    |-------+---+------------|
     ____OSL_L31____, XXXXXXX,    XXXXXXX, ____OSL_L32____,
  //|-------+---------+------|    |-------+---+------------|
                   __THUMB1__,     __THUMB2__
                 //`---------'    `----------'
  ),
};
