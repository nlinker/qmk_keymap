#include QMK_KEYBOARD_H

#include "keymap_russian.h"
#include "process_key_override.h"
#include "process_combo.h"

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

enum iris_layers {
  _COLEMAK,
  _RUSSIAN,
  _NAV,
  _NUM,
  _SYM,
  _MOUSE,
  _QWERTY,
  _PLOVER,
};

enum custom_keycodes {
  RGB_SLD = SAFE_RANGE,
  L_LNAV,
  L_RNAV,
  ST_M_0,
  ST_M_1,
  ST_M_2,
  ST_M_3,
  ST_M_4,
  ST_M_5,
};


enum tap_dance_codes {
  DANCE_0,
};

#define L_RUS  TG(_RUSSIAN)
#define L_NAV  MO(_NAV)
#define L_SYM  MO(_SYM)
#define L_NUM  TG(_NUM)

// Colemak layer modifiers
#define L_LSYM  LT(_SYM, KC_A)
#define M_LALT  MT(MOD_LALT, KC_C)
#define M_LCTL  MT(MOD_LCTL, KC_D)
#define M_RCTL  MT(MOD_RCTL, KC_H)
#define M_RALT  MT(MOD_LALT, KC_COMMA)
#define L_RSYM  LT(_SYM,KC_O)

// Russian layer modifiers
#define LR_LSYM  LT(_SYM, RU_EF)
#define MR_LALT  MT(MOD_LALT, RU_ES)
#define MR_LCTL  MT(MOD_LCTL, RU_EM)
#define MR_RCTL  MT(MOD_RCTL, RU_SOFT)
#define MR_RALT  MT(MOD_LALT, RU_BE)
#define LR_RSYM  LT(_SYM, RU_ZHE)

#define A_INFO  LCTL(KC_Q)
#define A_SEL   LCTL(KC_W)
#define A_FIND  LCTL(KC_F)
#define A_UNDO  LCTL(KC_Z)
#define A_COPY  LCTL(KC_C)
#define A_CUT   LCTL(KC_X)
#define A_PAST  LCTL(KC_V)
#define A_LCBR  LCTL(KC_LBRACKET)
#define A_RCBR  LCTL(KC_RBRACKET)
#define A_ATAB  LGUI(KC_TAB)

#define CAPSWD  CAPS_WORD

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    CAPSWD,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_GRV,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                               KC_J,    KC_L,    KC_U,    KC_Y,    KC_UNDS, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  L_LSYM,  KC_R,    KC_S,    KC_T,    KC_G,                               KC_M,    KC_N,    KC_E,    KC_I,    L_RSYM,  A_PAST,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     A_ATAB,  KC_Z,    KC_X,    M_LALT,  M_LCTL,  KC_V,    KC_DEL,           KC_BSPC, KC_K,    M_RCTL,  M_RALT,  KC_DOT,  KC_SLSH, A_COPY,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LSFT, L_LNAV,  KC_SPC,                    KC_ENT,  L_RNAV,  KC_RSFT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),


  [_RUSSIAN] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, KC_CAPS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RU_YO,   RU_SHTI, RU_TSE,  RU_U,    RU_KA,   RU_IE,                              RU_EN,   RU_GHE,  RU_SHA,  RU_SHCH, RU_ZE,   RU_HA,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, LR_LSYM, RU_YERU, RU_VE,   RU_A,    RU_PE,                              RU_ER,   RU_O,    RU_EL,   RU_DE,   LR_RSYM, RU_E,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, RU_YA,   RU_CHE,  MR_LALT, MR_RCTL, RU_I,    _______,          _______, RU_TE,   MR_RCTL, MR_RALT, RU_YU,   RU_DOT,  RU_HARD,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),


  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, A_INFO,  A_SEL,   A_FIND,  KC_PSCR, A_LCBR,                             KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_F12,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, A_RCBR,                             KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LGUI, A_UNDO,  L_NUM,   KC_LALT, KC_LCTL, KC_APP,  _______,          _______, A_CUT,   KC_RCTL, KC_LALT, XXXXXXX, XXXXXXX, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_NUM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, XXXXXXX, KC_HOME, KC_UP,   KC_END,  KC_PGUP,                            KC_PPLS, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, KC_PCMM,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, L_SYM,   KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                            KC_P0,   KC_P4,   KC_P5,   KC_P6,   KC_PAST, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LGUI, A_UNDO,  _______, KC_LALT, KC_LCTL, XXXXXXX, _______,          _______, KC_EQL,  KC_P1,   KC_P2,   KC_P3,   KC_PSLS, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   KC_PENT, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_SYM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_PLUS, KC_MINS, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_DQUO, KC_TILD, KC_LCBR, KC_LPRN, KC_LBRC,                            ST_M_3,  KC_COLN, KC_SCLN, KC_EQL,  KC_BSLS, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_QUOT, KC_GRV,  ST_M_0,  ST_M_1,  ST_M_2,  _______,          _______, ST_M_4,  KC_PIPE, KC_LABK, KC_RABK, KC_QUES, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_MOUSE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, KC_MS_U, _______, KC_WH_U,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_BTN1, KC_BTN2, KC_BTN3, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
};

void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom(); // enables Rgb, without saving settings
  rgblight_sethsv_noeeprom(180, 255, 255); // sets the color to teal/cyan without saving
  rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT); // sets mode to Fast breathing without saving
}

const uint16_t PROGMEM combo_cut[] = { LCTL(KC_C), LCTL(KC_V), COMBO_END };
const uint16_t PROGMEM combo_toggle_ru[] = { KC_DEL, KC_BSPC, COMBO_END };

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_cut, LCTL(KC_X)),
    COMBO(combo_toggle_ru, TG(_RUSSIAN)),
};

const key_override_t override_underscore = ko_make_basic(MOD_MASK_SHIFT, KC_UNDERSCORE, KC_MINUS);
// const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BACKSPACE, KC_DEL);
// const key_override_t override_double_quote = ko_make_basic(MOD_MASK_SHIFT, KC_DOUBLE_QUOTE, KC_QUOTE);
// const key_override_t override_colon = ko_make_basic(MOD_MASK_SHIFT, KC_COLON, KC_SEMICOLON);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &override_underscore,
    NULL
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LT(4,KC_A):
    case LT(4,KC_O):
      return TAPPING_TERM + 50;
    default:
      return TAPPING_TERM;
  }
}

// changes underglow based on current layer
#define RBG_VAL 120
layer_state_t layer_state_set_user(layer_state_t state) {
  switch(biton32(state)) {
    case _RUSSIAN:
      rgblight_sethsv_noeeprom(31, 223, RBG_VAL);
      break;
    case _NAV:
      rgblight_sethsv_noeeprom(63, 191, RBG_VAL);
      break;
    case _NUM:
      rgblight_sethsv_noeeprom(95, 159, RBG_VAL);
      break;
    case _SYM:
      rgblight_sethsv_noeeprom(127, 127, RBG_VAL);
      break;
    case _MOUSE:
      rgblight_sethsv_noeeprom(159, 95, RBG_VAL);
      break;
    default:
      rgblight_sethsv(0, 255, RBG_VAL);
      break;
  }
  return state;
}

static int nav_count = 0;
static bool nav_should_on = false;
static bool nav_should_stick = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case L_LNAV:
    case L_RNAV:
      if (record->event.pressed) {
        // either left or right key is pressed
        nav_count += 1;
        if (nav_count >= 2) {
          // press 2 buttons makes it sticky
          nav_should_stick = true;
        } else if (nav_should_stick) {
          nav_should_stick = false;
        }
        nav_should_on = true;
      } else {
        // either left or right key is released
        nav_count -= 1;
        nav_should_on = nav_should_stick;
      }
      if (nav_should_on) {
        layer_on(_NAV);
      } else {
        layer_off(_NAV);
      }
      break;

    case ST_M_0:
      if (record->event.pressed) {
        SEND_STRING("}" SS_TAP(X_LEFT));

      }
      break;
    case ST_M_1:
      if (record->event.pressed) {
        SEND_STRING(")" SS_TAP(X_LEFT));

      }
      break;
    case ST_M_2:
      if (record->event.pressed) {
        SEND_STRING("]" SS_TAP(X_LEFT));

      }
      break;
    case ST_M_3:
      if (record->event.pressed) {
        SEND_STRING("::");

      }
      break;
    case ST_M_4:
      if (record->event.pressed) {
        SEND_STRING("::<>" SS_TAP(X_LEFT));

      }
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case L_RUS:
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
