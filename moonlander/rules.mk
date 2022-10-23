# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
ENCODER_ENABLE = no
CONSOLE_ENABLE = yes
COMMAND_ENABLE = no
ORYX_ENABLE = no
STENO_ENABLE = yes
KEYBOARD_SHARED_EP = yes
SPACE_CADET_ENABLE = no
CAPS_WORD_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes
MOUSEKEY_ENABLE = yes
COMBO_ENABLE = yes

SRC = matrix.c
SRC += features/lat_word.c
SRC += features/layer_lock.c
SRC += features/short_conv.c
