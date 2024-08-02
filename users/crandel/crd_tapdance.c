/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
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

#define TAP_TAPPING_TERM 260
void install_tap_dance_entries(void) {
    vial_tap_dance_entry_t td0 = { TO_CLM, // Change layers
                                   TO_CHR,
                                   TO_NMB,
                                   TO_MOS,
                                   TAP_TAPPING_TERM };
    vial_tap_dance_entry_t td1 = { KC_SLSH, // / [ ? ]
                                   KC_LBRC,
                                   LSFT(KC_SLSH),
                                   KC_RBRC,
                                   TAP_TAPPING_TERM };
    dynamic_keymap_set_tap_dance(0, &td0); // the first value corresponds to the TD(i) slot
    dynamic_keymap_set_tap_dance(1, &td1);
#ifdef POINTING_DEVICE_ENABLE
    vial_tap_dance_entry_t td2 = { DPI_RST, // POINTER_DEFAULT_DPI_RESET
                                   DPI_RMOD, // POINTER_DEFAULT_DPI_REVERSE
                                   DPI_MOD, // POINTER_DEFAULT_DPI_FORWARD
                                   DPI_RST, // POINTER_DEFAULT_DPI_RESET
                                   TAP_TAPPING_TERM };
    dynamic_keymap_set_tap_dance(2, &td2);
#endif
}
