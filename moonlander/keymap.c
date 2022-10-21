#include QMK_KEYBOARD_H
#include "version.h"

#include "keymap_russian.h"
#include "keymap_steno.h"
#include "process_key_override.h"
#include "process_combo.h"
#include "features/layer_lock.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define SE_SECT_MAC ALGR(KC_6)
#define MOON_LED_LEVEL LED_LEVEL

enum moon_layers {
  _COLEMAK,
  _RUSSIAN,
  _NAV,
  _NUM,
  _MOUSE,
  _SYM,
  _QWERTY,
  _PLOVER,
};

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  L_LOCK,
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


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK] = LAYOUT_moonlander(
    KC_ESCAPE,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, CAPS_WORD,
    KC_TRANSPARENT, KC_Q,           KC_W,           KC_F,           KC_P,           KC_B,           KC_TRANSPARENT,         KC_TRANSPARENT, KC_J,           KC_L,           KC_U,           KC_Y,           KC_UNDS,        KC_TRANSPARENT,
    KC_TAB,         L_LSYM,         KC_R,           KC_S,           KC_T,           KC_G,           KC_TRANSPARENT,         KC_TRANSPARENT, KC_M,           KC_N,           KC_E,           KC_I,           L_RSYM,         KC_ENTER,
    A_ATAB,         KC_Z,           KC_X,           KC_C,           KC_D,           KC_V,                                                   KC_K,           KC_H,           KC_COMMA,       KC_DOT,         KC_SLASH,       L_LOCK,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LSHIFT,      KC_TRANSPARENT,                                         KC_TRANSPARENT, KC_RSHIFT,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    MO(2),          KC_SPACE,       KC_TRANSPARENT,                 KC_TRANSPARENT, KC_BSPACE,      MO(3)
  ),
  [_RUSSIAN] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_CAPSLOCK,
    RU_YO,          RU_SHTI,        RU_TSE,         RU_U,           RU_KA,          RU_IE,          KC_TRANSPARENT,         KC_TRANSPARENT, RU_EN,          RU_GHE,         RU_SHA,         RU_SHCH,        RU_ZE,          RU_HA,
    KC_TRANSPARENT, LR_LSYM,        RU_YERU,        RU_VE,          RU_A,           RU_PE,          KC_TRANSPARENT,         KC_TRANSPARENT, RU_ER,          RU_O,           RU_EL,          RU_DE,          LR_RSYM,        KC_TRANSPARENT,
    RU_HARD,        RU_YA,          RU_CHE,         RU_ES,          RU_EM,          RU_I,                                                   RU_TE,          RU_SOFT,        RU_BE,          RU_YU,          RU_DOT,         RU_E,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [_NAV] = LAYOUT_moonlander(
    KC_ESCAPE,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TG(6),                  TG(7),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, LCTL(KC_Q),     LCTL(KC_W),     LCTL(KC_F),     LCTL(KC_D),     LCTL(KC_Y),     KC_TRANSPARENT,         KC_TRANSPARENT, LCTL(KC_C),     KC_HOME,        KC_UP,          KC_END,         KC_PGUP,        KC_TRANSPARENT,
    KC_TRANSPARENT, MO(5),          KC_LGUI,        KC_LALT,        KC_LCTRL,       KC_APPLICATION, KC_TRANSPARENT,         KC_TRANSPARENT, LCTL(KC_V),     KC_LEFT,        KC_DOWN,        KC_RIGHT,       MO(5),          KC_TRANSPARENT,
    A_ATAB,         LCTL(KC_Z),     KC_NO,          KC_NO,          KC_LSHIFT,      KC_PSCREEN,                                             KC_DELETE,      KC_INSERT,      LCTL(KC_LBRACKET),LCTL(KC_RBRACKET),KC_PGDOWN,  L_LOCK,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [_NUM] = LAYOUT_moonlander(
    KC_ESCAPE,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          LCTL(KC_C),     KC_TRANSPARENT,         KC_TRANSPARENT, KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_TRANSPARENT,
    KC_TRANSPARENT, MO(5),          KC_F5,          KC_F6,          KC_F7,          LCTL(KC_V),     KC_TRANSPARENT,         KC_TRANSPARENT, KC_1,           KC_RCTRL,       KC_LALT,        KC_RALT,        MO(5),          KC_TRANSPARENT,
    A_ATAB,         KC_F8,          KC_F9,          KC_F10,         KC_F11,         KC_F12,                                                 KC_2,           KC_RSHIFT,      KC_3,           KC_4,           KC_5,           L_LOCK,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [_MOUSE] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_UP,       KC_TRANSPARENT, KC_MS_WH_UP,    KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN2,     KC_MS_BTN3,     KC_MS_BTN1,     KC_TRANSPARENT, KC_TRANSPARENT,         KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_MS_WH_DOWN,  KC_TRANSPARENT,
    A_ATAB,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, L_LOCK,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [_SYM] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_CAPSLOCK,
    KC_TRANSPARENT, KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,        KC_TRANSPARENT,         KC_TRANSPARENT, KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_PLUS,        KC_MINUS,       KC_TRANSPARENT,
    KC_TRANSPARENT, KC_DQUO,        KC_TILD,        KC_LCBR,        KC_LPRN,        KC_LBRACKET,    KC_TRANSPARENT,         KC_TRANSPARENT, ST_MACRO_3,     KC_COLN,        KC_SCOLON,      KC_EQUAL,       KC_BSLASH,      KC_ENTER,
    A_ATAB,         KC_QUOTE,       KC_GRAVE,       ST_MACRO_0,     ST_MACRO_1,     ST_MACRO_2,                                             ST_MACRO_4,     KC_PIPE,        KC_LABK,        KC_RABK,        KC_QUES,        L_LOCK,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [_QWERTY] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_TRANSPARENT,         KC_TRANSPARENT, KC_6,           KC_7,           KC_9,           KC_9,           KC_0,           KC_TRANSPARENT,
    KC_TRANSPARENT, KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_TRANSPARENT,         KC_TRANSPARENT, KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_TRANSPARENT,
    KC_TRANSPARENT, KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_TRANSPARENT,         KC_TRANSPARENT, KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_TRANSPARENT,
    KC_LSHIFT,      KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                                   KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_UP,          KC_RSHIFT,
    KC_LCTRL,       KC_TRANSPARENT, KC_LGUI,        KC_LALT,        KC_NO,          KC_TRANSPARENT,                                         KC_TRANSPARENT, KC_RALT,        KC_RCTRL,       KC_LEFT,        KC_DOWN,        KC_RIGHT,
    KC_SPACE,       KC_NO,          KC_TRANSPARENT,                 KC_TRANSPARENT, KC_NO,          KC_ENTER
  ),
  [_PLOVER] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,         KC_TRANSPARENT, STN_FN,         STN_RES1,       STN_RES2,       STN_PWR,        KC_NO,          TO(0),
    KC_TRANSPARENT, STN_N1,         STN_N2,         STN_N3,         STN_N4,         STN_N5,         KC_TRANSPARENT,         KC_TRANSPARENT, STN_N6,         STN_N7,         STN_N8,         STN_N9,         STN_NA,         STN_NB,
    KC_TRANSPARENT, STN_S1,         STN_TL,         STN_PL,         STN_HL,         STN_ST1,        KC_TRANSPARENT,         KC_TRANSPARENT, STN_ST3,        STN_FR,         STN_PR,         STN_LR,         STN_TR,         STN_DR,
    KC_TRANSPARENT, STN_S2,         STN_KL,         STN_WL,         STN_RL,         STN_ST2,                                                STN_ST4,        STN_RR,         STN_BR,         STN_GR,         STN_SR,         STN_ZR,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, STN_A,          STN_O,          KC_TRANSPARENT,                                         KC_TRANSPARENT, STN_E,          STN_U,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    STN_NC,         KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, STN_NC
  ),
};

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = { {245,218,204}, {0,0,0}, {245,218,204}, {64,255,255}, {0,0,0}, {0,0,0}, {188,255,255}, {41,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {188,255,255}, {147,255,255}, {188,255,255}, {147,255,255}, {0,0,0}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {245,218,204}, {0,0,0}, {0,0,0}, {147,255,255}, {0,0,0}, {245,218,204}, {41,255,255}, {0,0,0}, {0,0,0}, {188,255,255}, {41,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {188,255,255}, {147,255,255}, {188,255,255}, {147,255,255}, {0,0,0}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {245,218,204}, {0,0,0}, {0,0,0} },

    [1] = { {245,218,204}, {23,255,255}, {245,218,204}, {23,255,255}, {0,0,0}, {0,0,0}, {23,255,255}, {41,255,255}, {23,255,255}, {0,0,0}, {0,0,0}, {23,255,255}, {23,255,255}, {23,255,255}, {0,0,0}, {0,0,0}, {23,255,255}, {23,255,255}, {23,255,255}, {0,0,0}, {0,0,0}, {23,255,255}, {147,255,255}, {23,255,255}, {147,255,255}, {0,0,0}, {23,255,255}, {23,255,255}, {23,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {245,218,204}, {0,0,0}, {0,0,0}, {147,255,255}, {23,255,255}, {245,218,204}, {23,255,255}, {0,0,0}, {0,0,0}, {23,255,255}, {41,255,255}, {23,255,255}, {0,0,0}, {0,0,0}, {23,255,255}, {23,255,255}, {23,255,255}, {0,0,0}, {0,0,0}, {23,255,255}, {23,255,255}, {23,255,255}, {0,0,0}, {0,0,0}, {23,255,255}, {147,255,255}, {23,255,255}, {147,255,255}, {0,0,0}, {23,255,255}, {23,255,255}, {23,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {245,218,204}, {0,0,0}, {0,0,0} },

    [2] = { {245,218,204}, {0,0,0}, {245,218,204}, {64,255,255}, {0,0,0}, {0,0,0}, {28,127,255}, {41,255,255}, {28,127,255}, {0,0,0}, {0,0,0}, {28,127,255}, {147,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {28,127,255}, {147,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {28,127,255}, {147,255,255}, {147,255,255}, {147,255,255}, {0,0,0}, {28,127,255}, {73,255,85}, {4,232,184}, {41,255,255}, {0,0,0}, {0,0,0}, {41,255,255}, {245,218,204}, {0,0,0}, {0,0,0}, {147,255,255}, {0,0,0}, {4,232,184}, {41,255,255}, {0,0,0}, {0,0,0}, {23,255,255}, {41,255,255}, {23,255,255}, {0,0,0}, {0,0,0}, {73,255,85}, {166,218,166}, {23,255,255}, {0,0,0}, {0,0,0}, {166,218,166}, {166,218,166}, {23,255,255}, {0,0,0}, {0,0,0}, {73,255,85}, {166,218,166}, {28,127,255}, {147,255,255}, {0,0,0}, {4,232,184}, {4,232,184}, {28,127,255}, {41,255,255}, {0,0,0}, {0,0,0}, {41,255,255}, {245,218,204}, {0,0,0}, {0,0,0} },

    [3] = { {245,218,204}, {0,0,0}, {245,218,204}, {64,255,255}, {0,0,0}, {0,0,0}, {64,255,255}, {41,255,255}, {64,255,255}, {0,0,0}, {0,0,0}, {64,255,255}, {64,255,255}, {64,255,255}, {0,0,0}, {0,0,0}, {64,255,255}, {64,255,255}, {64,255,255}, {0,0,0}, {0,0,0}, {64,255,255}, {64,255,255}, {64,255,255}, {147,255,255}, {0,0,0}, {4,232,184}, {4,232,184}, {64,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {245,218,204}, {0,0,0}, {0,0,0}, {147,255,255}, {0,0,0}, {245,218,204}, {41,255,255}, {0,0,0}, {0,0,0}, {166,218,166}, {41,255,255}, {166,218,166}, {0,0,0}, {0,0,0}, {166,218,166}, {147,255,255}, {166,218,166}, {0,0,0}, {0,0,0}, {166,218,166}, {147,255,255}, {166,218,166}, {0,0,0}, {0,0,0}, {166,218,166}, {147,255,255}, {147,255,255}, {147,255,255}, {0,0,0}, {166,218,166}, {166,218,166}, {166,218,166}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {245,218,204}, {0,0,0}, {0,0,0} },

    [4] = { {245,218,204}, {0,0,0}, {245,218,204}, {64,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {23,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {23,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {23,255,255}, {0,0,0}, {147,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {245,218,204}, {0,0,0}, {0,0,0}, {147,255,255}, {0,0,0}, {245,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {4,232,184}, {4,232,184}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {4,232,184}, {0,0,0}, {0,0,0}, {0,0,0}, {4,232,184}, {4,232,184}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {4,232,184}, {0,0,0}, {147,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {245,218,204}, {0,0,0}, {0,0,0} },

    [5] = { {245,218,204}, {0,0,0}, {245,218,204}, {64,255,255}, {0,0,0}, {0,0,0}, {166,218,166}, {166,218,166}, {166,218,166}, {0,0,0}, {0,0,0}, {166,218,166}, {166,218,166}, {166,218,166}, {0,0,0}, {0,0,0}, {166,218,166}, {166,218,166}, {166,218,166}, {0,0,0}, {0,0,0}, {166,218,166}, {166,218,166}, {166,218,166}, {147,255,255}, {0,0,0}, {166,218,166}, {166,218,166}, {166,218,166}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {245,218,204}, {0,0,0}, {0,0,0}, {147,255,255}, {0,0,0}, {245,218,204}, {41,255,255}, {0,0,0}, {0,0,0}, {166,218,166}, {166,218,166}, {166,218,166}, {0,0,0}, {0,0,0}, {166,218,166}, {166,218,166}, {166,218,166}, {0,0,0}, {0,0,0}, {166,218,166}, {166,218,166}, {166,218,166}, {0,0,0}, {0,0,0}, {166,218,166}, {166,218,166}, {166,218,166}, {147,255,255}, {0,0,0}, {166,218,166}, {166,218,166}, {166,218,166}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {245,218,204}, {0,0,0}, {0,0,0} },

    [6] = { {245,218,204}, {0,0,0}, {245,218,204}, {147,255,255}, {147,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {147,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {147,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {0,0,0}, {0,0,0}, {245,218,204}, {0,0,0}, {0,0,0}, {245,218,204}, {147,255,255}, {0,0,0}, {245,218,204}, {147,255,255}, {245,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {245,218,204}, {245,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {245,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {147,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {147,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {245,218,204}, {0,0,0}, {0,0,0}, {245,218,204} },

    [7] = { {4,232,184}, {0,0,0}, {147,255,255}, {147,255,255}, {0,0,0}, {0,0,0}, {188,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {188,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {188,255,255}, {41,255,255}, {41,255,255}, {74,255,255}, {0,0,0}, {188,255,255}, {41,255,255}, {41,255,255}, {74,255,255}, {0,0,0}, {188,255,255}, {0,245,245}, {0,245,245}, {0,0,0}, {0,0,0}, {0,0,0}, {188,255,255}, {245,218,204}, {0,0,0}, {28,127,255}, {245,218,204}, {188,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {188,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {219,255,255}, {188,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {219,255,255}, {188,255,255}, {41,255,255}, {41,255,255}, {74,255,255}, {219,255,255}, {188,255,255}, {41,255,255}, {41,255,255}, {74,255,255}, {219,255,255}, {188,255,255}, {0,245,245}, {0,245,245}, {41,255,255}, {0,0,0}, {0,0,0}, {188,255,255}, {245,218,204}, {0,0,0}, {28,127,255} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
      break;
    case 5:
      set_layer_color(5);
      break;
    case 6:
      set_layer_color(6);
      break;
    case 7:
      set_layer_color(7);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case L_LSYM:
    case L_RSYM:
      return TAPPING_TERM + 50;
    default:
      return TAPPING_TERM;
  }
}

const uint16_t PROGMEM combo_cut[] = { LCTL(KC_C), LCTL(KC_V), COMBO_END };
const uint16_t PROGMEM combo_toggle_ru_1[] = { KC_T, KC_N, COMBO_END };
const uint16_t PROGMEM combo_toggle_ru_2[] = { RU_A, RU_O, COMBO_END };
const uint16_t PROGMEM combo_ts[] = { KC_T, KC_S, COMBO_END };
const uint16_t PROGMEM combo_sr[] = { KC_S, KC_R, COMBO_END };
const uint16_t PROGMEM combo_tsr[] = { KC_T, KC_S, KC_R, COMBO_END };
const uint16_t PROGMEM combo_ne[] = { KC_N, KC_E, COMBO_END };
const uint16_t PROGMEM combo_ei[] = { KC_E, KC_I, COMBO_END };
const uint16_t PROGMEM combo_nei[] = { KC_N, KC_E, KC_I, COMBO_END };
const uint16_t PROGMEM combo_ru_ts[] = { RU_A, RU_VE, COMBO_END };
const uint16_t PROGMEM combo_ru_sr[] = { RU_VE, RU_YERU, COMBO_END };
const uint16_t PROGMEM combo_ru_tsr[] = { RU_A, RU_VE, RU_YERU, COMBO_END };
const uint16_t PROGMEM combo_ru_ne[] = { RU_O, RU_EL, COMBO_END };
const uint16_t PROGMEM combo_ru_ei[] = { RU_EL, RU_DE, COMBO_END };
const uint16_t PROGMEM combo_ru_nei[] = { RU_O, RU_EL, RU_DE, COMBO_END };

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_cut, LCTL(KC_X)),
    COMBO(combo_toggle_ru_1, TG(_RUSSIAN)),
    COMBO(combo_toggle_ru_2, TG(_RUSSIAN)),
    COMBO(combo_ts, KC_LCTL),
    COMBO(combo_sr, KC_LALT),
    COMBO(combo_tsr, LCTL(KC_LALT)),
    COMBO(combo_ne, KC_RCTL),
    COMBO(combo_ei, KC_LALT),
    COMBO(combo_nei, RCTL(KC_LALT)),
    COMBO(combo_ru_ts, KC_LCTL),
    COMBO(combo_ru_sr, KC_LALT),
    COMBO(combo_ru_tsr, LCTL(KC_LALT)),
    COMBO(combo_ru_ne, KC_RCTL),
    COMBO(combo_ru_ei, KC_LALT),
    COMBO(combo_ru_nei, RCTL(KC_LALT)),
};

const key_override_t override_underscore = ko_make_basic(MOD_MASK_SHIFT, KC_UNDERSCORE, KC_MINUS);
const key_override_t override_question = ko_make_basic(MOD_MASK_SHIFT, KC_QUESTION, KC_SLASH);
const key_override_t override_left_angle = ko_make_basic(MOD_MASK_SHIFT, KC_LABK, KC_COMMA);
const key_override_t override_right_angle = ko_make_basic(MOD_MASK_SHIFT, KC_RABK, KC_DOT);
// ko_make_with_layers requires bitmask of layers

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &override_underscore,
    &override_question,
    &override_left_angle,
    &override_right_angle,
    NULL
};

static bool is_shift_pressed = false;
static layer_state_t current_layer_state = 0;

layer_state_t layer_state_set_user(layer_state_t state) {
  current_layer_state = state;
  state = update_tri_layer_state(state, _NAV, _NUM, _MOUSE);
  return state;
}

void switch_system_layout(uint8_t the_layer, bool is_shift_pressed) {
  // Switch to the specific language in the host system,
  // corresponding to the layer passed as the parameter.
  // Now we assume there are only two languages, and the switch shortcut is the CapsLock.
  //
  // Here goes the workaround, since Shift+Caps turns Caps on, not switches the language
  if (is_shift_pressed) {
    unregister_code(KC_LSHIFT);
    tap_code(KC_CAPS);
    register_code(KC_LSHIFT);
  } else {
    tap_code(KC_CAPS);
  }
}

bool process_shortcut_conv(uint16_t keycode, keyrecord_t *record, layer_state_t state, bool is_shift_pressed) {
  // bool is_en_layer = IS_LAYER_ON_STATE(state, _COLEMAK);
  bool is_ru_layer = IS_LAYER_ON_STATE(state, _RUSSIAN);
  bool is_ru_layer_exactly = state == (1 << _RUSSIAN);

  if (is_ru_layer) {
    switch (keycode) {
      case MO(_NAV):
      case MO(_NUM):
      case MO(_MOUSE):
        if (record->event.pressed) {
          switch_system_layout(_COLEMAK, is_shift_pressed);
        } else {
          switch_system_layout(_RUSSIAN, is_shift_pressed);
        }
        break;

      case LR_LSYM:
      case LR_RSYM:
        if (record->tap.count == 0) {
          // the key is being held, this means Sym layer activated
          if (record->event.pressed) {
            switch_system_layout(_COLEMAK, is_shift_pressed);
          } else {
            switch_system_layout(_RUSSIAN, is_shift_pressed);
          }
        }
        break;
    }

    // we translate modifiers for Russian layer only and
    if (is_ru_layer_exactly) {
      uint8_t r = record->event.key.row;
      uint8_t c = record->event.key.col;
      if ((1 <= r && r <= 3 && 1 <= c && c <= 5) ||
          (7 <= r && r <= 9 && 1 <= c && c <= 5) ||
          (r == 3 && c == 0) ||
          (r == 9 && c == 6)) {

        const uint16_t new_kc = keymaps[_COLEMAK][r][c];
        const uint8_t mods = get_mods() | get_oneshot_mods();

        if ((mods & MOD_MASK_CTRL) || (mods & MOD_MASK_ALT) || (mods & MOD_MASK_GUI)) {
          if (record->event.pressed) {
            register_code16(new_kc);
          } else {
            unregister_code16(new_kc);
          }
          return false;
        }
      }
    }
  }
  // continue processing
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_layer_lock(keycode, record, L_LOCK)) {
    return false;
  }
  if (!process_shortcut_conv(keycode, record, current_layer_state, is_shift_pressed)) {
    return false;
  }
  switch (keycode) {
    case KC_LSFT:
    case KC_RSFT:
      is_shift_pressed = record->event.pressed;
      break;

    case L_RUS:
      if (!record->event.pressed) {
        bool is_ru_layer = IS_LAYER_ON_STATE(current_layer_state, _RUSSIAN);
        if (is_ru_layer) {
          switch_system_layout(_COLEMAK, is_shift_pressed);
        } else {
          switch_system_layout(_RUSSIAN, is_shift_pressed);
        }
      }
      break;

    case ST_MACRO_0:
      if (record->event.pressed) {
      SEND_STRING("}" SS_TAP(X_LEFT));

      }
      break;
    case ST_MACRO_1:
      if (record->event.pressed) {
      SEND_STRING(")" SS_TAP(X_LEFT));

      }
      break;
    case ST_MACRO_2:
      if (record->event.pressed) {
      SEND_STRING("]" SS_TAP(X_LEFT));

    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING("::");

    }
    break;
    case ST_MACRO_4:
    if (record->event.pressed) {
      SEND_STRING("::<>" SS_TAP(X_LEFT));

    }
    break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}


void matrix_init_user() {
  steno_set_mode(STENO_MODE_GEMINI);
}
