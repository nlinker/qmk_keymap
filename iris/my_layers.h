#pragma once

#include "quantum.h"
#include "keymap_russian.h"

enum my_layers {
    _QWERTY,
    _RUSSIAN,
    _NAV_L,
    _NAV_R,
    _SYM,
    _MOUSE,
    _STENO,
};

#define L_RUS  TG(_RUSSIAN)
#define T_LNAV LT(2,KC_SPACE)
#define T_LSYM LT(4,KC_TAB)
#define T_RSYM LT(4,KC_BSPC)
#define T_RNAV LT(3,KC_ENTER)

//#define L_LSYM  LT(_SYM, KC_TAB)
#define L_LSYM  LT(_SYM, KC_A)
#define L_LALT  MT(MOD_LALT, KC_S)
#define L_LCTL  MT(MOD_LCTL, KC_D)
#define L_LSFT  MT(MOD_LSFT, KC_F)

#define L_RSFT  MT(MOD_RSFT, KC_J)
#define L_RCTL  MT(MOD_RCTL, KC_K)
#define L_RALT  MT(MOD_RALT, KC_L)
#define L_RSYM  LT(_SYM, KC_SCLN)

// Russian layer modifiers
#define L_LSYM_  LT(_SYM, RU_EF)
#define L_LALT_  MT(MOD_LALT, RU_YERU)
#define L_LCTL_  MT(MOD_LCTL, RU_VE)
#define L_LSFT_  MT(MOD_LSFT, RU_A)

#define L_RSFT_  MT(MOD_RSFT, RU_O)
#define L_RCTL_  MT(MOD_RCTL, RU_EL)
#define L_RALT_  MT(MOD_RALT, RU_DE)
#define L_RSYM_  LT(_SYM, RU_ZHE)

// Modifier keys on NavL and NavR layers
#define N_LSYM MO(_SYM)
#define N_LALT MT(MOD_LALT, KC_4)
#define N_LCTL MT(MOD_LCTL, KC_5)
#define N_LSFT MT(MOD_LSFT, KC_6)

// ,,,MO(4),
#define N_RSFT MT(MOD_RSFT, KC_LEFT)
#define N_RCTL MT(MOD_RCTL, KC_DOWN)
#define N_RALT MT(MOD_RALT, KC_RIGHT)
#define N_RSYM LT(_SYM,KC_F11)

// Modifier keys on SymL and SymR layers
#define ZLA_RCBR  TD(DANCE_0)
#define ZLC_LPRN  TD(DANCE_1)
#define ZLS_RPRN  TD(DANCE_2)

#define ZRS_UNDS  TD(DANCE_3)
#define ZRC_DQUO  TD(DANCE_4)
#define ZRA_QUOTE MT(MOD_LALT, KC_QUOTE)
