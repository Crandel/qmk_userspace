/*
Copyright 2024 Vitalii Drevenchuk <@Crandel>

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
  #ifdef RGBLIGHT_ENABLE
  rgblight_sethsv(CR_HSV_GREEN);
  #endif // RGBLIGHT_ENABLE
}


// AUTOMOUSE LAYERS
#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
void pointing_device_init_user(void) {
    set_auto_mouse_enable(true);
}
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │ Q │ W │ F │ P │ B │       │ E │ I │ U │ Y │ ; │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │ A │ R │ S │ T │ G │       │ M │ H │ J │ K │ L │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │ Z │ X │ C │ D │ V │       │ O │ N │ , │ . │ / │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │OSL├───┐           ┌───┤Bsp│
      *               └───┤Spc├───┐   ┌───┤Tab├───┘
      *                   └───┤TD0│   │Ent├───┘
      *                       └───┘   └───┘
      */

  [COLMAK_L] = LAYOUT_wrapper(
  //,--------------------------------.    ,---------------------------.
     AUTO_MS_TOG, ____COLEMAK_L11____,    ____COLEMAK_L12____, KC_BTN2,
  //|-----------+-------------+------|    |------+-------+---+--------|
          PNT_TD, ____COLEMAK_L21____,    ____COLEMAK_L22____, KC_BTN1,
  //|-----------+-------------+------|    |------+-------+---+--------|
         SNP_TOG, ____COLEMAK_L31____,    ____COLEMAK_L32____, KC_BTN3,
  //|-----------+-------------+------|    |------+-------+---+--------|
                          __THUMB1__,     __THUMB2__
                        //`---------'    `----------'
  ),

  [NUM_L] = LAYOUT_wrapper(
  //,-------------------------------.    ,---------------------------.
     XXXXXXX, ____NUMBERS_L11____,       ____NUMBERS_L12____, KC_BTN2,
  //|-------+--------+-------+------|    |------+-------+---+--------|
      PNT_TD, ____NUMBERS_L21____,       ____NUMBERS_L22____, KC_BTN1,
  //|-------+--------+-------+------|    |------+-------+---+--------|
     SNP_TOG, ____NUMBERS_L31____,       ____NUMBERS_L32____, KC_BTN3,
  //|-------+--------+-------+------|    |------+-------+---+--------|
                          __THUMB1__,     __THUMB2__
                        //`---------'    `----------'
  ),

  [CHARS_L] = LAYOUT_wrapper(
  //,-------------------------------.    ,---------------------------.
     XXXXXXX, ____CHARCTS_L11____,       ____CHARCTS_L12____, KC_BTN2,
  //|-------+--------+-------+------|    |------+-------+---+--------|
     XXXXXXX, ____CHARCTS_L21____,       ____CHARCTS_L22____, KC_BTN1,
  //|-------+--------+-------+------|    |------+-------+---+--------|
     XXXXXXX, ____CHARCTS_L31____,       ____CHARCTS_L32____, KC_BTN3,
  //|-------+--------+-------+------|    |------+-------+---+--------|
                          __THUMB1__,     __THUMB2__
                        //`---------'    `----------'
  ),

  [MOUSE_L] = LAYOUT_wrapper(
  //,----------------------------.    ,----------------------------.
     DPI_MOD, ____MOUSESS_L11____,    ____MOUSESS_L12____, DPI_RMOD,
  //|---------------------+------|    |------+-------+---+---------|
     SNIPING, ____MOUSESS_L21____,    ____MOUSESS_L22____,  DRGSCRL,
  //|-------------+-------+------|    |------+-------+---+---------|
     SNP_TOG, ____MOUSESS_L31____,    ____MOUSESS_L32____,  DRG_TOG,
  //|---------------------+------|    |------+-------+---+---------|
                       __THUMB1__,     __THUMB2__
                     //`---------'    `----------'
  ),

  [OSL_L] = LAYOUT_wrapper(
  //,------------------------.    ,------------------------.
     XXXXXXX, ____OSL_L11____,     ____OSL_L12____, XXXXXXX,
  //|-------+---------+------|    |-------+---+------------|
     XXXXXXX, ____OSL_L21____,     ____OSL_L22____, XXXXXXX,
  //|-------+---------+------|    |-------+---+------------|
     XXXXXXX, ____OSL_L31____,     ____OSL_L32____, XXXXXXX,
  //|-------+---------+------|    |-------+---+------------|
                   __THUMB1__,     __THUMB2__
                 //`---------'    `----------'
  ),

  [GAME_L] = LAYOUT(
  //,----------------------------------------------.    ,----------------------------------------------------.
     QK_GESC,    KC_G, KC_Q,   KC_W,   KC_E,   KC_H,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------+--------+-----+-------+-------+-------|    |------+---------+--------+--------+--------+--------|
      KC_TAB, KC_LSFT, KC_A,   KC_S,   KC_D,   KC_F,       KC_1,     KC_2,    KC_3,    KC_4,    KC_5, XXXXXXX,
  //|-------+--------+-----+-------+-------+-------|    |------+---------+--------+--------+--------+--------|
     KC_LALT, KC_LCTL, KC_Z,   KC_X,   KC_C,   KC_V,       KC_6,     KC_7,    KC_8,    KC_9,    KC_0, XXXXXXX,
  //|-------+--------+-----+-------+-------+-------|    |------+---------+--------+--------+--------+--------|
                             KC_ENT, KC_SPC,  TD(0),     KC_ENT,   KC_TAB, KC_BSPC
                            //`--------------------'    `-------------------------'
  ),
};
