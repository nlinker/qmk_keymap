#pragma once

#include "quantum.h"
#include "keymap_russian.h"

enum my_layers {
    _COLEMAK,
    _RUSSIAN,
    _NAV,
    _NUM,
    _MOUSE,
    _SYM,
//    _QWERTY,
//    _PLOVER,
};

#define L_RUS  TG(_RUSSIAN)
#define L_NAV  MO(_NAV)
#define L_NUM  MO(_NUM)
#define L_MOU  MO(_MOUSE)
#define L_SYM  MO(_SYM)

// Colemak layer modifiers
#define L_LSYM  LT(_SYM, KC_A)
#define L_RSYM  LT(_SYM, KC_O)

// Russian layer modifiers
#define LR_LSYM  LT(_SYM, RU_EF)
#define LR_RSYM  LT(_SYM, RU_ZHE)
