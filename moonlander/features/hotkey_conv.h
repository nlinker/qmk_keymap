#pragma once

#include "quantum.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Switch to the specific language in the host system, corresponding to the layer passed as the parameter.
 * @param the_layer the host system should be switched to the language that corresponds to the layer
 */
void switch_system_layout(uint8_t the_layer);

/**
 * Begin the conversion
 *
 * @param keycode the current keycode
 * @param record the current keyrecord
 * @param cur_state layer state that was recorded by `layer_state_set_user(layer_state_t state)`
 * @return true, if the key processing should go as usual
 */
bool process_hotkey_conversion(uint16_t keycode, keyrecord_t *record, layer_state_t cur_state);

#ifdef __cplusplus
}
#endif
