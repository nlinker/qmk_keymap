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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_ESCAPE,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_Q,           KC_W,           KC_F,           KC_P,           KC_B,           KC_TRANSPARENT,         KC_TRANSPARENT, KC_J,           KC_L,           KC_U,           KC_Y,           KC_UNDS,        A_LOCK,
    KC_TAB,         L_LSYM,         L_LALT,         L_LCTL,         L_LSFT,         KC_G,           KC_TRANSPARENT,         KC_TRANSPARENT, KC_M,           L_RSFT,         L_RCTL,         L_RALT,         L_RSYM,         KC_ENTER,
    A_ATAB,         KC_Z,           KC_X,           KC_C,           KC_D,           KC_V,                                                   KC_K,           KC_H,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_NO,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LSHIFT,      KC_TRANSPARENT,                                         KC_TRANSPARENT, KC_RSHIFT,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    L_NAV,          KC_SPACE,       KC_TRANSPARENT,                 KC_TRANSPARENT, KC_BSPACE,      L_FNN
  ),
  [1] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    RU_YO,          RU_SHTI,        RU_TSE,         RU_U,           RU_KA,          RU_IE,          KC_TRANSPARENT,         KC_TRANSPARENT, RU_EN,          RU_GHE,         RU_SHA,         RU_SHCH,        RU_ZE,          RU_HA,
    RU_HARD,        L_LSYM_,        L_LALT_,        L_LCTL_,        L_LSFT_,        RU_PE,          KC_TRANSPARENT,         KC_TRANSPARENT, RU_ER,          L_RSFT_,        L_RCTL_,        L_RALT_,        L_RSYM_,        RU_E,
    KC_TRANSPARENT, RU_YA,          RU_CHE,         RU_ES,          RU_EM,          RU_I,                                                   RU_TE,          RU_SOFT,        RU_BE,          RU_YU,          RU_DOT,         KC_NO,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, LCTL(KC_Q),     LCTL(KC_W),     LCTL(KC_F),     LCTL(KC_P),     LCTL(KC_B),     KC_TRANSPARENT,         KC_TRANSPARENT, KC_F4,          KC_HOME,        KC_UP,          KC_END,         KC_F12,         KC_F2,
    KC_TAB,         MO(5),          KC_LALT,        KC_LCTRL,       KC_LSHIFT,      KC_NO,          KC_TRANSPARENT,         KC_TRANSPARENT, KC_F5,          KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_F11,         KC_ENTER,
    KC_TRANSPARENT, LCTL(KC_Z),     LCTL(KC_X),     LCTL(KC_C),     LCTL(KC_D),     LCTL(KC_V),                                             KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F3,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_CAPSLOCK,    KC_7,           KC_8,           KC_9,           KC_NO,          KC_TRANSPARENT,         KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,
    KC_TAB,         MO(5),          KC_4,           KC_5,           KC_6,           KC_NO,          KC_TRANSPARENT,         KC_TRANSPARENT, KC_CAPS,        KC_RSHIFT,      KC_RCTRL,       KC_LALT,        MO(5),          KC_ENTER,
    KC_TRANSPARENT, KC_0,           KC_1,           KC_2,           KC_3,           KC_NO,                                                  L_RUS,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [4] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_SCROLLLOCK,  KC_SCROLLLOCK,  KC_SCROLLLOCK,  KC_PSCREEN,     CAPS_WORD,      KC_TRANSPARENT,         KC_TRANSPARENT, KC_NO,          KC_MS_WH_LEFT,  KC_MS_UP,       KC_MS_WH_RIGHT, KC_MS_WH_UP,    KC_TRANSPARENT,
    KC_TAB,         KC_NO,          KC_NO,          KC_MS_BTN1,     KC_MS_BTN2,     KC_NO,          KC_TRANSPARENT,         KC_TRANSPARENT, KC_NO,          KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_MS_WH_DOWN,  KC_ENTER,
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_MS_BTN3,     KC_APPLICATION, KC_NO,                                                  KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [5] = LAYOUT_moonlander(                                                                                                                                  // KC_LCBR,        ST_MACRO_0,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,        KC_TRANSPARENT,         KC_TRANSPARENT, KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_PLUS,        KC_MINUS,       KC_TRANSPARENT,
    KC_TAB,         KC_DQUO,        KC_TILD,        KC_LPRN,        KC_RPRN,        KC_SCOLON,      KC_TRANSPARENT,         KC_TRANSPARENT, ST_MACRO_3,     KC_COLN,        KC_LCBR,        KC_RCBR,        KC_BSLASH,      KC_ENTER,
    KC_TRANSPARENT, KC_QUOTE,       KC_GRAVE,       KC_LBRC,        KC_RBRC,        KC_EQUAL,                                               ST_MACRO_4,     KC_PIPE,        KC_LABK,        KC_RABK,        KC_QUES,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [6] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRANSPARENT,         KC_TRANSPARENT, STN_FN,         STN_RES1,       STN_RES2,       STN_PWR,        KC_NO,          TO(0),
    KC_TRANSPARENT, STN_N1,         STN_N2,         STN_N3,         STN_N4,         STN_N5,         KC_TRANSPARENT,         KC_TRANSPARENT, STN_N6,         STN_N7,         STN_N8,         STN_N9,         STN_NA,         STN_NB,
    KC_TRANSPARENT, STN_S1,         STN_TL,         STN_PL,         STN_HL,         STN_ST1,        KC_TRANSPARENT,         KC_TRANSPARENT, STN_ST3,        STN_FR,         STN_PR,         STN_LR,         STN_TR,         STN_DR,
    KC_TRANSPARENT, STN_S2,         STN_KL,         STN_WL,         STN_RL,         STN_ST2,                                                STN_ST4,        STN_RR,         STN_BR,         STN_GR,         STN_SR,         STN_ZR,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, STN_A,          STN_O,          KC_TRANSPARENT,                                         KC_TRANSPARENT, STN_E,          STN_U,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_NO,          STN_NC,         KC_TRANSPARENT,                 KC_TRANSPARENT, STN_NC,         KC_NO
  ),
};

const uint16_t PROGMEM combo_cut[] = { LCTL(KC_C), LCTL(KC_V), COMBO_END };
const uint16_t PROGMEM combo_fnn[] = { KC_SPACE, MO(_NAV), COMBO_END };
const uint16_t PROGMEM combo_nav[] = { KC_BSPACE, MO(_FNN), COMBO_END };
const uint16_t PROGMEM combo0[] = { KC_UP, KC_END, COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_DOWN, KC_RIGHT, COMBO_END};
const uint16_t PROGMEM combo2[] = { KC_HOME, KC_UP, COMBO_END};
const uint16_t PROGMEM combo3[] = { KC_LEFT, KC_DOWN, COMBO_END};
const uint16_t PROGMEM combo4[] = { KC_F2, KC_F12, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_cut, LCTL(KC_X)),
    COMBO(combo_fnn, MO(_FNN)),
    COMBO(combo_nav, MO(_NAV)),
    COMBO(combo0, KC_PGUP),
    COMBO(combo1, KC_PGDOWN),
    COMBO(combo2, KC_INSERT),
    COMBO(combo3, KC_DELETE),
    COMBO(combo4, KC_F1),
};

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}


const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [0] = { {245,218,204}, {0,0,0}, {245,218,204}, {64,255,255}, {0,0,0}, {0,0,0}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {188,255,255}, {147,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {188,255,255}, {147,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {188,255,255}, {147,255,255}, {188,255,255}, {147,255,255}, {0,0,0}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {245,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {188,255,255}, {147,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {188,255,255}, {147,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {188,255,255}, {147,255,255}, {188,255,255}, {147,255,255}, {0,0,0}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0} },

    [1] = { {0,0,0}, {23,255,255}, {23,255,255}, {64,255,255}, {0,0,0}, {0,0,0}, {23,255,255}, {23,255,255}, {23,255,255}, {0,0,0}, {0,0,0}, {23,255,255}, {147,255,255}, {23,255,255}, {0,0,0}, {0,0,0}, {23,255,255}, {147,255,255}, {23,255,255}, {0,0,0}, {0,0,0}, {23,255,255}, {147,255,255}, {23,255,255}, {147,255,255}, {0,0,0}, {23,255,255}, {23,255,255}, {23,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {23,255,255}, {23,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {23,255,255}, {23,255,255}, {23,255,255}, {0,0,0}, {0,0,0}, {23,255,255}, {147,255,255}, {23,255,255}, {0,0,0}, {0,0,0}, {23,255,255}, {147,255,255}, {23,255,255}, {0,0,0}, {0,0,0}, {23,255,255}, {147,255,255}, {23,255,255}, {147,255,255}, {0,0,0}, {23,255,255}, {23,255,255}, {23,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0} },

    [2] = { {245,218,204}, {0,0,0}, {245,218,204}, {64,255,255}, {0,0,0}, {0,0,0}, {28,127,255}, {41,255,255}, {28,127,255}, {0,0,0}, {0,0,0}, {28,127,255}, {166,218,166}, {28,127,255}, {0,0,0}, {0,0,0}, {28,127,255}, {166,218,166}, {28,127,255}, {0,0,0}, {0,0,0}, {28,127,255}, {166,218,166}, {28,127,255}, {147,255,255}, {0,0,0}, {28,127,255}, {0,0,0}, {28,127,255}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {245,218,204}, {41,255,255}, {0,0,0}, {0,0,0}, {41,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {73,255,85}, {64,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {64,255,255}, {64,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {73,255,85}, {64,255,255}, {41,255,255}, {147,255,255}, {0,0,0}, {41,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0} },

    [3] = { {245,218,204}, {0,0,0}, {245,218,204}, {64,255,255}, {0,0,0}, {0,0,0}, {64,255,255}, {41,255,255}, {73,255,85}, {0,0,0}, {0,0,0}, {73,255,85}, {73,255,85}, {73,255,85}, {0,0,0}, {0,0,0}, {73,255,85}, {73,255,85}, {73,255,85}, {0,0,0}, {0,0,0}, {73,255,85}, {73,255,85}, {73,255,85}, {147,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {64,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {245,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {147,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {147,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {147,255,255}, {0,0,0}, {147,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {23,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0} },

    [4] = { {245,218,204}, {0,0,0}, {245,218,204}, {64,255,255}, {0,0,0}, {0,0,0}, {166,218,166}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {73,255,85}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {188,255,255}, {4,232,184}, {4,232,184}, {0,0,0}, {0,0,0}, {4,232,184}, {4,232,184}, {166,218,166}, {147,255,255}, {0,0,0}, {73,255,85}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {245,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {23,255,255}, {23,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {245,218,204}, {4,232,184}, {0,0,0}, {0,0,0}, {0,0,0}, {4,232,184}, {4,232,184}, {0,0,0}, {0,0,0}, {0,0,0}, {245,218,204}, {4,232,184}, {0,0,0}, {147,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0} },

    [5] = { {245,218,204}, {0,0,0}, {245,218,204}, {64,255,255}, {0,0,0}, {0,0,0}, {166,218,166}, {166,218,166}, {166,218,166}, {0,0,0}, {0,0,0}, {166,218,166}, {166,218,166}, {166,218,166}, {0,0,0}, {0,0,0}, {166,218,166}, {166,218,166}, {166,218,166}, {0,0,0}, {0,0,0}, {166,218,166}, {166,218,166}, {166,218,166}, {147,255,255}, {0,0,0}, {166,218,166}, {166,218,166}, {166,218,166}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {245,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {166,218,166}, {166,218,166}, {166,218,166}, {0,0,0}, {0,0,0}, {166,218,166}, {166,218,166}, {166,218,166}, {0,0,0}, {0,0,0}, {166,218,166}, {166,218,166}, {166,218,166}, {0,0,0}, {0,0,0}, {166,218,166}, {166,218,166}, {166,218,166}, {147,255,255}, {0,0,0}, {166,218,166}, {166,218,166}, {166,218,166}, {0,0,0}, {0,0,0}, {0,0,0}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0} },

    [6] = { {4,232,184}, {0,0,0}, {0,0,0}, {147,255,255}, {0,0,0}, {0,0,0}, {188,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {188,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {188,255,255}, {41,255,255}, {41,255,255}, {74,255,255}, {0,0,0}, {188,255,255}, {41,255,255}, {41,255,255}, {74,255,255}, {0,0,0}, {188,255,255}, {0,245,245}, {0,245,245}, {41,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {188,255,255}, {0,0,0}, {28,127,255}, {41,255,255}, {188,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {188,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {219,255,255}, {188,255,255}, {41,255,255}, {41,255,255}, {0,0,0}, {219,255,255}, {188,255,255}, {41,255,255}, {41,255,255}, {74,255,255}, {219,255,255}, {188,255,255}, {41,255,255}, {41,255,255}, {74,255,255}, {219,255,255}, {188,255,255}, {0,245,245}, {0,245,245}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {188,255,255}, {0,0,0}, {28,127,255} },

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
  new_state = update_tri_layer_state(new_state, _NAV, _FNN, _MOUSE);
  if (cur_state != new_state) {
    bool is_cur_ru = IS_LAYER_ON_STATE(cur_state, _RUSSIAN);
    bool is_new_ru = IS_LAYER_ON_STATE(new_state, _RUSSIAN);
    if (is_cur_ru && !is_new_ru) {
      // switch system ru -> en
      switch_system_layout(_COLEMAK);
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
          switch_system_layout(_COLEMAK);
          SEND_STRING("}" SS_TAP(X_LEFT));
          switch_system_layout(_RUSSIAN);
        } else {
          SEND_STRING("}" SS_TAP(X_LEFT));
        }
      }
      break;
    case ST_MACRO_1:
      if (record->event.pressed) {
      SEND_STRING(")" SS_TAP(X_LEFT));

      }
      break;
    case ST_MACRO_2:
      if (record->event.pressed) {
        if (is_ru) {
          switch_system_layout(_COLEMAK);
          SEND_STRING("]" SS_TAP(X_LEFT));
          switch_system_layout(_RUSSIAN);
        } else {
          SEND_STRING("]" SS_TAP(X_LEFT));
        }
    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      if (is_ru) {
        SEND_STRING(SS_LSFT("66"));
      } else {
        SEND_STRING("::");
      }
    }
    break;
    case ST_MACRO_4:
    if (record->event.pressed) {
      if (is_ru) {
        switch_system_layout(_COLEMAK);
        SEND_STRING("::<>" SS_TAP(X_LEFT));
        switch_system_layout(_RUSSIAN);
      } else {
        SEND_STRING("::<>" SS_TAP(X_LEFT));
      }
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
