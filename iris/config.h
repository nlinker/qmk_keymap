#pragma once

/*
  #define USE_I2C
  #define NO_PRINT
  #define BACKLIGHT_BREATHING
*/
#define EE_HANDS
#define PERMISSIVE_HOLD

#define QUICK_TAP_TERM 90

#define USB_SUSPEND_WAKEUP_DELAY 0
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 100


#define LAYER_STATE_8BIT
#define COMBO_COUNT 9

#define RGB_MATRIX_STARTUP_SPD 60
#define COMBO_MUST_HOLD_MODS // if a combo triggers a modifier, only trigger when the combo is held
#define COMBO_HOLD_TERM 150  // how long at least one of the combo keys must be held to trigger

