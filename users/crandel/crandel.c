#include "crandel.h"

#ifdef RGBLIGHT_ENABLE
__attribute__ ((weak))
void vd_layer_state_set(layer_state_t state) {
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
bool vd_process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case V_US:
    if (record->event.pressed) {
      set_lang(true);
    }
    return false;
  case V_UK:
    if (record->event.pressed) {
      set_lang(false);
    }
    return false;
  case AUTO_MS_TOG:
    if (record->event.pressed) {
      #ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
      set_auto_mouse_enable(!get_auto_mouse_enable());
      #endif
    }
    return false; // Skip all further processing of this key
  case KC_BSPC:
    {
      static uint16_t registered_key = KC_NO;
      if (record->event.pressed) {  // On key press.
        const uint8_t mods = get_mods();
#ifndef NO_ACTION_ONESHOT
        uint8_t shift_mods = (mods | get_oneshot_mods()) & MOD_MASK_SHIFT;
#else
        uint8_t shift_mods = mods & MOD_MASK_SHIFT;
#endif  // NO_ACTION_ONESHOT
        if (shift_mods) {  // At least one shift key is held.
          registered_key = KC_DEL;
          // If one shift is held, clear it from the mods. But if both
          // shifts are held, leave as is to send Shift + Del.
          if (shift_mods != MOD_MASK_SHIFT) {
#ifndef NO_ACTION_ONESHOT
            del_oneshot_mods(MOD_MASK_SHIFT);
#endif  // NO_ACTION_ONESHOT
            unregister_mods(MOD_MASK_SHIFT);
          }
        } else {
          registered_key = KC_BSPC;
        }
        register_code(registered_key);
        set_mods(mods);
      } else {  // On key release.
        unregister_code(registered_key);
      }
    }
    return false;
  }
  return true;
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
