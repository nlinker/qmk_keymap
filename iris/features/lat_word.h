#pragma once

#include "quantum.h"

#ifdef __cplusplus
extern "C" {
#endif

bool process_lat_word(uint16_t keycode, const keyrecord_t *record, uint16_t lat_word_keycode);

#ifdef __cplusplus
}
#endif
