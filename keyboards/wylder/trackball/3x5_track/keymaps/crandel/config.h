/*
Copyright 2024 Vitalii Drevenchuk <@Crandel>
SPDX-License-Identifier: GPL-2.0-or-later
*/

#pragma once

// Vial settings
#define VIAL_KEYBOARD_UID {0xF6, 0x24, 0xF4, 0x83, 0xB1, 0x4B, 0xE2, 0xB4}

#define VIAL_UNLOCK_COMBO_ROWS { 0, 2 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 2 }
#define VIAL_TAP_DANCE_ENTRIES 5
#define VIAL_COMBO_ENTRIES     30

// Redefine here
#undef MATRIX_COL_PINS
#define MATRIX_COL_PINS { GP3,  GP4,  GP5,  GP6,  GP7 }
#undef MATRIX_ROW_PINS
#define MATRIX_ROW_PINS { GP11, GP12, GP13, GP14, GP15 }
