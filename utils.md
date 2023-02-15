### Indentation

```
                 K
                 K
                 K
                                 K
                                 K
```

### Text representation

```
$ qmk info -kb moonlander -m
Keyboard Name: Moonlander Mark I
Manufacturer: ZSA Technology Labs
Website: zsa.io/moonlander
Maintainer: ZSA via Drashna
Keyboard Folder: moonlander
Layouts: LAYOUT_moonlander
Processor: STM32F303
Bootloader: stm32-dfu
Matrix for "LAYOUT_moonlander":
            ┌──┐                                    ┌──┐
        ┌──┐│0D│┌──┐┌──┐┌──┐            ┌──┐┌──┐┌──┐│6D│┌──┐
┌──┐┌──┐│0C│└──┘│0E││0F││0G│            │6A││6B││6C│└──┘│6E│┌──┐┌──┐
│0A││0B│└──┘┌──┐└──┘└──┘└──┘            └──┘└──┘└──┘┌──┐└──┘│6F││6G│
└──┘└──┘┌──┐│1D│┌──┐┌──┐┌──┐            ┌──┐┌──┐┌──┐│7D│┌──┐└──┘└──┘
┌──┐┌──┐│1C│└──┘│1E││1F││1G│            │7A││7B││7C│└──┘│7E│┌──┐┌──┐
│1A││1B│└──┘┌──┐└──┘└──┘└──┘            └──┘└──┘└──┘┌──┐└──┘│7F││7G│
└──┘└──┘┌──┐│2D│┌──┐┌──┐┌──┐            ┌──┐┌──┐┌──┐│8D│┌──┐└──┘└──┘
┌──┐┌──┐│2C│└──┘│2E││2F││2G│            │8A││8B││8C│└──┘│8E│┌──┐┌──┐
│2A││2B│└──┘┌──┐└──┘└──┘└──┘            └──┘└──┘└──┘┌──┐└──┘│8F││8G│
└──┘└──┘┌──┐│3D│┌──┐┌──┐                    ┌──┐┌──┐│9D│┌──┐└──┘└──┘
┌──┐┌──┐│3C│└──┘│3E││3F│                    │9B││9C│└──┘│9E│┌──┐┌──┐
│3A││3B│└──┘┌──┐└──┘└──┘                    └──┘└──┘┌──┐└──┘│9F││9G│
└──┘└──┘┌──┐│4D│┌──┐                            ┌──┐│AD│┌──┐└──┘└──┘
┌──┐┌──┐│4C│└──┘│4E│┌──────┐            ┌──────┐│AC│└──┘│AE│┌──┐┌──┐
│4A││4B│└──┘    └──┘│5D    │            │BD    │└──┘    └──┘│AF││AG│
└──┘└──┘            └──────┘            └──────┘            └──┘└──┘
                    ┌──┐┌──┐┌──┐    ┌──┐┌──┐┌──┐
                    │5A││5B││5C│    │BE││BF││BG│
                    │  ││  ││  │    │  ││  ││  │
                    │  ││  ││  │    │  ││  ││  │
                    └──┘└──┘└──┘    └──┘└──┘└──┘
```

### Console output

Insert somewhere in `keymap.c`
```c
#ifdef CONSOLE_ENABLE
    uprintf(
        "this_kc:0x%04X, new_kc:0x%04X, row:%3u, col:%3u, pressed:%u, ru_layer:%d ru_layer_ex:%d shift:%d\n",
        keycode, new_kc, r, c, record->event.pressed, is_ru_layer, is_ru_layer_exact, is_shift_pressed
    );
#endif
```
then open the console
```bash
$ qmk console
```

### Combos

... that were used to be used.
```c
const uint16_t PROGMEM combo_ts[] = { KC_T, KC_S, COMBO_END };
const uint16_t PROGMEM combo_sr[] = { KC_S, KC_R, COMBO_END };
const uint16_t PROGMEM combo_tsr[] = { KC_T, KC_S, KC_R, COMBO_END };
const uint16_t PROGMEM combo_ne[] = { KC_N, KC_E, COMBO_END };
const uint16_t PROGMEM combo_ei[] = { KC_E, KC_I, COMBO_END };
const uint16_t PROGMEM combo_nei[] = { KC_N, KC_E, KC_I, COMBO_END };
const uint16_t PROGMEM combo_ru_ts[] = { RU_A, RU_VE, COMBO_END };
const uint16_t PROGMEM combo_ru_sr[] = { RU_VE, RU_YERU, COMBO_END };
const uint16_t PROGMEM combo_ru_tsr[] = { RU_A, RU_VE, RU_YERU, COMBO_END };
const uint16_t PROGMEM combo_ru_ne[] = { RU_O, RU_EL, COMBO_END };
const uint16_t PROGMEM combo_ru_ei[] = { RU_EL, RU_DE, COMBO_END };
const uint16_t PROGMEM combo_ru_nei[] = { RU_O, RU_EL, RU_DE, COMBO_END };

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_ts, KC_LCTL),
    COMBO(combo_sr, KC_LALT),
    COMBO(combo_tsr, LCTL(KC_LALT)),
    COMBO(combo_ne, KC_RCTL),
    COMBO(combo_ei, KC_LALT),
    COMBO(combo_nei, RCTL(KC_LALT)),
    COMBO(combo_ru_ts, KC_LCTL),
    COMBO(combo_ru_sr, KC_LALT),
    COMBO(combo_ru_tsr, LCTL(KC_LALT)),
    COMBO(combo_ru_ne, KC_RCTL),
    COMBO(combo_ru_ei, KC_LALT),
    COMBO(combo_ru_nei, RCTL(KC_LALT)),
};
```

### Interpret double shift as Sym layer switch

```c
//    case KC_LSHIFT:
//    case KC_RSHIFT:
//      const uint8_t mods = get_mods() | get_oneshot_mods();
//      if ((mods & MOD_MASK_SHIFT)) {
//        ...        
//      }
//      if (record->event.pressed) {
//        layer_on(_SYM);
//      } else {
//        layer_off(_SYM);
//      } 
//      break;
//
```

### Monkeytype get word list

```javascript
import $ from 'jquery'
message = $('#words > .word').map((_, it) => $(it).children().text()).get().join(" ")
console.log(message)
```

### Print binary representation with padding

```c
static layer_state_t cur_state = 0;

static char cur_state_bin[33];
static char new_state_bin[33];
static char *padding = "..........................";

layer_state_t layer_state_set_user(layer_state_t new_state) {
  
    itoa(cur_state, cur_state_bin, 2);
    itoa(new_state, new_state_bin, 2);
    int pad_len_cur = 8 - strlen(cur_state_bin) < 0? 0: 8 - strlen(cur_state_bin);
    int pad_len_new = 8 - strlen(new_state_bin) < 0? 0: 8 - strlen(new_state_bin);
    uprintf("cur_state: [%*.*s%s], new_state: [%*.*s%s] \n", 
            pad_len_cur, pad_len_cur, padding, cur_state_bin,
            pad_len_new, pad_len_new, padding, new_state_bin);
}
```

### Checking layers

```c
bool is_new_nav = IS_LAYER_ON_STATE(new_state, _NAV);
bool is_new_fnn = IS_LAYER_ON_STATE(new_state, _FNN);
bool is_new_mouse = IS_LAYER_ON_STATE(new_state, _MOUSE);
bool is_new_sym = IS_LAYER_ON_STATE(new_state, _SYM);
bool is_cur_nav = IS_LAYER_ON_STATE(current_layer_state, _NAV);
bool is_cur_fnn = IS_LAYER_ON_STATE(current_layer_state, _FNN);
bool is_cur_mouse = IS_LAYER_ON_STATE(current_layer_state, _MOUSE);
bool is_cur_sym = IS_LAYER_ON_STATE(current_layer_state, _SYM);
bool is_cur_ru = IS_LAYER_ON_STATE(cur_state, _RUSSIAN);
bool is_new_ru = IS_LAYER_ON_STATE(new_state, _RUSSIAN);
```


### Key code translation

```c
  switch (keycode) {
    case KC_MINS   : // #define RU_MINS KC_MINS    // -
    case KC_EQL    : // #define RU_EQL  KC_EQL     // = 
    case KC_BSLS   : // #define RU_BSLS KC_BSLS    // (backslash)
    case S(KC_1)   : // #define RU_EXLM S(KC_1)    // ! !
    case S(KC_2)   : // #define RU_DQUO S(KC_2)    // " @
    case S(KC_3)   : // #define RU_NUM  S(KC_3)    // № #
    case S(KC_4)   : // #define RU_SCLN S(KC_4)    // ; $
    case S(KC_5)   : // #define RU_PERC S(KC_5)    // % %
    case S(KC_6)   : // #define RU_COLN S(KC_6)    // : ^
    case S(KC_7)   : // #define RU_QUES S(KC_7)    // ? &
    case S(KC_8)   : // #define RU_ASTR S(KC_8)    // * *
    case S(KC_9)   : // #define RU_LPRN S(KC_9)    // ( (
    case S(KC_0)   : // #define RU_RPRN S(KC_0)    // ) )
    case S(KC_MINS): // #define RU_UNDS S(KC_MINS) // _
    case S(KC_EQL) : // #define RU_PLUS S(KC_EQL)  // +
    case S(KC_BSLS): // #define RU_SLSH S(KC_BSLS) // /
    case KC_SLSH   : // #define RU_DOT  KC_SLSH    // .
    case S(KC_DOT) : // #define RU_COMM S(KC_DOT)  // ,

      itoa(cur_state, cur_state_bin, 2);
      int pad_len_cur = 8 - strlen(cur_state_bin) < 0? 0: 8 - strlen(cur_state_bin);
      uprintf("cur_state: [%*.*s%s] sys_lang_id: %d, keycode: %d, is_ru: %d\n", pad_len_cur, pad_len_cur, padding, cur_state_bin,
                system_language_id,
                keycode,
                is_ru
              );

      return true;
  }
```

### Switch Russian/English
                          
```c
switch (switch_keycode) {
  case L_RUS: {
    bool is_cur_ru = IS_LAYER_ON_STATE(cur_state, _RUSSIAN);
    if (is_cur_ru) {
      switch_system_layout(_RUSSIAN);
    } else {
      switch_system_layout(_COLEMAK);
    }
  }
}
```
