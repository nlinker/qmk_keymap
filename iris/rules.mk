# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
ENCODER_ENABLE = no
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
ORYX_ENABLE = no
RGB_MATRIX_CUSTOM_KB = no
STENO_ENABLE = yes
STENO_PROTOCOL = geminipr
KEYBOARD_SHARED_EP = yes
SPACE_CADET_ENABLE = no
CAPS_WORD_ENABLE = yes
COMBO_ENABLE = yes
MOUSEKEY_ENABLE = yes
DEFERRED_EXEC_ENABLE = yes  # for A_ATAB behavior
KEY_OVERRIDE_ENABLE = yes # for shift + underscore -> minus

SRC = matrix.c
SRC += features/hotkey_conv.c
SRC += features/layer_lock.c
