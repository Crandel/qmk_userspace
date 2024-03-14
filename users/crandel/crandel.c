#include "crandel.h"

#ifdef RGBLIGHT_ENABLE
layer_state_t default_layer_state_set_user(layer_state_t state) {
  #ifdef CONSOLE_ENABLE
  uprintf("current state in default_layer_state_set_user %d, biton %d\n", state, biton32(state));
  #endif // CONSOLE_ENABLE
  switch (biton32(state)) {
    case COLMAK_L:
      set_indicators_state(CR_HSV_GREEN, "Colemak");
      break;
    case NUM_L:
      set_indicators_state(CR_HSV_BLUE, "Numbers");
      break;
    case CHARS_L:
      set_indicators_state(CR_HSV_GOLD, "Chars");
      break;
    case MOUSE_L:
      set_indicators_state(CR_HSV_ORANGE, "Mouse");
      break;
    case GAME_L:
      set_indicators_state(CR_HSV_RED, "Games");
      break;
  }
  return state;
};
#endif // RGBLIGHT_ENABLE

__attribute__ ((weak))
void set_lang(bool lng){
  if (lng) {
    tap_code(KC_CAPS);
  } else {
    tap_code16(S(KC_CAPS));
  }
}

__attribute__ ((weak))
void set_indicators_state(uint8_t hue, uint8_t sat, uint8_t val, const char *data){
  #ifdef OLED_ENABLE
  update_oled_layer(data);
  #endif // OLED_ENABLE
  #ifdef RGBLIGHT_ENABLE
  rgblight_sethsv(hue, sat, val);
  #endif // RGBLIGHT_ENABLE
}
