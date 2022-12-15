#pragma once

#include "quantum.h"

#ifdef __cplusplus
extern "C" {
#endif

enum SwitchState {
    SS_OFF,
    SS_PENDING,
    SS_ON,
};

extern enum SwitchState switch_state;
/**
 *
 * @param keycode the current keycode
 * @param record the current keyrecord
 * @param state layer state that was recorded by `layer_state_set_user(layer_state_t state)`
 * @return true, if the key processing should go as usual
 */
bool process_hotkey_conversion(uint16_t keycode, keyrecord_t *record, layer_state_t state);

/**
 * Switch to the specific language in the host system, corresponding to the layer passed as the parameter.
 * @param the_layer the host system should be switched to the language that corresponds to the layer
 */
void switch_system_layout(uint8_t the_layer);

#ifdef __cplusplus
}
#endif
