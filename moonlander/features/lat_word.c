#include "lat_word.h"
#include "my_layers.h"

static bool is_lat_word_on = false;
static uint8_t system_language_id = 0;

bool process_lat_word(uint16_t keycode, const keyrecord_t *record, uint16_t lat_word_keycode) {

  // Nothing in this function acts on key release
  if (!record->event.pressed) {
    return true;
  }

  // Handle the custom keycodes that go with this feature
  if (keycode == lat_word_keycode) {
    is_lat_word_on = true;
    uprintf(
        "enable lat_word, this_kc:0x%04X, sys_lang:%d, is_lat_word_on:%d\n",
        keycode, system_language_id, is_lat_word_on
    );
    return false;
  }

  // If the behavior isn't enabled and the keypress isn't a keycode to
  // toggle the behavior, allow QMK to handle the keypress as usual
  if (!is_lat_word_on) {
    return true;
  }

  if (!should_preserve_lat_word(keycode, record)) {
    is_lat_word_on = false;
    uprintf(
        "disable lat_word, this_kc:0x%04X, sys_lang:%d, is_lat_word_on:%d\n",
        keycode, system_language_id, is_lat_word_on
    );
  }

  // continue processing as usual
  return true;
}

bool should_preserve_lat_word(uint16_t keycode, const keyrecord_t *record) {
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
  switch (keycode) {
    // Keycodes which should not disable lat word mode
    case KC_A ... KC_Z:
    case KC_1 ... KC_0:
    case KC_UNDS:
    case KC_BSPC:
      return true;
  }
  return false;
}

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
