#pragma once

enum my_keycodes {
    RGB_SLD = SAFE_RANGE,
    L_LOCK,
    ST_M_0,
    ST_M_1,
    ST_M_2,
    ST_M_3,
    ST_M_4,
};

#define CAPSWD  CAPS_WORD
#define A_ATAB  LGUI(KC_TAB)

#define A_CT_Q  LCTL(KC_Q)
#define A_CT_W  LCTL(KC_W)
#define A_CT_F  LCTL(KC_F)
#define A_CT_P  LCTL(KC_P)
#define A_CT_B  LCTL(KC_B)

#define A_CT_A  LCTL(KC_A)
#define A_CT_R  LCTL(KC_R)
#define A_CT_S  LCTL(KC_S)
#define A_CT_T  LCTL(KC_T)
#define A_CT_G  LCTL(KC_G)

#define A_CT_Z  LCTL(KC_Z)
#define A_CT_X  LCTL(KC_X)
#define A_CT_C  LCTL(KC_C)
#define A_CT_D  LCTL(KC_D)
#define A_CT_V  LCTL(KC_V)

#define A_CT_M  LCTL(KC_M)
#define A_CT_N  LCTL(KC_N)
#define A_CT_E  LCTL(KC_E)
#define A_CT_I  LCTL(KC_I)
#define A_CT_O  LCTL(KC_O)

#define A_CT_Y  LCTL(KC_Y)
#define A_SLSH  LCTL(KC_SLASH)
#define A_RCBR  LCTL(KC_RBRACKET)
#define A_LCBR  LCTL(KC_LBRACKET)

#define A_MT_4  MT(MOD_RSFT, KC_4)
#define A_MT_5  MT(MOD_RCTL, KC_5)
#define A_MT_6  MT(MOD_LALT, KC_6)