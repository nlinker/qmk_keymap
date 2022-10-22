#include "lat_word.h"
#include "my_layers.h"

static bool is_lat_word_on = false;

bool process_lat_word(uint16_t keycode, const keyrecord_t *record, uint16_t lat_word_keycode) {
  // Nothing in this function acts on key release
  if (!record->event.pressed) {
    return true;
  }

  // Handle the custom keycodes that go with this feature
  if (keycode == lat_word_keycode) {
    switch_system_layout(_COLEMAK);
    return false;
  }

  // If the behavior isn't enabled and the keypress isn't a keycode to
  // toggle the behavior, allow QMK to handle the keypress as usual
  if (!is_lat_word_on) {
    return true;
  }

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

  if (should_terminate_lat_word(keycode, record)) {
    switch_system_layout(_RUSSIAN);
  }

  return true;
}


bool should_terminate_lat_word(uint16_t keycode, const keyrecord_t *record) {
  switch (keycode) {
    // Keycodes which should not disable caps word mode
    case KC_A ... KC_Z:
    case KC_1 ... KC_0:
    case KC_UNDS:
    case KC_BSPC:
      return false;

    default:
      if (record->event.pressed) {
        return true;
      }
      return false;
  }

  // Should be unreachable
  return false;
}

void switch_system_layout(uint8_t the_layer) {
  // Here goes the workaround, since Shift+Caps turns Caps on, not switches the language
  const uint8_t mods = get_mods() | get_oneshot_mods();
  const bool is_shift_pressed = mods & MOD_MASK_SHIFT;
  if (is_shift_pressed) {
    unregister_code(KC_LSHIFT);
    tap_code(KC_CAPS);
    register_code(KC_LSHIFT);
  } else {
    tap_code(KC_CAPS);
  }
}
