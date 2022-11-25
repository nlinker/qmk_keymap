#pragma once

/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Apply the modifier on keys that are tapped during a short hold of a modtap
#define PERMISSIVE_HOLD

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

#undef TAPPING_TERM
#define TAPPING_TERM 200

// Make X and > to be easier triggered
#define TAPPING_TERM_PER_KEY

#define USB_SUSPEND_WAKEUP_DELAY 0
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 100

#define FIRMWARE_VERSION u8"gqXJ4/GXd73"
#define RAW_USAGE_PAGE 0xFF60
#define RAW_USAGE_ID 0x61
#define LAYER_STATE_8BIT
#define RGB_MATRIX_STARTUP_SPD 60

#define COMBO_COUNT 1
#define COMBO_TERM 50        // how quickly all combo keys must be pressed in succession to trigger
#define COMBO_MUST_HOLD_MODS // if a combo triggers a modifier, only trigger when the combo is held
#define COMBO_HOLD_TERM 175  // how long at least one of the combo keys must be held to trigger