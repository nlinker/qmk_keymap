#pragma once

#include "quantum.h"
#include "keymap_russian.h"

enum my_layers {
    _COLEMAK,
    _RUSSIAN,
    _NAV,
    _FNN,
    _MOUSE,
    _SYM,
};

#define L_RUS  TG(_RUSSIAN)
#define L_NAV  MO(_NAV)
#define L_FNN  MO(_FNN)
#define L_SYM  MO(_SYM)
#define L_PLOV MO(_PLOVER)

// Colemak layer modifiers
//#define L_LSYM  LT(_SYM, KC_TAB)
#define L_LSYM  LT(_SYM, KC_A)
#define L_LALT  MT(MOD_LALT, KC_R)
#define L_LCTL  MT(MOD_LCTL, KC_S)
#define L_LSFT  MT(MOD_LSFT, KC_T)

#define L_RSFT  MT(MOD_RSFT, KC_N)
#define L_RCTL  MT(MOD_RCTL, KC_E)
#define L_RALT  MT(MOD_LALT, KC_I)
#define L_RSYM  LT(_SYM, KC_O)

// Russian layer modifiers
#define L_LSYM_  LT(_SYM, RU_EF)
#define L_LALT_  MT(MOD_LALT, RU_YERU)
#define L_LCTL_  MT(MOD_LCTL, RU_VE)
#define L_LSFT_  MT(MOD_LSFT, RU_A)

#define L_RSFT_  MT(MOD_RSFT, RU_O)
#define L_RCTL_  MT(MOD_RCTL, RU_EL)
#define L_RALT_  MT(MOD_LALT, RU_DE)
#define L_RSYM_  LT(_SYM, RU_ZHE)
