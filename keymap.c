#include QMK_KEYBOARD_H
#include "version.h"

#include "keymap_russian.h"
#include "keymap_us_international.h"
#include "keymap_steno.h"
#include "process_key_override.h"
#include "print.h"

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
  ST_MACRO_0,
  ST_MACRO_1,
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           TG(4),
    KC_GRAVE,       KC_Q,           KC_W,           KC_F,           KC_P,           KC_B,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_J,           KC_L,           KC_U,           KC_Y,           KC_UNDS,        KC_EQUAL,
    KC_TAB,         KC_A,           KC_R,           KC_S,           KC_T,           KC_G,           KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_M,           KC_N,           KC_E,           KC_I,           KC_O,           KC_DQUO,
    KC_LGUI,        KC_Z,           LT(3,KC_X),     MT(MOD_LALT, KC_C),MT(MOD_LCTL, KC_D),KC_V,                                           KC_K,           MT(MOD_RCTL, KC_H),MT(MOD_LALT, KC_COMMA),LT(3,KC_DOT),   KC_SLASH,       KC_COLN,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LSHIFT,      TG(1),                                                                                                          KC_BSPACE,      KC_RSHIFT,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_SPACE,       TT(2),          KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_ENTER
  ),
  [1] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    ST_MACRO_0,     RU_SHTI,        RU_TSE,         RU_U,           RU_KA,          RU_IE,          RU_YO,                                          RU_MINS,        RU_EN,          RU_GHE,         RU_SHA,         RU_SHCH,        RU_ZE,          RU_HA,
    KC_TRANSPARENT, RU_EF,          RU_YERU,        RU_VE,          RU_A,           RU_PE,          RU_HARD,                                                                        RU_EQL,         RU_ER,          RU_O,           RU_EL,          RU_DE,          RU_ZHE,         RU_E,
    KC_TRANSPARENT, RU_YA,          RU_CHE,         RU_ES,          RU_EM,          RU_I,                                           RU_TE,          RU_SOFT,        RU_BE,          RU_YU,          RU_DOT,         RU_COLN,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
    KC_CAPSLOCK,    KC_MS_BTN2,     LCTL(KC_W),     KC_MS_UP,       KC_NO,          KC_MS_WH_UP,    KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_PGUP,        KC_HOME,        KC_UP,          KC_END,         KC_INSERT,      KC_F12,
    KC_TRANSPARENT, KC_MS_BTN1,     KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_MS_WH_DOWN,  KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_PGDOWN,      KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_DELETE,      CAPS_WORD,
    KC_TRANSPARENT, KC_PC_UNDO,     MO(3),          KC_LALT,        KC_LCTRL,       KC_PC_PASTE,                                    KC_PC_COPY,     KC_RCTRL,       KC_LALT,        MO(3),          KC_APPLICATION, KC_PSCREEN,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN3,                                                                                                     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
    KC_GRAVE,       KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_PLUS,        KC_MINUS,       KC_F12,
    KC_TRANSPARENT, KC_LABK,        KC_NO,          KC_LCBR,        KC_LPRN,        KC_LBRACKET,    KC_TRANSPARENT,                                                                 KC_TRANSPARENT, ST_MACRO_1,     KC_COLN,        KC_SCOLON,      KC_NO,          KC_BSLASH,      KC_QUOTE,
    KC_TRANSPARENT, KC_RABK,        KC_TRANSPARENT, KC_RCBR,        KC_RPRN,        KC_RBRACKET,                                    KC_NO,          KC_TILD,        KC_COMMA,       KC_DOT,         KC_QUES,        KC_PIPE,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [4] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,
    KC_TRANSPARENT, KC_NO,          KC_HOME,        KC_UP,          KC_END,         KC_PGUP,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_KP_PLUS,     KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_MINUS,    KC_KP_SLASH,
    KC_TRANSPARENT, KC_NO,          KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_PGDOWN,      KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_KP_0,        KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_ASTERISK, KC_EQUAL,
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_LALT,        KC_LCTRL,       KC_PC_PASTE,                                    KC_PC_COPY,     KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_KP_COMMA,    KC_NO,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_KP_ENTER
  ),
  [5] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_NO,                                          KC_NO,          KC_MEDIA_PREV_TRACK,KC_MEDIA_STOP,  KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT, TO(0),
    KC_TRANSPARENT, KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_TRANSPARENT,
    KC_TRANSPARENT, KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_TRANSPARENT,
    KC_LSHIFT,      KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_UP,          KC_RSHIFT,
    KC_LCTRL,       KC_TRANSPARENT, KC_LGUI,        KC_LALT,        KC_NO,          KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_RALT,        KC_RCTRL,       KC_LEFT,        KC_DOWN,        KC_RIGHT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [6] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          QK_STENO_BOLT,  QK_STENO_GEMINI,                                KC_TRANSPARENT, STN_FN,         STN_RES1,       STN_RES2,       STN_PWR,        KC_NO,          KC_NO,
    KC_TRANSPARENT, STN_N1,         STN_N2,         STN_N3,         STN_N4,         STN_N5,         KC_TRANSPARENT,                                 KC_TRANSPARENT, STN_N6,         STN_N7,         STN_N8,         STN_N9,         STN_NA,         STN_NB,         
    KC_TRANSPARENT, STN_S1,         STN_TL,         STN_PL,         STN_HL,         STN_ST1,        KC_TRANSPARENT,                                                                 KC_TRANSPARENT, STN_ST3,        STN_FR,         STN_PR,         STN_LR,         STN_TR,         STN_DR,         
    KC_TRANSPARENT, STN_S2,         STN_KL,         STN_WL,         STN_RL,         STN_ST2,                                        STN_ST4,        STN_RR,         STN_BR,         STN_GR,         STN_SR,         STN_ZR,         
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, STN_NC,         KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, STN_NC,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    STN_A,          STN_O,          KC_TRANSPARENT,                 KC_TRANSPARENT, STN_E,          STN_U
  ),
};

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = { {245,218,204}, {188,255,255}, {245,218,204}, {147,255,255}, {0,0,0}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,0}, {188,255,255}, {188,255,255}, {188,255,255}, {41,255,255}, {0,0,0}, {188,255,255}, {188,255,255}, {188,255,255}, {147,255,255}, {0,0,0}, {188,255,255}, {188,255,255}, {188,255,255}, {147,255,255}, {147,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {245,218,204}, {41,255,255}, {0,0,0}, {41,255,255}, {41,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,0}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,0}, {188,255,255}, {188,255,255}, {188,255,255}, {41,255,255}, {0,0,0}, {188,255,255}, {188,255,255}, {188,255,255}, {147,255,255}, {0,0,0}, {188,255,255}, {188,255,255}, {188,255,255}, {147,255,255}, {147,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {245,218,204}, {0,0,0}, {0,0,0}, {245,218,204} },

    [1] = { {4,232,184}, {64,255,255}, {245,218,204}, {147,255,255}, {0,0,0}, {166,218,166}, {166,218,166}, {166,218,166}, {166,218,166}, {0,0,0}, {166,218,166}, {166,218,166}, {166,218,166}, {166,218,166}, {0,0,0}, {166,218,166}, {166,218,166}, {166,218,166}, {166,218,166}, {0,0,0}, {166,218,166}, {166,218,166}, {166,218,166}, {166,218,166}, {147,255,255}, {166,218,166}, {166,218,166}, {166,218,166}, {166,218,166}, {0,0,0}, {166,218,166}, {166,218,166}, {245,218,204}, {41,255,255}, {0,0,0}, {41,255,255}, {41,255,255}, {166,218,166}, {166,218,166}, {64,255,255}, {0,0,0}, {166,218,166}, {166,218,166}, {166,218,166}, {64,255,255}, {0,0,0}, {166,218,166}, {166,218,166}, {166,218,166}, {166,218,166}, {0,0,0}, {166,218,166}, {166,218,166}, {166,218,166}, {166,218,166}, {0,0,0}, {166,218,166}, {166,218,166}, {166,218,166}, {166,218,166}, {147,255,255}, {166,218,166}, {166,218,166}, {166,218,166}, {166,218,166}, {0,0,0}, {64,255,255}, {64,255,255}, {245,218,204}, {0,0,0}, {0,0,0}, {245,218,204} },

    [2] = { {245,218,204}, {147,255,255}, {245,218,204}, {147,255,255}, {0,0,0}, {64,255,255}, {245,218,204}, {4,232,184}, {245,218,204}, {0,0,0}, {64,255,255}, {28,127,255}, {4,232,184}, {41,255,255}, {0,0,0}, {64,255,255}, {4,232,184}, {4,232,184}, {147,255,255}, {0,0,0}, {64,255,255}, {0,0,0}, {4,232,184}, {147,255,255}, {147,255,255}, {64,255,255}, {4,232,184}, {4,232,184}, {245,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {245,218,204}, {41,255,255}, {0,0,0}, {4,232,184}, {64,255,255}, {64,255,255}, {147,255,255}, {28,127,255}, {0,0,0}, {64,255,255}, {4,232,184}, {4,232,184}, {73,255,85}, {0,0,0}, {64,255,255}, {73,255,85}, {166,218,166}, {41,255,255}, {0,0,0}, {64,255,255}, {166,218,166}, {166,218,166}, {147,255,255}, {0,0,0}, {64,255,255}, {73,255,85}, {166,218,166}, {147,255,255}, {147,255,255}, {64,255,255}, {73,255,85}, {73,255,85}, {245,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {245,218,204}, {0,0,0}, {0,0,0}, {4,232,184} },

    [3] = { {245,218,204}, {166,218,166}, {245,218,204}, {147,255,255}, {0,0,0}, {64,255,255}, {166,218,166}, {166,218,166}, {166,218,166}, {0,0,0}, {64,255,255}, {166,218,166}, {0,0,0}, {41,255,255}, {0,0,0}, {64,255,255}, {166,218,166}, {166,218,166}, {166,218,166}, {0,0,0}, {64,255,255}, {166,218,166}, {166,218,166}, {166,218,166}, {147,255,255}, {64,255,255}, {166,218,166}, {166,218,166}, {166,218,166}, {0,0,0}, {0,0,0}, {0,0,0}, {245,218,204}, {41,255,255}, {0,0,0}, {41,255,255}, {64,255,255}, {64,255,255}, {166,218,166}, {166,218,166}, {0,0,0}, {64,255,255}, {166,218,166}, {166,218,166}, {166,218,166}, {0,0,0}, {64,255,255}, {166,218,166}, {0,0,0}, {41,255,255}, {0,0,0}, {64,255,255}, {166,218,166}, {166,218,166}, {166,218,166}, {0,0,0}, {64,255,255}, {166,218,166}, {166,218,166}, {166,218,166}, {147,255,255}, {64,255,255}, {166,218,166}, {166,218,166}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {245,218,204}, {0,0,0}, {0,0,0}, {245,218,204} },

    [4] = { {245,218,204}, {166,218,166}, {245,218,204}, {147,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {73,255,85}, {166,218,166}, {0,0,0}, {0,0,0}, {0,0,0}, {166,218,166}, {166,218,166}, {147,255,255}, {0,0,0}, {0,0,0}, {73,255,85}, {166,218,166}, {147,255,255}, {147,255,255}, {0,0,0}, {73,255,85}, {73,255,85}, {245,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {245,218,204}, {41,255,255}, {0,0,0}, {41,255,255}, {41,255,255}, {73,255,85}, {73,255,85}, {0,0,0}, {0,0,0}, {0,0,0}, {73,255,85}, {73,255,85}, {73,255,85}, {0,0,0}, {0,0,0}, {166,218,166}, {166,218,166}, {166,218,166}, {0,0,0}, {0,0,0}, {166,218,166}, {166,218,166}, {166,218,166}, {0,0,0}, {0,0,0}, {166,218,166}, {166,218,166}, {166,218,166}, {147,255,255}, {0,0,0}, {73,255,85}, {166,218,166}, {245,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {245,218,204}, {0,0,0}, {0,0,0}, {245,218,204} },

    [5] = { {245,218,204}, {0,0,0}, {245,218,204}, {147,255,255}, {147,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {147,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {147,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {245,218,204}, {245,218,204}, {0,0,0}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {147,255,255}, {245,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {245,218,204}, {245,218,204}, {28,127,255}, {0,0,0}, {0,0,0}, {0,0,0}, {245,218,204}, {28,127,255}, {0,0,0}, {0,0,0}, {0,0,0}, {147,255,255}, {28,127,255}, {0,0,0}, {0,0,0}, {0,0,0}, {147,255,255}, {28,127,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {245,218,204}, {0,0,0}, {0,0,0}, {245,218,204} },

    [6] = { {4,232,184}, {0,0,0}, {147,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {188,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {188,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {188,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {188,255,255}, {41,255,255}, {41,255,255}, {188,255,255}, {52,255,255}, {188,255,255}, {0,245,245}, {0,245,245}, {52,255,255}, {0,0,0}, {0,0,0}, {74,255,255}, {74,255,255}, {0,0,0}, {28,127,255}, {0,0,0}, {188,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {188,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {219,255,255}, {188,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {219,255,255}, {188,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {219,255,255}, {188,255,255}, {41,255,255}, {41,255,255}, {188,255,255}, {219,255,255}, {188,255,255}, {0,245,245}, {0,245,245}, {0,0,0}, {0,0,0}, {0,0,0}, {74,255,255}, {74,255,255}, {0,0,0}, {28,127,255} },

};

const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BACKSPACE, KC_DEL);
const key_override_t double_quote_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOUBLE_QUOTE, KC_QUOTE);
const key_override_t underscore_override = ko_make_basic(MOD_MASK_SHIFT, KC_UNDERSCORE, KC_MINUS);
const key_override_t colon_override = ko_make_basic(MOD_MASK_SHIFT, KC_COLON, KC_SEMICOLON);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_key_override,
    &double_quote_override,
    &underscore_override,
    &colon_override,
    NULL
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // // stub in case it gets needed
        //  case LT(3,KC_X):
        //  case LT(3,KC_DOT):
        //      // avoid swallowing the letters when slow typing
        //      return 250;

        default:
            return TAPPING_TERM;
    }
}

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
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n",
            keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
    switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LGUI(SS_TAP(X_SPACE)) SS_DELAY(100) SS_TAP(X_GRAVE) SS_DELAY(100) SS_LGUI(SS_TAP(X_SPACE)));

    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_SCOLON)) SS_DELAY(100) SS_LSFT(SS_TAP(X_SCOLON)));

    }
    break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case TG(1):
      if (!record->event.pressed) {
        register_code(KC_LGUI);
        register_code(KC_SPACE);
        unregister_code(KC_SPACE);
        unregister_code(KC_LGUI);
      }
      break;
  }
  return true;
}


void matrix_init_user() {
  steno_set_mode(STENO_MODE_GEMINI);
}
