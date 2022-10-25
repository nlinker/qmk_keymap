#include QMK_KEYBOARD_H

#include "process_key_override.h"
#include "process_combo.h"

#include "my_keycodes.h"
#include "my_layers.h"
#include "features/layer_lock.h"
#include "features/short_conv.h"

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

static layer_state_t current_layer_state = 0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                               KC_J,    KC_L,    KC_U,    KC_Y,    KC_UNDS, CAPSWD,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  L_LSYM,  KC_R,    KC_S,    KC_T,    KC_G,                               KC_M,    KC_N,    KC_E,    KC_I,    L_RSYM,  KC_ENT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     A_ATAB,  KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    _______,          _______, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, L_LOCK,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LSFT, MO(2),   KC_SPC,                    KC_BSPC, MO(3),   KC_RSFT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RUSSIAN] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RU_YO,   RU_SHTI, RU_TSE,  RU_U,    RU_KA,   RU_IE,                              RU_EN,   RU_GHE,  RU_SHA,  RU_SHCH, RU_ZE,   RU_HA,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, LR_LSYM, RU_YERU, RU_VE,   RU_A,    RU_PE,                              RU_ER,   RU_O,    RU_EL,   RU_DE,   LR_RSYM, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     RU_HARD, RU_YA,   RU_CHE,  RU_ES,   RU_EM,   RU_I,    _______,          _______, RU_TE,   RU_SOFT, RU_BE,   RU_YU,   RU_DOT,  RU_E,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, A_CT_Q,  A_CT_W,  A_CT_F,  A_CT_P,  A_CT_B,                             A_CT_C,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, L_SYM,   KC_LALT, KC_LCTL, KC_LSFT, KC_LGUI,                            A_CT_V,  KC_LEFT, KC_DOWN, KC_RGHT, L_SYM,   _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     A_ATAB,  A_CT_Z,  XXXXXXX, A_CT_E,  A_CT_D,  A_CT_Y,  _______,          _______, KC_INS,  KC_DEL,  A_LCBR,  A_RCBR,  KC_PGDN, L_LOCK,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_NUM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              L_RUS,   KC_7,    KC_8,    KC_9,    _______, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, L_SYM,   KC_PSCR, KC_F6,   KC_F7,   KC_APP,                             KC_RALT, A_MT_4,  A_MT_5,  A_MT_6,  L_SYM,   _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     A_ATAB,  KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,          _______, KC_0,    KC_1,    KC_2,    KC_3,    _______, L_LOCK,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_MOUSE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______,                            _______, _______, KC_MS_U, _______, KC_WH_U, XXXXXXX,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, KC_BTN2, KC_BTN3, KC_BTN1, _______,                            _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     A_ATAB,  _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, L_LOCK,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_SYM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_PLUS, KC_MINS, KC_CAPS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_DQUO, KC_TILD, KC_LCBR, KC_LPRN, KC_LBRC,                            ST_M_3 , KC_COLN, KC_SCLN, KC_EQL,  KC_BSLS, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     A_ATAB,  KC_QUOT, KC_GRV,  ST_M_0,  ST_M_1,  ST_M_2,  _______,          _______, ST_M_4,  KC_PIPE, KC_LABK, KC_RABK, KC_QUES, L_LOCK,
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
  current_layer_state = state;
  state = update_tri_layer_state(state, _NAV, _NUM, _MOUSE);
  return state;
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

//const uint16_t PROGMEM combo_toggle_en_1[] = { KC_P, KC_T, COMBO_END };
//const uint16_t PROGMEM combo_toggle_en_2[] = { KC_L, KC_N, COMBO_END };
//const uint16_t PROGMEM combo_toggle_ru_1[] = { RU_KA, RU_A, COMBO_END };
//const uint16_t PROGMEM combo_toggle_ru_2[] = { RU_GHE, RU_O, COMBO_END };
const uint16_t PROGMEM combo_cut[] = { LCTL(KC_C), LCTL(KC_V), COMBO_END };
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
//    COMBO(combo_toggle_en_1, TG(_RUSSIAN)),
//    COMBO(combo_toggle_en_2, TG(_RUSSIAN)),
//    COMBO(combo_toggle_ru_1, TG(_RUSSIAN)),
//    COMBO(combo_toggle_ru_2, TG(_RUSSIAN)),
    COMBO(combo_cut, LCTL(KC_X)),
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

//layer_state_t layer_state_set_user(layer_state_t state) {
//  current_layer_state = state;
//  state = update_tri_layer_state(state, _NAV, _NUM, _MOUSE);
//  return state;
//}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_layer_lock(keycode, record, L_LOCK)) {
    return false;
  }
  if (!process_shortcut_conv(keycode, record, current_layer_state)) {
    return false;
  }

  switch (keycode) {
    case L_RUS:
      if (!record->event.pressed) {
        const bool is_ru_layer = IS_LAYER_ON_STATE(current_layer_state, _RUSSIAN);
        if (is_ru_layer) {
          switch_system_layout(_COLEMAK);
        } else {
          switch_system_layout(_RUSSIAN);
        }
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
  }
  return true;
}
