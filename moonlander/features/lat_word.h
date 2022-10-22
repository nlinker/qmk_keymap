#pragma once

#include "quantum.h"

#ifdef __cplusplus
extern "C" {
#endif

bool process_lat_word(uint16_t keycode, const keyrecord_t *record, uint16_t lat_word_keycode);

/**
 * The symbols controlling the mode are defined in the function.
 */
bool should_terminate_lat_word(uint16_t keycode, const keyrecord_t *record);

/**
 * Switch to the specific language in the host system, corresponding to the layer passed as the parameter.
 * @param the_layer the host system should be switched to the language that corresponds to the layer
 */
void switch_system_layout(uint8_t the_layer);


#ifdef __cplusplus
}
#endif
