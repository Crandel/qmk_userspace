/*
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
#include "3x5_track.h"
#include "crandel.h"
#include QMK_KEYBOARD_H

#include "crandel.c"

#ifdef LEADER_ENABLE
#  include "crd_leader.c"
#endif

#ifdef TAP_DANCE_ENABLE
#  include "crd_tapdance.c"
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return vd_process_record_user(keycode, record);
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
      * │ Q │ W │ F │ P │ B │       │ E │ I │ U │ Y │ ; │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ A │ R │ S │ T │ G │       │ M │ H │ J │ K │ L │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ Z │ X │ C │ D │ V │       │ O │ N │ , │ . │ / │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *             ┌───┬───┐           ┌───┐
      *             │OSL│Spc│           │Ent│
      *             ├───┼───┤           ├───┤
      *             │   │TD0│           │Tab│
      *             └───┼───┤       ┌───┼───┤
      *                 │   │       │   │BSP│
      *                 └───┘       └───┴───┘
      */
  [COLMAK_L] = LAYOUT_3x5_wrapper(
    //--------------------      ,------------------.
      ____COLEMAK_L11____,      ____COLEMAK_L12____,
    //-------+-------+----      |------+-------+---|
      ____COLEMAK_L21____,      ____COLEMAK_L22____,
    //-------+-------+----      |------+-------+---|
      ____COLEMAK_L31____,      ____COLEMAK_L32____,
    //-------+-------+----      |------+-------+---|
              __THUMB11__,      __THUMB21__,
            //-----------|      |----------|
              __THUMB12__,      __THUMB22__,
            //-----------|      |----------|
              __THUMB13__,      __THUMB23__
            //-----------|      |----------|
  ),
  [NUM_L] = LAYOUT_3x5_wrapper(
  //--------------------.    ,------------------.
     ____NUMBERS_L11____,    ____NUMBERS_L12____,
  //--------------------|    |-----+-------+----|
     ____NUMBERS_L21____,    ____NUMBERS_L22____,
  //--------------------|    |-----+-------+----|
     ____NUMBERS_L31____,    ____NUMBERS_L32____,
  //--------------------|    |-----+-------+----|
             __THUMB11__,    __THUMB21__,
           //-----------|    |----------|
             __THUMB12__,    __THUMB22__,
           //-----------|    |----------|
             __THUMB13__,    __THUMB23__
           //-----------|    |----------|

  ),
  [CHARS_L] = LAYOUT_3x5_wrapper(
  //-----------------------.    ,------------------.
        ____CHARCTS_L11____,    ____CHARCTS_L12____,
  //--------+-----+--------|    |------+-------+---|
        ____CHARCTS_L21____,    ____CHARCTS_L22____,
  //--------+-----+--------|    |------+-------+---|
        ____CHARCTS_L31____,    ____CHARCTS_L32____,
  //--------+-----+--------|    |------+-------+---|
                __THUMB11__,    __THUMB21__,
              //-----------|    |----------|
                __THUMB12__,    __THUMB22__,
              //-----------|    |----------|
                __THUMB13__,    __THUMB23__
              //-----------|    |----------|
  ),
  [MOUSE_L] = LAYOUT_3x5_wrapper(
  //,-------------------.    ,------------------.
     ____MOUSESS_L11____,    ____MOUSESS_L12____,
  //|----+-------+------|    |------+-------+---|
     ____MOUSESS_L21____,    ____MOUSESS_L22____,
  //|----+-------+------|    |------+-------+---|
     ____MOUSESS_L31____,    ____MOUSESS_L32____,
  //|----+-------+------|    |------+-------+---|
             __THUMB11__,    __THUMB21__,
           //-----------|    |----------|
             __THUMB12__,    __THUMB22__,
           //-----------|    |----------|
             __THUMB13__,    __THUMB23__
           //-----------|    |----------|
  ),

  [OSL_L] = LAYOUT_3x5_wrapper(
  //,---------------.    ,---------------.
     ____OSL_L11____,     ____OSL_L12____,
  //|--------+------|    |-------+---+---|
     ____OSL_L21____,     ____OSL_L22____,
  //|--------+------|    |-------+---+---|
     ____OSL_L31____,     ____OSL_L32____,
  //|--------+------|    |-------+---+---|
         __THUMB11__,    __THUMB21__,
       //-----------|    |----------|
         __THUMB12__,    __THUMB22__,
       //-----------|    |----------|
         __THUMB13__,    __THUMB23__
       //-----------|    |----------|

  ),
  [GAME_L] = LAYOUT_3x5(
  //,-------------------------------------.    ,-------------------------------------------.
        KC_G, KC_Q,   KC_W,   KC_E,   KC_H,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-------+-----+-------+-------+-------|    |------+---------+--------+--------+--------|
     KC_LSFT, KC_A,   KC_S,   KC_D,   KC_F,       KC_1,     KC_2,    KC_3,    KC_4,    KC_5,
  //|-------+-----+-------+-------+-------|    |------+---------+--------+--------+--------|
     KC_LCTL, KC_Z,   KC_X,   KC_C,   KC_V,       KC_6,     KC_7,    KC_8,    KC_9,    KC_0,
  //|-------+-----+-------+-------+-------|    |------+---------+--------+--------+--------|
                            KC_ENT, KC_SPC,               KC_ENT,
                          //------+-------|    |- -----+--------|
                            KC_TAB,  TD(0),              KC_BSPC,
                          //------+-------|    |-------+--------|
                           KC_LALT, KC_GRV,     XXXXXXX,  KC_TAB
                          // -----+-------|    |-------+--------|
  )
};
