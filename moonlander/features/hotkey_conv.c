#include "moonlander.h"
#include "hotkey_conv.h"
#include "my_keycodes.h"
#include "my_layers.h"

static uint8_t system_language_id = 0;

void switch_system_layout(uint8_t the_layer) {
  if (system_language_id != the_layer) {
    const uint8_t mods = get_mods() | get_oneshot_mods();
    const bool is_shift_pressed = mods & MOD_MASK_SHIFT;
    if (is_shift_pressed) {
      // here goes the workaround, since Shift+Caps turns Caps on, not switches the language
      unregister_code(KC_LSHIFT);
      SEND_STRING(SS_TAP(X_CAPS) SS_DELAY(10));
      register_code(KC_LSHIFT);
    } else {
      // tap_code(KC_CAPS);
      SEND_STRING(SS_TAP(X_CAPS) SS_DELAY(10));
    }
    system_language_id = the_layer;
  }
}

static char cur_state_bin[33];
static char *padding = "..........................";

bool process_hotkey_conversion(uint16_t keycode, keyrecord_t *record, layer_state_t cur_state) {

  // ! @ { } %   ^ & * + -
  // " ~ ( ) $   M : ; = \_
  // ' ` [ ] #   M | < > ?

  // ! " Х Ъ %   : ? * + -
  // Э Ё ( ) ;   M Ж ж = \_
  // э ё х ъ №   M / Б Ю ,

  // KC_TRANSPARENT, KC_EXLM,        KC_AT,          KC_LCBR,        ST_MACRO_0,     KC_PERC,        KC_TRANSPARENT,         KC_TRANSPARENT, KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_PLUS,        KC_MINUS,       KC_TRANSPARENT,
  // KC_TAB,         KC_DQUO,        KC_TILD,        KC_LPRN,        ST_MACRO_1,     KC_DLR,         KC_TRANSPARENT,         KC_TRANSPARENT, ST_MACRO_3,     KC_COLN,        KC_SCOLON,      KC_EQUAL,       KC_BSLASH,      KC_ENTER,
  // KC_TRANSPARENT, KC_QUOTE,       KC_GRAVE,       KC_LBRACKET,    ST_MACRO_2,     KC_HASH,                                                ST_MACRO_4,     KC_PIPE,        KC_LABK,        KC_RABK,        KC_QUES,        KC_TRANSPARENT,

  bool is_ru = IS_LAYER_ON_STATE(cur_state, _RUSSIAN);
  // bool is_sym = IS_LAYER_ON_STATE(cur_state, _SYM);

  itoa(cur_state, cur_state_bin, 2);
  int pad_len_cur = 8 - strlen(cur_state_bin) < 0? 0: 8 - strlen(cur_state_bin);
  uprintf("cur_state: [%*.*s%s] sys_lang_id: %d, keycode: %d, is_ru: %d\n", pad_len_cur, pad_len_cur, padding, cur_state_bin,
          system_language_id, keycode, is_ru);

  if (is_ru) {
    switch (keycode) {
      case KC_EXLM:
      case KC_PERC:
      case KC_PLUS:
      case KC_MINUS:
      case KC_LPRN:
      case KC_RPRN:
      case KC_BSLASH:
      case KC_EQUAL:
        keycode = keycode;
        break;

      case KC_DQUO:
        keycode = S(KC_2);
        break;

      case KC_AT:
      case KC_CIRC:
      case KC_AMPR:
      case KC_ASTR:
      case KC_TILD:
      case KC_DLR:
      case KC_COLN:
      case KC_SCOLON:
      case KC_LCBR:
      case KC_QUOTE:
      case KC_GRAVE:
      case KC_HASH:
      case KC_PIPE:
      case KC_LABK:
      case KC_RABK:
      case KC_LBRACKET:
      case KC_QUES:
//        switch_system_layout(_COLEMAK);
//        switch_system_layout(_RUSSIAN);
        break;
    }
//    if (record->event.pressed) {
//      register_code16(keycode);
//    } else {
//      unregister_code16(keycode);
//    }
//    return false;
  }

//  switch (switch_state) {
//    case SS_OFF:
//      break;
//    case SS_PENDING:
//      switch_system_layout(_COLEMAK);
//      switch_state = SS_ON;
//      break;
//    case SS_ON:
//      switch_system_layout(_RUSSIAN);
//      switch_state = SS_PENDING;
//      break;
//  }

//  if (is_ru_layer) {
//    if (is_ru_layer_exactly) {
//      uint8_t r = record->event.key.row;
//      uint8_t c = record->event.key.col;
//      if (0 <= r && r < MATRIX_ROWS && 0 <= c && c < MATRIX_COLS) {
//        const uint16_t new_kc = keymaps[_COLEMAK][r][c];
//        const uint8_t mods = get_mods() | get_oneshot_mods();
//        if ((mods & MOD_MASK_CTRL) || (mods & MOD_MASK_ALT) || (mods & MOD_MASK_GUI)) {
//          if (record->event.pressed) {
//            register_code16(new_kc);
//          } else {
//            unregister_code16(new_kc);
//          }
//          return false;
//        }
//      }
//    }
//  }
  // continue processing
  return true;
}
