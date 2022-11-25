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
      tap_code(KC_CAPS);
      register_code(KC_LSHIFT);
    } else {
      tap_code(KC_CAPS);
    }
    wait_ms(10);
    // for Gui + Space shortcut
    // register_code(KC_LGUI);
    // register_code(KC_SPACE);
    // wait_ms(1);
    // unregister_code(KC_SPACE);
    // unregister_code(KC_LGUI);
    system_language_id = the_layer;
  }
}

bool process_hotkey_conversion(uint16_t keycode, keyrecord_t *record, layer_state_t state) {
  // bool is_en_layer = IS_LAYER_ON_STATE(state, _COLEMAK);
  bool is_ru_layer = IS_LAYER_ON_STATE(state, _RUSSIAN);
  bool is_ru_layer_exactly = state == (1 << _RUSSIAN);

  if (is_ru_layer) {
    switch (keycode) {
      case MO(_NAV):
      case MO(_FNN):
      case MO(_MOUSE):
        if (record->event.pressed) {
          switch_system_layout(_COLEMAK);
        } else {
          switch_system_layout(_RUSSIAN);
        }
        break;

      case L_LSYM_:
      case L_RSYM_:
        if (record->tap.count == 0) {
          // the key is being held, this means Sym layer activated
          if (record->event.pressed) {
            switch_system_layout(_COLEMAK);
          } else {
            switch_system_layout(_RUSSIAN);
          }
        }
        break;
    }

// TODO hangs if the home row pressed
    if (is_ru_layer_exactly) {
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
    }
  }
  // continue processing
  return true;
}
