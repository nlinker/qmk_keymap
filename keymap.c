#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_br_abnt2.h"
#include "keymap_russian.h"
#include "keymap_us_international.h"
#include "keymap_steno.h"
#include "process_key_override.h"

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

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           TG(1),                                          KC_TRANSPARENT, KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           CAPS_WORD,      
    KC_GRAVE,       KC_Q,           KC_W,           KC_F,           KC_P,           KC_B,           KC_LCBR,                                        KC_LBRACKET,    KC_J,           KC_L,           KC_U,           KC_Y,           KC_UNDS,        KC_COLN,
    KC_TAB,         MT(MOD_LGUI, KC_A),MT(MOD_LALT, KC_R),MT(MOD_LSFT, KC_S),MT(MOD_LCTL, KC_T),KC_G,           KC_RCBR,                                                                        KC_RBRACKET,    KC_M,           MT(MOD_RCTL, KC_N),MT(MOD_RSFT, KC_E),MT(MOD_RALT, KC_I),MT(MOD_RGUI, KC_O),KC_DQUO,        
    KC_TRANSPARENT, KC_Z,           KC_X,           KC_C,           KC_D,           KC_V,                                           KC_K,           KC_H,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_BSLASH,      
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_SPACE,       KC_TAB,                                                                                                         KC_BSPACE,      KC_ENTER,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    MO(3),          MO(2),          KC_APPLICATION,                 KC_TRANSPARENT, MO(2),          MO(4)
  ),
  [1] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, RU_SHTI,        RU_TSE,         RU_U,           RU_KA,          RU_IE,          RU_YO,                                          RU_HA,          RU_EN,          RU_GHE,         RU_SHA,         RU_SHCH,        RU_ZE,          KC_TRANSPARENT, 
    KC_TRANSPARENT, MT(MOD_LGUI, RU_EF),MT(MOD_LALT, RU_YERU),MT(MOD_LSFT, RU_VE),MT(MOD_LCTL, RU_A),RU_PE,          RU_HARD,                                                                        RU_E,           RU_ER,          MT(MOD_RCTL, RU_O),MT(MOD_RSFT, RU_EL),MT(MOD_RALT, RU_DE),MT(MOD_RGUI, RU_ZHE),KC_TRANSPARENT, 
    KC_TRANSPARENT, RU_YA,          RU_CHE,         RU_ES,          RU_EM,          RU_I,                                           RU_TE,          RU_SOFT,        RU_BE,          RU_YU,          RU_DOT,         KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_moonlander(
    TO(0),          KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_NO,                                          KC_NO,          KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_TRANSPARENT, 
    KC_NO,          KC_QUOTE,       KC_LABK,        KC_RABK,        KC_DQUO,        KC_DOT,         KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_AMPR,        KC_TRANSPARENT, KC_LBRACKET,    KC_RBRACKET,    KC_PERC,        KC_TRANSPARENT, 
    KC_NO,          KC_EXLM,        KC_MINUS,       KC_PLUS,        KC_EQUAL,       KC_HASH,        KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_PIPE,        KC_COLN,        KC_LPRN,        KC_RPRN,        KC_QUES,        KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_CIRC,        KC_SLASH,       KC_ASTR,        KC_BSLASH,      KC_TRANSPARENT,                                 KC_TILD,        KC_DLR,         KC_LCBR,        KC_RCBR,        KC_AT,          KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_moonlander(
    TO(0),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,                                          KC_NO,          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_TRANSPARENT,
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_NO,          KC_PGUP,        KC_HOME,        KC_END,         KC_INSERT,      KC_DELETE,      KC_F11,
    KC_TRANSPARENT, OSM(MOD_LGUI),  OSM(MOD_LALT),  OSM(MOD_LSFT),  OSM(MOD_LCTL),  KC_NO,          KC_NO,                                                                          KC_NO,          KC_PGDOWN,      KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_F12,
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,                                          KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [4] = LAYOUT_moonlander(
    TO(0),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_EQUAL,       KC_7,           KC_8,           KC_9,           KC_PLUS,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_ASTR,        KC_4,           KC_5,           KC_6,           KC_MINUS,       KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_NO,          OSM(MOD_RCTL),  OSM(MOD_RCTL),  OSM(MOD_RALT),  OSM(MOD_RGUI),  KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_0,           KC_1,           KC_2,           KC_3,           KC_SLASH,                                       KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN3,     KC_MS_BTN2,     KC_MS_BTN1,     KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_UP,       KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [5] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, QK_STENO_BOLT,                                  QK_STENO_GEMINI,STN_FN,         STN_RES1,       STN_RES2,       STN_PWR,        KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, STN_N1,         STN_N2,         STN_N3,         STN_N4,         STN_N5,         KC_TRANSPARENT,                                 KC_TRANSPARENT, STN_N6,         STN_N7,         STN_N8,         STN_N9,         STN_NA,         STN_NB,         
    KC_TRANSPARENT, STN_S1,         STN_TL,         STN_PL,         STN_HL,         STN_ST1,        KC_TRANSPARENT,                                                                 KC_TRANSPARENT, STN_ST3,        STN_FR,         STN_PR,         STN_LR,         STN_TR,         STN_DR,         
    KC_TRANSPARENT, STN_S2,         STN_KL,         STN_WL,         STN_RL,         STN_ST2,                                        STN_ST4,        STN_RR,         STN_BR,         STN_GR,         STN_SR,         STN_ZR,         
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, STN_NC,         STN_NC,                                                                                                         STN_NC,         STN_NC,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    STN_A,          STN_O,          KC_DELETE,                      KC_BSPACE,      STN_E,          STN_U
  ),
};

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = { {147,255,255}, {64,255,255}, {147,255,255}, {0,0,0}, {0,0,0}, {64,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,0}, {64,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,0}, {64,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,0}, {64,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {245,218,204}, {64,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {41,255,255}, {64,255,255}, {64,255,255}, {41,255,255}, {41,255,255}, {147,255,255}, {147,255,255}, {147,255,255}, {64,255,255}, {64,255,255}, {188,255,255}, {0,0,0}, {64,255,255}, {64,255,255}, {188,255,255}, {188,255,255}, {0,0,0}, {64,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,0}, {64,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,0}, {64,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {245,218,204}, {64,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {41,255,255}, {64,255,255}, {64,255,255}, {41,255,255}, {41,255,255}, {147,255,255}, {147,255,255} },

    [1] = { {147,255,255}, {64,255,255}, {147,255,255}, {0,0,0}, {0,0,0}, {64,255,255}, {245,218,204}, {245,218,204}, {245,218,204}, {0,0,0}, {64,255,255}, {245,218,204}, {245,218,204}, {245,218,204}, {0,0,0}, {64,255,255}, {245,218,204}, {245,218,204}, {245,218,204}, {0,0,0}, {64,255,255}, {245,218,204}, {245,218,204}, {245,218,204}, {4,232,184}, {64,255,255}, {245,218,204}, {245,218,204}, {245,218,204}, {41,255,255}, {245,218,204}, {245,218,204}, {41,255,255}, {41,255,255}, {0,0,0}, {147,255,255}, {147,255,255}, {64,255,255}, {64,255,255}, {64,255,255}, {0,0,0}, {64,255,255}, {245,218,204}, {245,218,204}, {64,255,255}, {0,0,0}, {64,255,255}, {245,218,204}, {245,218,204}, {245,218,204}, {0,0,0}, {64,255,255}, {245,218,204}, {245,218,204}, {245,218,204}, {0,0,0}, {64,255,255}, {245,218,204}, {245,218,204}, {245,218,204}, {245,218,204}, {64,255,255}, {245,218,204}, {245,218,204}, {245,218,204}, {64,255,255}, {245,218,204}, {245,218,204}, {41,255,255}, {41,255,255}, {0,0,0}, {147,255,255} },

    [2] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {188,255,255}, {166,218,166}, {166,218,166}, {166,218,166}, {0,0,0}, {188,255,255}, {166,218,166}, {166,218,166}, {166,218,166}, {0,0,0}, {188,255,255}, {166,218,166}, {166,218,166}, {166,218,166}, {0,0,0}, {188,255,255}, {166,218,166}, {166,218,166}, {166,218,166}, {4,232,184}, {188,255,255}, {166,218,166}, {166,218,166}, {166,218,166}, {0,0,0}, {166,218,166}, {166,218,166}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {166,218,166}, {166,218,166}, {166,218,166}, {0,0,0}, {0,0,0}, {188,255,255}, {166,218,166}, {166,218,166}, {166,218,166}, {0,0,0}, {188,255,255}, {166,218,166}, {166,218,166}, {166,218,166}, {0,0,0}, {188,255,255}, {166,218,166}, {166,218,166}, {166,218,166}, {0,0,0}, {188,255,255}, {166,218,166}, {166,218,166}, {166,218,166}, {4,232,184}, {188,255,255}, {166,218,166}, {166,218,166}, {166,218,166}, {0,0,0}, {166,218,166}, {166,218,166}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [3] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {147,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {147,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {147,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {147,255,255}, {0,0,0}, {245,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {188,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {188,255,255}, {4,232,184}, {166,218,166}, {188,255,255}, {0,0,0}, {188,255,255}, {4,232,184}, {166,218,166}, {188,255,255}, {0,0,0}, {188,255,255}, {147,255,255}, {166,218,166}, {188,255,255}, {0,0,0}, {188,255,255}, {147,255,255}, {166,218,166}, {188,255,255}, {245,218,204}, {188,255,255}, {73,255,85}, {73,255,85}, {188,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [4] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {73,255,85}, {73,255,85}, {166,218,166}, {0,0,0}, {0,0,0}, {166,218,166}, {166,218,166}, {166,218,166}, {245,218,204}, {0,0,0}, {166,218,166}, {166,218,166}, {166,218,166}, {245,218,204}, {0,0,0}, {166,218,166}, {166,218,166}, {166,218,166}, {245,218,204}, {0,0,0}, {73,255,85}, {73,255,85}, {73,255,85}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {147,255,255}, {0,0,0}, {245,218,204}, {0,0,0}, {0,0,0}, {147,255,255}, {0,0,0}, {245,218,204}, {0,0,0}, {0,0,0}, {147,255,255}, {0,0,0}, {245,218,204}, {0,0,0}, {0,0,0}, {147,255,255}, {0,0,0}, {245,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [5] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {0,0,0}, {188,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {188,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {188,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {188,255,255}, {41,255,255}, {41,255,255}, {188,255,255}, {0,0,0}, {188,255,255}, {0,245,245}, {0,245,245}, {52,255,255}, {0,0,0}, {0,0,0}, {74,255,255}, {74,255,255}, {0,0,0}, {188,255,255}, {0,0,0}, {188,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {188,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {219,255,255}, {188,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {219,255,255}, {188,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {219,255,255}, {188,255,255}, {41,255,255}, {41,255,255}, {188,255,255}, {219,255,255}, {188,255,255}, {0,245,245}, {0,245,245}, {52,255,255}, {0,0,0}, {0,0,0}, {74,255,255}, {74,255,255}, {0,0,0}, {188,255,255} },

};

const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BACKSPACE, KC_DEL);
const key_override_t double_quote_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOUBLE_QUOTE, KC_QUOTE);
const key_override_t colon_override = ko_make_basic(MOD_MASK_SHIFT, KC_COLON, KC_SEMICOLON);
const key_override_t underscore_override = ko_make_basic(MOD_MASK_SHIFT, KC_UNDERSCORE, KC_MINUS);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_key_override,
    &double_quote_override,
    &colon_override,
    &underscore_override,
    NULL
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
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;

    case TG(1):
        if (!record->event.pressed) {
            register_code(KC_CAPSLOCK);
        }
        break;
  }
  return true;
}


void matrix_init_user() {
  steno_set_mode(STENO_MODE_GEMINI);
}
