#pragma once

#include "moonlander.h"
#include "keymap_russian.h"

enum my_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  L_LOCK,
  LAT_WORD,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,
};

#define L_RUS  TG(_RUSSIAN)
#define L_NAV  MO(_NAV)
#define L_SYM  MO(_SYM)
#define L_NUM  MO(_NUM)
#define L_MOU  MO(_MOUSE)

#define CAPSWD  CAPS_WORD
#define A_ATAB  LGUI(KC_TAB)
#define A_RCTD  MT(MOD_RCTL, KC_DEL)
#define A_LCTD  MT(MOD_LCTL, KC_DEL)

// Colemak layer modifiers
#define L_LSYM  LT(_SYM, KC_A)
#define L_RSYM  LT(_SYM, KC_O)

// Russian layer modifiers
#define LR_LSYM  LT(_SYM, RU_EF)
#define LR_RSYM  LT(_SYM, RU_ZHE)
