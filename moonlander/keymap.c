#include QMK_KEYBOARD_H
#include "version.h"

#include "keymap_steno.h"
#include "process_key_override.h"
#include "process_combo.h"

#include "my_keycodes.h"
#include "my_layers.h"
#include "features/hotkey_conv.h"
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

static layer_state_t cur_state = 0;
static bool atab_tapped = false;


enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,
  DANCE_3,
  DANCE_4,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_ESCAPE,      KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_TRANSPARENT,         KC_TRANSPARENT, KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_TRANSPARENT,
    KC_TAB,         KC_A,           L_LALT,         L_LCTL,         L_LSFT,         KC_G,           KC_TRANSPARENT,         KC_TRANSPARENT, KC_H,           L_RSFT,         L_RCTL,         L_RALT,         KC_SCOLON,      KC_ENTER,
    A_ATAB,         KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                                   KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       L_RUS,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, MO(4),          KC_TRANSPARENT,                                         KC_TRANSPARENT, MO(5),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    MO(2),          MT(MOD_LSFT, KC_SPACE),KC_LSHIFT,               KC_RSHIFT,      MT(MOD_RSFT, KC_BSPACE),MO(3)
  ),
  [1] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    RU_YO,          RU_SHTI,        RU_TSE,         RU_U,           RU_KA,          RU_IE,          KC_TRANSPARENT,         KC_TRANSPARENT, RU_EN,          RU_GHE,         RU_SHA,         RU_SHCH,        RU_ZE,          RU_HA,
    RU_HARD,        RU_EF,          L_LALT_,        L_LCTL_,        L_LSFT_,        RU_PE,          KC_TRANSPARENT,         KC_TRANSPARENT, RU_ER,          L_RSFT_,        L_RCTL_,        L_RALT_,        RU_ZHE,         RU_E,
    KC_TRANSPARENT, RU_YA,          RU_CHE,         RU_ES,          RU_EM,          RU_I,                                                   RU_TE,          RU_SOFT,        RU_BE,          RU_YU,          RU_DOT,         KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_ESCAPE,      A_LOCK,         KC_7,           KC_8,           KC_9,           KC_F1,          KC_TRANSPARENT,         KC_TRANSPARENT, KC_F4,          KC_HOME,        KC_UP,          KC_END,         KC_F2,          KC_F12,
    KC_TAB,         KC_0,           ZLA_4,          ZLC_5,          ZLS_6,          KC_NO,          KC_TRANSPARENT,         KC_TRANSPARENT, KC_F5,          KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_F3,          KC_ENTER,
    KC_TRANSPARENT, KC_NO,          KC_1,           KC_2,           KC_3,           KC_NO,                                                  KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_ESCAPE,      A_LOCK,         KC_7,           KC_8,           KC_9,           KC_F1,          KC_TRANSPARENT,         KC_TRANSPARENT, KC_F4,          KC_HOME,        KC_UP,          KC_END,         KC_F2,          KC_F12,
    KC_TAB,         KC_0,           KC_4,           KC_5,           KC_6,           KC_NO,          KC_TRANSPARENT,         KC_TRANSPARENT, KC_F5,          ZRS_LEFT,       ZRC_DOWN,       ZRA_RIGHT,      KC_F3,          KC_ENTER,
    KC_TRANSPARENT, KC_NO,          KC_1,           KC_2,           KC_3,           KC_NO,                                                  KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [4] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_ESCAPE,      KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,        KC_TRANSPARENT,         KC_TRANSPARENT, KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_PLUS,        KC_MINUS,       KC_APPLICATION,
    KC_TAB,         KC_LCBR,        ZLA_RCBR,       ZLC_LPRN,       ZLS_RPRN,       KC_NO,          KC_TRANSPARENT,         KC_TRANSPARENT, KC_PIPE,        KC_UNDS,        KC_DQUO,        KC_QUOTE,       KC_COLN,        KC_ENTER,
    CAPS_WORD,      KC_TILD,        KC_GRAVE,       KC_LBRACKET,    KC_RBRACKET,    KC_NO,                                                  KC_BSLASH,      KC_EQUAL,       KC_LABK,        KC_RABK,        KC_QUES,        KC_CAPSLOCK,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [5] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_ESCAPE,      KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,        KC_TRANSPARENT,         KC_TRANSPARENT, KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_PLUS,        KC_MINUS,       KC_APPLICATION,
    KC_TAB,         KC_LCBR,        KC_RCBR,        KC_LPRN,        KC_RPRN,        KC_NO,          KC_TRANSPARENT,         KC_TRANSPARENT, KC_PIPE,        ZRS_UNDS,       ZRC_DQUO,       ZRA_QUOTE,      KC_COLN,        KC_ENTER,
    CAPS_WORD,      KC_TILD,        KC_GRAVE,       KC_LBRACKET,    KC_RBRACKET,    KC_NO,                                                  KC_BSLASH,      KC_EQUAL,       KC_LABK,        KC_RABK,        KC_QUES,        KC_CAPSLOCK,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [6] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    DT_UP,          A_LOCK,         KC_MS_BTN3,     KC_PSCREEN,     LALT(KC_PSCREEN),KC_NO,         KC_TRANSPARENT,         KC_TRANSPARENT, KC_NO,          KC_MS_WH_LEFT,  KC_MS_UP,       KC_MS_WH_RIGHT, KC_MS_WH_UP,    KC_NO,
    DT_PRNT,        KC_NO,          KC_APPLICATION, KC_MS_BTN1,     KC_MS_BTN2,     KC_LGUI,        KC_TRANSPARENT,         KC_TRANSPARENT, KC_RGUI,        KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_MS_WH_DOWN,  KC_ENTER,
    DT_DOWN,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                                  KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

const uint16_t PROGMEM combo_cut[] = { LCTL(KC_C), LCTL(KC_V), COMBO_END };
const uint16_t PROGMEM combo0[] = { KC_UP, KC_END, COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_DOWN, KC_RIGHT, COMBO_END};
const uint16_t PROGMEM combo2[] = { KC_UP, KC_END, COMBO_END};
const uint16_t PROGMEM combo3[] = { MT(MOD_RCTL, KC_DOWN), MT(MOD_LALT, KC_RIGHT), COMBO_END};
const uint16_t PROGMEM combo4[] = { KC_HOME, KC_UP, KC_END, COMBO_END};
const uint16_t PROGMEM combo5[] = { KC_HOME, KC_UP, KC_END, COMBO_END};
const uint16_t PROGMEM combo6[] = { KC_LEFT, KC_DOWN, KC_RIGHT, COMBO_END};
const uint16_t PROGMEM combo7[] = { MT(MOD_RSFT, KC_LEFT), MT(MOD_RCTL, KC_DOWN), MT(MOD_LALT, KC_RIGHT), COMBO_END};
const uint16_t PROGMEM combo8[] = { KC_HOME, KC_UP, COMBO_END};
//const uint16_t PROGMEM combo9[] = { KC_HOME, KC_UP, COMBO_END};
const uint16_t PROGMEM combo10[] = { KC_LEFT, KC_DOWN, COMBO_END};
const uint16_t PROGMEM combo11[] = { MT(MOD_RSFT, KC_LEFT), MT(MOD_RCTL, KC_DOWN), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_cut, LCTL(KC_X)),
    COMBO(combo0, KC_PGUP),
    COMBO(combo1, KC_PGDOWN),
    COMBO(combo2, KC_PGUP),
    COMBO(combo3, KC_PGDOWN),
    COMBO(combo4, LCTL(KC_C)),
    COMBO(combo5, LCTL(KC_C)),
    COMBO(combo6, LCTL(KC_V)),
    COMBO(combo7, LCTL(KC_V)),
    COMBO(combo8, KC_INSERT),
//    COMBO(combo9, KC_INSERT),
    COMBO(combo10, KC_DELETE),
    COMBO(combo11, KC_DELETE),
};


extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}


const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = { {0,0,0}, {245,218,204}, {245,218,204}, {64,255,255}, {0,0,0}, {0,0,0}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {188,255,255}, {147,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {188,255,255}, {147,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {188,255,255}, {147,255,255}, {188,255,255}, {41,255,255}, {0,0,0}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {245,218,204}, {147,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {245,218,204}, {64,255,255}, {0,0,0}, {0,0,0}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {188,255,255}, {147,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {188,255,255}, {147,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {188,255,255}, {147,255,255}, {188,255,255}, {41,255,255}, {0,0,0}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {245,218,204}, {147,255,255}, {0,0,0} },

    [1] = { {0,0,0}, {23,255,255}, {23,255,255}, {64,255,255}, {0,0,0}, {0,0,0}, {23,255,255}, {23,255,255}, {23,255,255}, {0,0,0}, {0,0,0}, {23,255,255}, {147,255,255}, {23,255,255}, {0,0,0}, {0,0,0}, {23,255,255}, {147,255,255}, {23,255,255}, {0,0,0}, {0,0,0}, {23,255,255}, {147,255,255}, {23,255,255}, {147,255,255}, {0,0,0}, {23,255,255}, {23,255,255}, {23,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {245,218,204}, {41,255,255}, {0,0,0}, {0,0,0}, {23,255,255}, {23,255,255}, {64,255,255}, {0,0,0}, {0,0,0}, {23,255,255}, {23,255,255}, {23,255,255}, {0,0,0}, {0,0,0}, {23,255,255}, {147,255,255}, {23,255,255}, {0,0,0}, {0,0,0}, {23,255,255}, {147,255,255}, {23,255,255}, {0,0,0}, {0,0,0}, {23,255,255}, {147,255,255}, {23,255,255}, {147,255,255}, {0,0,0}, {23,255,255}, {23,255,255}, {23,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {245,218,204}, {41,255,255}, {0,0,0} },

    [2] = { {0,0,0}, {245,218,204}, {245,218,204}, {64,255,255}, {0,0,0}, {0,0,0}, {4,232,184}, {73,255,85}, {0,0,0}, {0,0,0}, {0,0,0}, {73,255,85}, {166,218,166}, {73,255,85}, {0,0,0}, {0,0,0}, {73,255,85}, {166,218,166}, {73,255,85}, {0,0,0}, {0,0,0}, {73,255,85}, {166,218,166}, {73,255,85}, {147,255,255}, {0,0,0}, {41,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {245,218,204}, {41,255,255}, {0,0,0}, {0,0,0}, {41,255,255}, {245,218,204}, {41,255,255}, {0,0,0}, {0,0,0}, {41,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {73,255,85}, {64,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {64,255,255}, {64,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {73,255,85}, {64,255,255}, {41,255,255}, {147,255,255}, {0,0,0}, {41,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {245,218,204}, {41,255,255}, {0,0,0} },

    [3] = { {0,0,0}, {245,218,204}, {245,218,204}, {64,255,255}, {0,0,0}, {0,0,0}, {245,218,204}, {73,255,85}, {0,0,0}, {0,0,0}, {0,0,0}, {73,255,85}, {73,255,85}, {73,255,85}, {0,0,0}, {0,0,0}, {73,255,85}, {73,255,85}, {73,255,85}, {0,0,0}, {0,0,0}, {73,255,85}, {73,255,85}, {73,255,85}, {147,255,255}, {0,0,0}, {41,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {245,218,204}, {41,255,255}, {0,0,0}, {0,0,0}, {41,255,255}, {245,218,204}, {41,255,255}, {0,0,0}, {0,0,0}, {41,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {73,255,85}, {166,218,166}, {41,255,255}, {0,0,0}, {0,0,0}, {64,255,255}, {166,218,166}, {41,255,255}, {0,0,0}, {0,0,0}, {73,255,85}, {166,218,166}, {41,255,255}, {147,255,255}, {0,0,0}, {41,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {245,218,204}, {41,255,255}, {0,0,0} },

    [4] = { {0,0,0}, {245,218,204}, {245,218,204}, {73,255,85}, {0,0,0}, {0,0,0}, {166,218,166}, {166,218,166}, {166,218,166}, {0,0,0}, {0,0,0}, {166,218,166}, {147,255,255}, {166,218,166}, {0,0,0}, {0,0,0}, {166,218,166}, {147,255,255}, {166,218,166}, {0,0,0}, {0,0,0}, {166,218,166}, {147,255,255}, {166,218,166}, {147,255,255}, {0,0,0}, {166,218,166}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {245,218,204}, {41,255,255}, {0,0,0}, {0,0,0}, {166,218,166}, {245,218,204}, {28,127,255}, {0,0,0}, {0,0,0}, {166,218,166}, {166,218,166}, {166,218,166}, {0,0,0}, {0,0,0}, {166,218,166}, {166,218,166}, {166,218,166}, {0,0,0}, {0,0,0}, {166,218,166}, {166,218,166}, {166,218,166}, {0,0,0}, {0,0,0}, {166,218,166}, {166,218,166}, {166,218,166}, {147,255,255}, {0,0,0}, {166,218,166}, {166,218,166}, {166,218,166}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {245,218,204}, {41,255,255}, {0,0,0} },

    [5] = { {0,0,0}, {245,218,204}, {245,218,204}, {73,255,85}, {0,0,0}, {0,0,0}, {166,218,166}, {166,218,166}, {166,218,166}, {0,0,0}, {0,0,0}, {166,218,166}, {166,218,166}, {166,218,166}, {0,0,0}, {0,0,0}, {166,218,166}, {166,218,166}, {166,218,166}, {0,0,0}, {0,0,0}, {166,218,166}, {166,218,166}, {166,218,166}, {147,255,255}, {0,0,0}, {166,218,166}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {245,218,204}, {41,255,255}, {0,0,0}, {0,0,0}, {166,218,166}, {245,218,204}, {28,127,255}, {0,0,0}, {0,0,0}, {166,218,166}, {166,218,166}, {166,218,166}, {0,0,0}, {0,0,0}, {166,218,166}, {147,255,255}, {166,218,166}, {0,0,0}, {0,0,0}, {166,218,166}, {147,255,255}, {166,218,166}, {0,0,0}, {0,0,0}, {166,218,166}, {147,255,255}, {166,218,166}, {147,255,255}, {0,0,0}, {166,218,166}, {166,218,166}, {166,218,166}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {245,218,204}, {41,255,255}, {0,0,0} },

    [6] = { {0,0,0}, {73,255,85}, {73,255,85}, {73,255,85}, {0,0,0}, {0,0,0}, {4,232,184}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {4,232,184}, {166,218,166}, {0,0,0}, {0,0,0}, {0,0,0}, {4,232,184}, {4,232,184}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {4,232,184}, {0,0,0}, {147,255,255}, {0,0,0}, {0,0,0}, {64,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {245,218,204}, {41,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {245,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {23,255,255}, {23,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {245,218,204}, {4,232,184}, {0,0,0}, {0,0,0}, {0,0,0}, {4,232,184}, {4,232,184}, {0,0,0}, {0,0,0}, {0,0,0}, {245,218,204}, {4,232,184}, {0,0,0}, {147,255,255}, {0,0,0}, {0,0,0}, {64,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {245,218,204}, {41,255,255}, {0,0,0} },

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
  if (rawhid_state.rgb_control) {
      return;
  }
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
      return TAPPING_TERM + 20;
    default:
      return TAPPING_TERM;
  }
}

// ko_make_with_layers requires bitmask of layers
const key_override_t override_underscore = ko_make_basic(MOD_MASK_SHIFT, KC_UNDERSCORE, KC_MINUS);
const key_override_t override_question = ko_make_basic(MOD_MASK_SHIFT, KC_QUESTION, KC_SLASH);
const key_override_t override_left_angle = ko_make_basic(MOD_MASK_SHIFT, KC_LABK, KC_COMMA);
const key_override_t override_right_angle = ko_make_basic(MOD_MASK_SHIFT, KC_RABK, KC_DOT);

const key_override_t **key_overrides = (const key_override_t *[]){
    &override_underscore,
    &override_question,
    &override_left_angle,
    &override_right_angle,
    NULL
};

layer_state_t layer_state_set_user(layer_state_t new_state) {
  new_state = update_tri_layer_state(new_state, _NAV_L, _NAV_R, _MOUSE);
  if (cur_state != new_state) {
    bool is_cur_ru = IS_LAYER_ON_STATE(cur_state, _RUSSIAN);
    bool is_new_ru = IS_LAYER_ON_STATE(new_state, _RUSSIAN);
    if (is_cur_ru && !is_new_ru) {
      // switch system ru -> en
      switch_system_layout(_QWERTY);
    } else if (!is_cur_ru && is_new_ru) {
      // switch system en -> ru
      switch_system_layout(_RUSSIAN);
    }
  }
  cur_state = new_state;
  return new_state;
}

static uint32_t idle_callback(uint32_t trigger_time, void* cb_arg) {
  // case A_TAB:
  if (atab_tapped) {
    atab_tapped = false;
    unregister_code(KC_LGUI);
  }
  return 0;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_layer_lock(keycode, record, A_LOCK)) {
    return false;
  }
  if (!process_hotkey_conversion(keycode, record, cur_state)) {
    return false;
  }

  bool is_ru = IS_LAYER_ON_STATE(cur_state, _RUSSIAN);
  switch (keycode) {
    case A_ATAB:
      if (record->event.pressed) {
        if (!atab_tapped) {
          register_code(KC_LGUI);
        }
        static deferred_token idle_token = INVALID_DEFERRED_TOKEN;
        if (!extend_deferred_exec(idle_token, A_TAB_TIMEOUT)) {
          idle_token = defer_exec(A_TAB_TIMEOUT, idle_callback, NULL);
        }
        atab_tapped = true;
        tap_code(KC_TAB);
      }
      break;

    case ST_MACRO_0:
      if (record->event.pressed) {
        if (is_ru) {
          switch_system_layout(_QWERTY);
          SEND_STRING("::<>" SS_TAP(X_LEFT));
          switch_system_layout(_RUSSIAN);
        } else {
          SEND_STRING("::<>" SS_TAP(X_LEFT));
        }
      }
      break;
    case ST_MACRO_1:
      if (record->event.pressed) {
        if (is_ru) {
          SEND_STRING(SS_LSFT("66"));
        } else {
          SEND_STRING("::");
        }
      }
      break;

    case RGB_SLD:
        if (rawhid_state.rgb_control) {
            return false;
        }
        if (record->event.pressed) {
            rgblight_mode(1);
        }
        return false;
  }
  return true;
}


typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[5];

uint8_t dance_step(qk_tap_dance_state_t *state);

uint8_t dance_step(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_0(qk_tap_dance_state_t *state, void *user_data);
void dance_0_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_0_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_0(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_RCBR);
        tap_code16(KC_RCBR);
        tap_code16(KC_RCBR);
    }
    if(state->count > 3) {
        tap_code16(KC_RCBR);
    }
}

void dance_0_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_RCBR); break;
        case SINGLE_HOLD: register_code16(KC_LALT); break;
        case DOUBLE_TAP: register_code16(KC_RCBR); register_code16(KC_RCBR); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_RCBR); register_code16(KC_RCBR);
    }
}

void dance_0_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_RCBR); break;
        case SINGLE_HOLD: unregister_code16(KC_LALT); break;
        case DOUBLE_TAP: unregister_code16(KC_RCBR); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_RCBR); break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(qk_tap_dance_state_t *state, void *user_data);
void dance_1_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_1_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_1(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LPRN);
        tap_code16(KC_LPRN);
        tap_code16(KC_LPRN);
    }
    if(state->count > 3) {
        tap_code16(KC_LPRN);
    }
}

void dance_1_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(KC_LPRN); break;
        case SINGLE_HOLD: register_code16(KC_LCTRL); break;
        case DOUBLE_TAP: register_code16(KC_LPRN); register_code16(KC_LPRN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LPRN); register_code16(KC_LPRN);
    }
}

void dance_1_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(KC_LPRN); break;
        case SINGLE_HOLD: unregister_code16(KC_LCTRL); break;
        case DOUBLE_TAP: unregister_code16(KC_LPRN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LPRN); break;
    }
    dance_state[1].step = 0;
}
void on_dance_2(qk_tap_dance_state_t *state, void *user_data);
void dance_2_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_2_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_2(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_RPRN);
        tap_code16(KC_RPRN);
        tap_code16(KC_RPRN);
    }
    if(state->count > 3) {
        tap_code16(KC_RPRN);
    }
}

void dance_2_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(KC_RPRN); break;
        case SINGLE_HOLD: register_code16(KC_LSHIFT); break;
        case DOUBLE_TAP: register_code16(KC_RPRN); register_code16(KC_RPRN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_RPRN); register_code16(KC_RPRN);
    }
}

void dance_2_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(KC_RPRN); break;
        case SINGLE_HOLD: unregister_code16(KC_LSHIFT); break;
        case DOUBLE_TAP: unregister_code16(KC_RPRN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_RPRN); break;
    }
    dance_state[2].step = 0;
}
void on_dance_3(qk_tap_dance_state_t *state, void *user_data);
void dance_3_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_3_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_3(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_UNDS);
        tap_code16(KC_UNDS);
        tap_code16(KC_UNDS);
    }
    if(state->count > 3) {
        tap_code16(KC_UNDS);
    }
}

void dance_3_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(KC_UNDS); break;
        case SINGLE_HOLD: register_code16(KC_RSHIFT); break;
        case DOUBLE_TAP: register_code16(KC_UNDS); register_code16(KC_UNDS); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_UNDS); register_code16(KC_UNDS);
    }
}

void dance_3_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(KC_UNDS); break;
        case SINGLE_HOLD: unregister_code16(KC_RSHIFT); break;
        case DOUBLE_TAP: unregister_code16(KC_UNDS); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_UNDS); break;
    }
    dance_state[3].step = 0;
}
void on_dance_4(qk_tap_dance_state_t *state, void *user_data);
void dance_4_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_4_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_4(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_DQUO);
        tap_code16(KC_DQUO);
        tap_code16(KC_DQUO);
    }
    if(state->count > 3) {
        tap_code16(KC_DQUO);
    }
}

void dance_4_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_TAP: register_code16(KC_DQUO); break;
        case SINGLE_HOLD: register_code16(KC_RCTRL); break;
        case DOUBLE_TAP: register_code16(KC_DQUO); register_code16(KC_DQUO); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_DQUO); register_code16(KC_DQUO);
    }
}

void dance_4_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_TAP: unregister_code16(KC_DQUO); break;
        case SINGLE_HOLD: unregister_code16(KC_RCTRL); break;
        case DOUBLE_TAP: unregister_code16(KC_DQUO); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_DQUO); break;
    }
    dance_state[4].step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
        [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
        [DANCE_4] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
};
