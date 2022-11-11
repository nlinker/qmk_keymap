#pragma once

#include "quantum.h"
#include "keymap_russian.h"

enum my_layers {
    _COLEMAK,
    _COLEMAK_M,
    _RUSSIAN,
    _NAV,
    _NUM,
    _MOUSE,
    _SYM,
    _PLOVER,
};

#define L_RUS  TG(_RUSSIAN)
#define L_NAV  MO(_NAV)
#define L_NUM  MO(_NUM)
#define L_MOU  MO(_MOUSE)
#define L_SYM  MO(_SYM)
#define L_PLOV MO(_PLOVER)

// Colemak layer modifiers
#define L_LSYM  LT(_SYM, KC_A)
#define L_RSYM  LT(_SYM, KC_O)

// Russian layer modifiers
#define L_LSYM_  LT(_SYM, RU_EF)
#define L_RSYM_  LT(_SYM, RU_ZHE)
