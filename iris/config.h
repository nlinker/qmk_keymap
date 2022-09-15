#pragma once

// #define USE_I2C
#define EE_HANDS
// #define NO_DEBUG
// #define NO_PRINT
// #define BACKLIGHT_BREATHING

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

#undef TAPPING_TERM
#define TAPPING_TERM 200

// Make X and > to be easier triggered
#define TAPPING_TERM_PER_KEY

// Apply the modifier on keys that are tapped during a short hold of a modtap
#define PERMISSIVE_HOLD

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

#define USB_SUSPEND_WAKEUP_DELAY 0
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 100

// TAPPING_TOGGLE x (count)
// If you hold a TT key down, layer is activated, and then is de-activated when
// you let go (like MO()). If you repeatedly tap it, the layer will be toggled
// on or off (like TG()). It needs 5 taps by default, but you can change this by
// defining TAPPING_TOGGLE to another number.
#define TAPPING_TOGGLE 1

#define RGB_MATRIX_STARTUP_SPD 60
