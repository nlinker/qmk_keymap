#pragma once

#include "quantum.h"
#include "keymap_russian.h"

enum my_layers {
    _QWERTY,
    _RUSSIAN,
    _NAV_L,
    _NAV_R,
    _FNN,
    _SYM,
    _MOUSE,
};

#define L_RUS  TG(_RUSSIAN)

// Modifier keys on NavL and NavR layers

#define AM_KC_4  MT(MOD_LALT, KC_4)
#define AM_KC_5  MT(MOD_LCTL, KC_5)
#define AM_KC_6  MT(MOD_LSFT, KC_6)

#define AM_LEFT  MT(MOD_RSFT, KC_LEFT)
#define AM_DOWN  MT(MOD_RCTL, KC_DOWN)
#define AM_RIGHT MT(MOD_LALT, KC_RIGHT)

//#define L_LSYM  LT(_SYM, KC_TAB)
#define L_LSYM  LT(_SYM, KC_A)
#define L_LALT  MT(MOD_LALT, KC_S)
#define L_LCTL  MT(MOD_LCTL, KC_D)
#define L_LSFT  MT(MOD_LSFT, KC_F)

#define L_RSFT  MT(MOD_RSFT, KC_J)
#define L_RCTL  MT(MOD_RCTL, KC_K)
#define L_RALT  MT(MOD_LALT, KC_L)
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
