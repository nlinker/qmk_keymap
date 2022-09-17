#include QMK_KEYBOARD_H

#include "keymap_russian.h"
#include "process_key_override.h"
#include "print.h"

enum iris_layers {
  _COLEMAK,
  _RUS,
  _NAV,
  _SYM,
  _NUM,
};

enum custom_keycodes {
  COLEMAK = SAFE_RANGE,
  L_LNAV,
  L_RNAV,
  ST_M_0,
  ST_M_1,
  ST_M_2,
};


enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,
  DANCE_3,
};

#define L_RUS  TG(_RUS)
#define L_NAV  TT(_NAV)
#define L_SYM  MO(_SYM)
#define L_NUM  TG(_NUM)

#define L_LSYM  LT(3, KC_X)
#define M_LALT  MT(MOD_LALT, KC_C)
#define M_LCTL  MT(MOD_LCTL, KC_D)

#define M_RCTL  MT(MOD_RCTL, KC_H)
#define M_RALT  MT(MOD_LALT, KC_COMMA)
#define L_RSYM  LT(3, KC_DOT)

#define A_SEL   LCTL(KC_W)
#define A_PASTE TD(DANCE_1)
#define A_COPY  TD(DANCE_2)
#define A_CUT   TD(DANCE_3)
#define A_UNDO  LCTL(KC_Z)

#define CAPSWD  CAPS_WORD
#define RU_TDSH  TD(DANCE_0)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    L_NUM,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_GRV,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                               KC_J,    KC_L,    KC_U,    KC_Y,    KC_UNDS, KC_EQL,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                               KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_DQUO,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LGUI, KC_Z,    L_LSYM,  M_LALT,  M_LCTL,  KC_V,    L_RUS,            KC_BSPC, KC_K,    M_RCTL,  M_RALT,  L_RSYM,  KC_SLSH, KC_COLN,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LSFT, KC_SPC,  L_LNAV,                    L_RNAV,   KC_ENT,  KC_RSFT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),


  [_RUS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RU_YO,   RU_SHTI, RU_TSE,  RU_U,    RU_KA,   RU_IE,                              RU_EN,   RU_GHE,  RU_SHA,  RU_SHCH, RU_ZE,   RU_HA,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, RU_EF,   RU_YERU, RU_VE,   RU_A,    RU_PE,                              RU_ER,   RU_O,    RU_EL,   RU_DE,   RU_ZHE,  RU_E,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, RU_YA,   RU_CHE,  RU_ES,   RU_EM,   RU_I,    _______,          _______, RU_TE,   RU_TDSH, RU_BE,   RU_YU,   RU_DOT,  RU_COLN,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),


  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_WH_U, A_SEL,   KC_MS_U, KC_PSCR, KC_BTN3,                            KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_F12,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_WH_D, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN2,                            KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_CAPS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, XXXXXXX, L_SYM,   KC_LALT, KC_LCTL, XXXXXXX, KC_BTN1,          _______, KC_APP,  A_PASTE, A_COPY,  A_CUT,   A_UNDO,  CAPSWD,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_SYM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_BSLS, KC_MINS, KC_F12,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, ST_M_0,  KC_LABK, KC_LCBR, KC_LPRN, KC_LBRC,                            ST_M_2,  KC_COLN, KC_SCLN, KC_PIPE, KC_PLUS, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, ST_M_1,  KC_RABK, KC_RCBR, KC_RPRN, KC_RBRC, _______,          _______, XXXXXXX, KC_TILD, KC_COMM, KC_DOT,  KC_QUES, XXXXXXX,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_NUM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_PGUP, KC_HOME, KC_UP,   KC_END,  XXXXXXX,                            KC_PPLS, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, KC_PSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,                            KC_P0,   KC_P4,   KC_P5,   KC_P6,   KC_PAST, KC_EQL,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, XXXXXXX, XXXXXXX, KC_LALT, KC_LCTL, XXXXXXX, _______,          _______, XXXXXXX, KC_P1,   KC_P2,   KC_P3,   KC_PCMM, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, KC_PENT, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};


// const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BACKSPACE, KC_DEL);
const key_override_t double_quote_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOUBLE_QUOTE, KC_QUOTE);
const key_override_t underscore_override = ko_make_basic(MOD_MASK_SHIFT, KC_UNDERSCORE, KC_MINUS);
const key_override_t colon_override = ko_make_basic(MOD_MASK_SHIFT, KC_COLON, KC_SEMICOLON);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &double_quote_override,
    &underscore_override,
    &colon_override,
    NULL
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LT(3,KC_X):
    case LT(3,KC_DOT):
      return TAPPING_TERM + 50;
    default:
      return TAPPING_TERM;
  }
}

// changes underglow based on current layer
#define RBG_VAL 120
layer_state_t layer_state_set_user(layer_state_t state) {
  enum iris_layers {
      _COLEMAK,
      _RUS,
      _NAV,
      _SYM,
      _NUM,
  };

  switch(biton32(state)) {
    case _RUS:
      // green-ish
      rgblight_sethsv_noeeprom(72, 221, RBG_VAL);
      break;
    case _NAV:
      // Red
      rgblight_sethsv_noeeprom(0, 255, RBG_VAL);
      break;
    case _SYM:
      // Dark Blue
      rgblight_sethsv_noeeprom(255, 0, RBG_VAL);
      break;
    case _NUM:
      // Violet
      rgblight_sethsv_noeeprom(96, 96, RBG_VAL);
      break;
    default:
      // Default colors
      rgblight_sethsv(32, 170, RBG_VAL);
      break;
  }
  return state;
}

static int nav_count = 0;
static bool nav_should_on = false;
static bool nav_should_stick = false;

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
#ifdef CONSOLE_ENABLE
  uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
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
        SEND_STRING(SS_LSFT(SS_TAP(X_COMMA)) SS_DELAY(100) SS_TAP(X_EQUAL));

      }
      break;
    case ST_M_1:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT(SS_TAP(X_DOT)) SS_DELAY(100) SS_TAP(X_EQUAL));

      }
      break;
    case ST_M_2:
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT(SS_TAP(X_SCOLON)) SS_DELAY(100) SS_LSFT(SS_TAP(X_SCOLON)));

      }
      break;
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

// region === Tap dances ===
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

static tap dance_state[4];

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
    tap_code16(RU_SOFT);
    tap_code16(RU_SOFT);
    tap_code16(RU_SOFT);
  }
  if(state->count > 3) {
    tap_code16(RU_SOFT);
  }
}

void dance_0_finished(qk_tap_dance_state_t *state, void *user_data) {
  dance_state[0].step = dance_step(state);
  switch (dance_state[0].step) {
    case SINGLE_TAP: register_code16(RU_SOFT); break;
    case SINGLE_HOLD: register_code16(RU_HARD); break;
    case DOUBLE_TAP: register_code16(RU_SOFT); register_code16(RU_SOFT); break;
    case DOUBLE_SINGLE_TAP: tap_code16(RU_SOFT); register_code16(RU_SOFT);
  }
}

void dance_0_reset(qk_tap_dance_state_t *state, void *user_data) {
  wait_ms(10);
  switch (dance_state[0].step) {
    case SINGLE_TAP: unregister_code16(RU_SOFT); break;
    case SINGLE_HOLD: unregister_code16(RU_HARD); break;
    case DOUBLE_TAP: unregister_code16(RU_SOFT); break;
    case DOUBLE_SINGLE_TAP: unregister_code16(RU_SOFT); break;
  }
  dance_state[0].step = 0;
}
void on_dance_1(qk_tap_dance_state_t *state, void *user_data);
void dance_1_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_1_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_1(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LCTL(KC_V));
        tap_code16(LCTL(KC_V));
        tap_code16(LCTL(KC_V));
    }
    if(state->count > 3) {
        tap_code16(LCTL(KC_V));
    }
}

void dance_1_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(LCTL(KC_V)); break;
        case SINGLE_HOLD: register_code16(KC_RCTRL); break;
        case DOUBLE_TAP: register_code16(LCTL(KC_V)); register_code16(LCTL(KC_V)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LCTL(KC_V)); register_code16(LCTL(KC_V));
    }
}

void dance_1_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(LCTL(KC_V)); break;
        case SINGLE_HOLD: unregister_code16(KC_RCTRL); break;
        case DOUBLE_TAP: unregister_code16(LCTL(KC_V)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LCTL(KC_V)); break;
    }
    dance_state[1].step = 0;
}
void on_dance_2(qk_tap_dance_state_t *state, void *user_data);
void dance_2_finished(qk_tap_dance_state_t *state, void *user_data);
void dance_2_reset(qk_tap_dance_state_t *state, void *user_data);

void on_dance_2(qk_tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LCTL(KC_C));
        tap_code16(LCTL(KC_C));
        tap_code16(LCTL(KC_C));
    }
    if(state->count > 3) {
        tap_code16(LCTL(KC_C));
    }
}

void dance_2_finished(qk_tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(LCTL(KC_C)); break;
        case SINGLE_HOLD: register_code16(KC_LALT); break;
        case DOUBLE_TAP: register_code16(LCTL(KC_C)); register_code16(LCTL(KC_C)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LCTL(KC_C)); register_code16(LCTL(KC_C));
    }
}

void dance_2_reset(qk_tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(LCTL(KC_C)); break;
        case SINGLE_HOLD: unregister_code16(KC_LALT); break;
        case DOUBLE_TAP: unregister_code16(LCTL(KC_C)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LCTL(KC_C)); break;
    }
    dance_state[2].step = 0;
}
void on_dance_3(qk_tap_dance_state_t* state, void* user_data);
void dance_3_finished(qk_tap_dance_state_t* state, void* user_data);
void dance_3_reset(qk_tap_dance_state_t* state, void* user_data);

void on_dance_3(qk_tap_dance_state_t* state, void* user_data) {
  if(state->count == 3) {
    tap_code16(LCTL(KC_X));
    tap_code16(LCTL(KC_X));
    tap_code16(LCTL(KC_X));
  }
  if(state->count > 3) {
    tap_code16(LCTL(KC_X));
  }
}

void dance_3_finished(qk_tap_dance_state_t* state, void* user_data) {
  dance_state[3].step = dance_step(state);
  switch (dance_state[3].step) {
    case SINGLE_TAP: register_code16(LCTL(KC_X)); break;
    case SINGLE_HOLD: layer_on(3);break;
    case DOUBLE_TAP: register_code16(LCTL(KC_X)); register_code16(LCTL(KC_X));break;
    case DOUBLE_SINGLE_TAP: tap_code16(LCTL(KC_X)); register_code16(LCTL(KC_X));
  }
}

void dance_3_reset(qk_tap_dance_state_t* state, void* user_data) {
  wait_ms(10);
  switch (dance_state[3].step) {
    case SINGLE_TAP:unregister_code16(LCTL(KC_X));break;
    case SINGLE_HOLD:layer_off(3);break;
    case DOUBLE_TAP:unregister_code16(LCTL(KC_X));break;
    case DOUBLE_SINGLE_TAP:unregister_code16(LCTL(KC_X));break;
  }
  dance_state[3].step = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
    [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
    [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
    [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
};

// endregion
