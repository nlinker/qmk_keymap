#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
#include "keymap_steno.h"

#include "process_key_override.h"
#include "process_combo.h"
#include "my_keycodes.h"
#include "my_layers.h"
#include "features/hotkey_conv.h"
#include "features/layer_lock.h"
#define MOON_LED_LEVEL LED_LEVEL

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  A_LOCK,
  A_ATAB,
};

// to track switch to Mouse and Russian layer
static layer_state_t cur_state = 0;
static bool atab_tapped = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TG(6),                  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_GRAVE,       KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_TRANSPARENT,         KC_TRANSPARENT, KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_MINUS,
    KC_TAB,         KC_A,           L_LALT,         L_LCTL,         L_LSFT,         KC_G,           KC_TRANSPARENT,         KC_TRANSPARENT, KC_H,           L_RSFT,         L_RCTL,         L_RALT,         KC_SCLN,        KC_UNDS,
    A_ATAB,         KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                                   KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       L_RUS,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LEFT_SHIFT,  KC_TRANSPARENT,                                         KC_TRANSPARENT, KC_RIGHT_SHIFT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    LT(2,KC_SPACE), LT(4,KC_ESCAPE),KC_TRANSPARENT,                 KC_TRANSPARENT, LT(4,KC_BSPC),  LT(3,KC_ENTER)
  ),
  [1] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    RU_YO,          RU_SHTI,        RU_TSE,         RU_U,           RU_KA,          RU_IE,          KC_TRANSPARENT,         KC_TRANSPARENT, RU_EN,          RU_GHE,         RU_SHA,         RU_SHCH,        RU_ZE,          RU_HA,
    RU_HARD,        RU_EF,          L_LALT_,        L_LCTL_,        L_LSFT_,        RU_PE,          KC_TRANSPARENT,         KC_TRANSPARENT, RU_ER,          L_RSFT_,        L_RCTL_,       L_RALT_,         RU_ZHE,         RU_E,
    KC_TRANSPARENT, RU_YA,          RU_CHE,         RU_ES,          RU_EM,          RU_I,                                                   RU_TE,          RU_SOFT,        RU_BE,          RU_YU,          RU_DOT,         KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_NO,          KC_NO,          KC_7,           KC_8,           KC_9,           KC_NO,          KC_TRANSPARENT,         KC_TRANSPARENT, KC_F4,          KC_HOME,        KC_UP,          KC_END,         KC_F11,         KC_NO,
    KC_TAB,         KC_NO,          ZLA_4,          ZLC_5,          ZLS_6,          KC_CAPS,        KC_TRANSPARENT,         KC_TRANSPARENT, KC_F5,          KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_NO,          KC_F12,
    KC_TRANSPARENT, KC_0,           KC_1,           KC_2,           KC_3,           CW_TOGG,                                                KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_NO,          KC_NO,          KC_7,           KC_8,           KC_9,           KC_NO,          KC_TRANSPARENT,         KC_TRANSPARENT, KC_F4,          KC_HOME,        KC_UP,          KC_END,         KC_F11,         KC_NO,
    KC_TAB,         KC_NO,          KC_4,           KC_5,           KC_6,           KC_CAPS,        KC_TRANSPARENT,         KC_TRANSPARENT, KC_F5,          ZRS_LEFT,       ZRC_DOWN,       ZRA_RIGHT,      KC_NO,          KC_F12,
    KC_TRANSPARENT, KC_0,           KC_1,           KC_2,           KC_3,           CW_TOGG,                                                KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [4] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TILD,        KC_NO,          KC_AMPR,        KC_ASTR,        KC_PLUS,        KC_NO,          KC_TRANSPARENT,         KC_TRANSPARENT, KC_QUOTE,       KC_DQUO,        KC_LCBR,        KC_RCBR,        KC_EQUAL,       KC_MINUS,
    KC_TAB,         KC_COLN,        KC_DLR,         KC_PERC,        KC_CIRC,        KC_NO,          KC_TRANSPARENT,         KC_TRANSPARENT, KC_LBRC,        KC_RBRC,        KC_LPRN,        KC_RPRN,        KC_COLN,        KC_UNDS,
    KC_TRANSPARENT, KC_TILD,        KC_EXLM,        KC_AT,          KC_HASH,        KC_NO,                                                  KC_BSLS,        KC_PIPE,        KC_LABK,        KC_RABK,        KC_QUES,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [5] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_NO,          KC_NO,          KC_MS_WH_LEFT,  KC_PSCR,        KC_MS_WH_RIGHT, KC_NO,          KC_TRANSPARENT,         KC_TRANSPARENT, KC_NO,          KC_MS_WH_UP,    KC_MS_UP,       KC_MS_WH_DOWN,  KC_NO,          KC_NO,
    KC_NO,          KC_APPLICATION, KC_MS_BTN1,     KC_MS_BTN3,     KC_MS_BTN2,     KC_LEFT_GUI,    KC_TRANSPARENT,         KC_TRANSPARENT, KC_RIGHT_GUI,   KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_NO,          KC_NO,
    KC_NO,          KC_NO,          KC_NO,          KC_SCRL,        KC_NO,          KC_NO,                                                  KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [6] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_NO,          STN_N1,         STN_N2,         STN_N3,         STN_N4,         STN_N5,         KC_TRANSPARENT,         KC_TRANSPARENT, STN_N6,         STN_N7,         STN_N8,         STN_N9,         STN_NA,         STN_NB,
    KC_NO,          STN_S1,         STN_TL,         STN_PL,         STN_HL,         STN_ST1,        KC_TRANSPARENT,         KC_TRANSPARENT, STN_ST3,        STN_FR,         STN_PR,         STN_LR,         STN_TR,         STN_DR,
    KC_TRANSPARENT, STN_S2,         STN_KL,         STN_WL,         STN_RL,         STN_ST2,                                                STN_ST4,        STN_RR,         STN_BR,         STN_GR,         STN_SR,         STN_ZR,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, STN_NC,                                                 STN_NC,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    STN_A,          STN_O,          KC_TRANSPARENT,                 KC_TRANSPARENT, STN_E,          STN_U
  ),
};

const uint16_t PROGMEM combo_cut[] = { LCTL(KC_C), LCTL(KC_V), COMBO_END };
const uint16_t PROGMEM combo0[] = { KC_UP, KC_END, COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_DOWN, KC_RIGHT, COMBO_END};
const uint16_t PROGMEM combo2[] = { RU_GHE, RU_SHA, COMBO_END};
const uint16_t PROGMEM combo3[] = { KC_HOME, KC_UP, COMBO_END};
const uint16_t PROGMEM combo4[] = { MT(MOD_RSFT, RU_O), MT(MOD_RCTL, RU_EL), COMBO_END};
const uint16_t PROGMEM combo5[] = { KC_LEFT, KC_DOWN, COMBO_END};
const uint16_t PROGMEM combo6[] = { MT(MOD_RSFT, KC_LEFT), MT(MOD_RCTL, KC_DOWN), COMBO_END};
const uint16_t PROGMEM combo7[] = { KC_F6, KC_F7, COMBO_END};
const uint16_t PROGMEM combo8[] = { KC_F7, KC_F8, COMBO_END};
const uint16_t PROGMEM combo9[] = { KC_F8, KC_F9, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_cut, LCTL(KC_X)),
    COMBO(combo0, KC_PAGE_UP),
    COMBO(combo1, KC_PGDN),
    COMBO(combo2, KC_INSERT),
    COMBO(combo3, KC_INSERT),
    COMBO(combo4, KC_DELETE),
    COMBO(combo5, KC_DELETE),
    COMBO(combo6, KC_DELETE),
    COMBO(combo7, KC_F1),
    COMBO(combo8, KC_F2),
    COMBO(combo9, KC_F3),
};

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}


const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {0,0,0}, {188,255,255}, {245,218,204}, {64,255,255}, {0,0,0}, {0,0,0}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {188,255,255}, {147,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {188,255,255}, {147,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {188,255,255}, {147,255,255}, {188,255,255}, {147,255,255}, {0,0,0}, {188,255,255}, {188,255,255}, {188,255,255}, {28,127,255}, {0,0,0}, {0,0,0}, {245,218,204}, {245,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {188,255,255}, {188,255,255}, {64,255,255}, {0,0,0}, {0,0,0}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {188,255,255}, {147,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {188,255,255}, {147,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {188,255,255}, {147,255,255}, {188,255,255}, {147,255,255}, {0,0,0}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {245,218,204}, {245,218,204}, {0,0,0}, {0,0,0} },

    [1] = { {0,0,0}, {23,255,255}, {23,255,255}, {64,255,255}, {0,0,0}, {0,0,0}, {23,255,255}, {23,255,255}, {23,255,255}, {0,0,0}, {0,0,0}, {23,255,255}, {147,255,255}, {23,255,255}, {0,0,0}, {0,0,0}, {23,255,255}, {147,255,255}, {23,255,255}, {0,0,0}, {0,0,0}, {23,255,255}, {147,255,255}, {23,255,255}, {147,255,255}, {0,0,0}, {23,255,255}, {23,255,255}, {23,255,255}, {28,127,255}, {0,0,0}, {0,0,0}, {245,218,204}, {245,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {23,255,255}, {23,255,255}, {64,255,255}, {0,0,0}, {0,0,0}, {23,255,255}, {23,255,255}, {23,255,255}, {0,0,0}, {0,0,0}, {23,255,255}, {147,255,255}, {23,255,255}, {0,0,0}, {0,0,0}, {23,255,255}, {147,255,255}, {23,255,255}, {0,0,0}, {0,0,0}, {23,255,255}, {147,255,255}, {23,255,255}, {147,255,255}, {0,0,0}, {23,255,255}, {23,255,255}, {23,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {245,218,204}, {245,218,204}, {0,0,0}, {0,0,0} },

    [2] = { {0,0,0}, {0,0,0}, {245,218,204}, {64,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {73,255,85}, {0,0,0}, {0,0,0}, {73,255,85}, {166,218,166}, {73,255,85}, {0,0,0}, {0,0,0}, {73,255,85}, {166,218,166}, {73,255,85}, {0,0,0}, {0,0,0}, {73,255,85}, {166,218,166}, {73,255,85}, {147,255,255}, {0,0,0}, {0,0,0}, {41,255,255}, {64,255,255}, {28,127,255}, {0,0,0}, {0,0,0}, {245,218,204}, {245,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {64,255,255}, {0,0,0}, {0,0,0}, {41,255,255}, {0,0,0}, {41,255,255}, {0,0,0}, {0,0,0}, {73,255,85}, {64,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {64,255,255}, {64,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {73,255,85}, {64,255,255}, {41,255,255}, {147,255,255}, {0,0,0}, {41,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {245,218,204}, {245,218,204}, {0,0,0}, {0,0,0} },

    [3] = { {0,0,0}, {0,0,0}, {245,218,204}, {64,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {73,255,85}, {0,0,0}, {0,0,0}, {73,255,85}, {73,255,85}, {73,255,85}, {0,0,0}, {0,0,0}, {73,255,85}, {73,255,85}, {73,255,85}, {0,0,0}, {0,0,0}, {73,255,85}, {73,255,85}, {73,255,85}, {147,255,255}, {0,0,0}, {0,0,0}, {41,255,255}, {64,255,255}, {28,127,255}, {0,0,0}, {0,0,0}, {245,218,204}, {245,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {64,255,255}, {0,0,0}, {0,0,0}, {41,255,255}, {0,0,0}, {41,255,255}, {0,0,0}, {0,0,0}, {73,255,85}, {166,218,166}, {41,255,255}, {0,0,0}, {0,0,0}, {64,255,255}, {166,218,166}, {41,255,255}, {0,0,0}, {0,0,0}, {73,255,85}, {166,218,166}, {41,255,255}, {147,255,255}, {0,0,0}, {41,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {245,218,204}, {245,218,204}, {0,0,0}, {0,0,0} },

    [4] = { {0,0,0}, {166,218,166}, {245,218,204}, {64,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {166,218,166}, {166,218,166}, {0,0,0}, {0,0,0}, {166,218,166}, {166,218,166}, {166,218,166}, {0,0,0}, {0,0,0}, {166,218,166}, {166,218,166}, {166,218,166}, {0,0,0}, {0,0,0}, {166,218,166}, {166,218,166}, {166,218,166}, {147,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {28,127,255}, {0,0,0}, {0,0,0}, {245,218,204}, {245,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {166,218,166}, {166,218,166}, {64,255,255}, {0,0,0}, {0,0,0}, {166,218,166}, {166,218,166}, {166,218,166}, {0,0,0}, {0,0,0}, {166,218,166}, {166,218,166}, {166,218,166}, {0,0,0}, {0,0,0}, {166,218,166}, {166,218,166}, {166,218,166}, {0,0,0}, {0,0,0}, {166,218,166}, {166,218,166}, {166,218,166}, {147,255,255}, {0,0,0}, {166,218,166}, {166,218,166}, {166,218,166}, {0,0,0}, {0,0,0}, {0,0,0}, {245,218,204}, {245,218,204}, {0,0,0}, {0,0,0} },

    [5] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {166,218,166}, {0,0,0}, {0,0,0}, {0,0,0}, {245,218,204}, {4,232,184}, {0,0,0}, {0,0,0}, {0,0,0}, {28,127,255}, {4,232,184}, {4,232,184}, {0,0,0}, {0,0,0}, {245,218,204}, {4,232,184}, {0,0,0}, {147,255,255}, {0,0,0}, {0,0,0}, {64,255,255}, {0,0,0}, {28,127,255}, {0,0,0}, {0,0,0}, {245,218,204}, {245,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {23,255,255}, {4,232,184}, {0,0,0}, {0,0,0}, {0,0,0}, {4,232,184}, {4,232,184}, {0,0,0}, {0,0,0}, {0,0,0}, {23,255,255}, {4,232,184}, {0,0,0}, {147,255,255}, {0,0,0}, {0,0,0}, {64,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {245,218,204}, {245,218,204}, {0,0,0}, {0,0,0} },

    [6] = { {0,0,0}, {0,0,0}, {0,0,0}, {64,255,255}, {0,0,0}, {0,0,0}, {166,218,166}, {4,232,184}, {4,232,184}, {0,0,0}, {0,0,0}, {166,218,166}, {4,232,184}, {4,232,184}, {0,0,0}, {0,0,0}, {166,218,166}, {4,232,184}, {4,232,184}, {0,0,0}, {0,0,0}, {166,218,166}, {4,232,184}, {4,232,184}, {147,255,255}, {0,0,0}, {166,218,166}, {4,232,184}, {4,232,184}, {28,127,255}, {0,0,0}, {0,0,0}, {4,232,184}, {4,232,184}, {0,0,0}, {41,255,255}, {0,0,0}, {166,218,166}, {4,232,184}, {4,232,184}, {0,0,0}, {0,0,0}, {166,218,166}, {4,232,184}, {4,232,184}, {0,0,0}, {0,0,0}, {166,218,166}, {4,232,184}, {4,232,184}, {0,0,0}, {0,0,0}, {166,218,166}, {4,232,184}, {4,232,184}, {0,0,0}, {0,0,0}, {166,218,166}, {4,232,184}, {4,232,184}, {147,255,255}, {0,0,0}, {166,218,166}, {4,232,184}, {4,232,184}, {0,0,0}, {0,0,0}, {0,0,0}, {4,232,184}, {4,232,184}, {0,0,0}, {41,255,255} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
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

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (keyboard_config.disable_layer_led) { return false; }
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
  return true;
}

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

  switch (keycode) {

    case RGB_SLD:
        if (rawhid_state.rgb_control) {
            return false;
        }
        if (record->event.pressed) {
            rgblight_mode(1);
        }
        return false;

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

  }
  return true;
}



