#include "lat_word.h"
#include "my_layers.h"
#include "features/short_conv.h"

static bool is_lat_word_on = false;

uint16_t extract_base_keycode(uint16_t keycode, const keyrecord_t *record) {
  // Get the base keycode of a mod or layer tap key
  switch (keycode) {
    case QK_MOD_TAP ... QK_MOD_TAP_MAX:
    case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
    case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
      // Earlier return if this has not been considered tapped yet
      if (record->tap.count == 0) {
        return true;
      }
      keycode = keycode & 0xFF;
      break;
    default:
      break;
  }
  return keycode;
}

bool should_preserve_lat_word(uint16_t base_keycode, const keyrecord_t *record) {
  switch (base_keycode) {
    // Keycodes which should not disable lat word mode
    case KC_A ... KC_Z:
    case KC_1 ... KC_0:
    case KC_UNDS:
    case KC_LSHIFT:
    case KC_RSHIFT:
    case KC_BSPC:
      return true;
  }
  return false;
}

bool process_lat_word(uint16_t keycode, const keyrecord_t *record, uint16_t lat_word_keycode) {
  // Handle the custom keycodes that go with this feature
  if (keycode == lat_word_keycode) {
    is_lat_word_on = true;
    switch_system_layout(_COLEMAK);
    return false;
  }
  // If the behavior isn't enabled and the keypress isn't a keycode to
  // toggle the behavior, allow QMK to handle the keypress as usual
  if (!is_lat_word_on) {
    return true;
  }
  const uint16_t base_keycode = extract_base_keycode(keycode, record);
  if (!should_preserve_lat_word(base_keycode, record)) {
    is_lat_word_on = false;
    switch_system_layout(_RUSSIAN);
  } else {
    // generate the corresponding keypress from _COLEMAK layer
    uint8_t r = record->event.key.row;
    uint8_t c = record->event.key.col;
    if (0 <= r && r < MATRIX_ROWS && 0 <= c && c < MATRIX_COLS) {
      const uint16_t new_kc = keymaps[_COLEMAK][r][c];
      // tap_code16(new_kc);
      if (record->event.pressed) {
        register_code16(new_kc);
      } else {
        unregister_code16(new_kc);
      }
      return false;
    }
  }

  // continue processing as usual
  return true;
}
