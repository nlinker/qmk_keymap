/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/

#define PERMISSIVE_HOLD

#define ORYX_CONFIGURATOR
// When the user holds a key after tapping it, the tapping function is repeated by default,
// rather than activating the hold function. This allows keeping the ability to auto-repeat
// the tapping function of a dual-role key. QUICK_TAP_TERM enables fine tuning of that
// ability. If set to 0, it will remove the auto-repeat ability and activate the hold function instead.
#define QUICK_TAP_TERM 90

#define COMBO_MUST_HOLD_MODS // if a combo triggers a modifier, only trigger when the combo is held
#define COMBO_HOLD_TERM 150  // how long at least one of the combo keys must be held to trigger

#define USB_SUSPEND_WAKEUP_DELAY 0
#undef MOUSEKEY_TIME_TO_MAX
#define MOUSEKEY_TIME_TO_MAX 100

#define FIRMWARE_VERSION u8"Qm9Zm/bvgxW7"

#define SERIAL_NUMBER "Qm9Zm/bvgxW7"
#define LAYER_STATE_8BIT
#define COMBO_COUNT 8

#define RGB_MATRIX_STARTUP_SPD 60

