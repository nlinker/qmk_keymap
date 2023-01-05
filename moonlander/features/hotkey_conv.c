#include "moonlander.h"
#include "hotkey_conv.h"
#include "my_keycodes.h"
#include "my_layers.h"

enum SwitchState switch_state = SS_OFF;
layer_state_t cur_state = 0;
static uint8_t system_language_id = 0;

void switch_system_layout(uint8_t the_layer) {
  if (system_language_id != the_layer) {
    const uint8_t mods = get_mods() | get_oneshot_mods();
    const bool is_shift_pressed = mods & MOD_MASK_SHIFT;
    if (is_shift_pressed) {
      // here goes the workaround, since Shift+Caps turns Caps on, not switches the language
      unregister_code(KC_LSHIFT);
      tap_code(KC_CAPS);
      register_code(KC_LSHIFT);
    } else {
      tap_code(KC_CAPS);
    }
    system_language_id = the_layer;
  }
}

//static char state_bin[33];
//static char *padding = "..........................";

bool process_hotkey_conversion(uint16_t keycode, keyrecord_t *record, layer_state_t state) {

//  itoa(state, state_bin, 2);
//  int pad_len = 8 - strlen(state_bin) < 0? 0: 8 - strlen(state_bin);
//  uprintf("kc: 0x%04X, col: %3u, row: %3u, pressed: %u, [%*.*s%s]\n",
//          keycode, record->event.key.col, record->event.key.row, record->event.pressed,
//          pad_len, pad_len, padding, state_bin);

  // the keycodes, that independent on the language system layout
  switch (keycode) {
    case KC_MINS   : // #define RU_MINS KC_MINS    // -
    case KC_EQL    : // #define RU_EQL  KC_EQL     // =
    case KC_BSLS   : // #define RU_BSLS KC_BSLS    // (backslash)
    case S(RU_1)   : // #define RU_EXLM S(RU_1)    // !
    case S(RU_2)   : // #define RU_DQUO S(RU_2)    // "
    case S(RU_3)   : // #define RU_NUM  S(RU_3)    // №
    case S(RU_4)   : // #define RU_SCLN S(RU_4)    // ;
    case S(RU_5)   : // #define RU_PERC S(RU_5)    // %
    case S(RU_6)   : // #define RU_COLN S(RU_6)    // :
    case S(RU_7)   : // #define RU_QUES S(RU_7)    // ?
    case S(RU_8)   : // #define RU_ASTR S(RU_8)    // *
    case S(RU_9)   : // #define RU_LPRN S(RU_9)    // (
    case S(RU_0)   : // #define RU_RPRN S(RU_0)    // )
    case S(RU_MINS): // #define RU_UNDS S(RU_MINS) // _
    case S(RU_EQL) : // #define RU_PLUS S(RU_EQL)  // +
    case S(RU_BSLS): // #define RU_SLSH S(RU_BSLS) // /
    case KC_SLSH   : // #define RU_DOT  KC_SLSH    // .
    case S(RU_DOT) : // #define RU_COMM S(RU_DOT)  // ,
      return true;
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
