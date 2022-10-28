# Nick's layout

Derived from configuration in 
[Oryx](https://configure.zsa.io/moonlander/layouts/gqXJ4/latest/0)

This layout uses 56 keys only and fits to Iris rev4 keyboard.

The most notable features are:
- Colemak-DH on the base layer, Qwerty is possible
- Ctrl and Alt modifiers are on the home row; however they are implemented as combos on the base layer. The reason
  is that the usual Mod Taps feature makes the keyboard feels like laggy and not immediately responsive. The feature
  also requires to select and get used to the timings. I used Mod Taps on the NUM layer only, since digits are
  typed with more care and slower than text. 
- There are paired Shift keys, they are explicitly dedicated and never overloaded.
  The usage of the dedicated Shift keys greatly reduces the number of errors when typing text.
- Underscore is the default, `-` can be obtained either with Shift, or using Symbol layer 
- Buffer operations duplicated on the NAV layer on the right half, Ctrl+X is implemented as the chord (Ctrl+C, Ctrl+V)
- NAV layer is accessible with the most ease and contains not only cursor moves, 
  but buffer operations, word selections, modifiers and other helpers
- NUM layer is accessible with the most ease as well and contains not only digits, but Fn keys
- MOUSE layer is enabled with NAV and NUM modifiers pressed simultaneously
- SYM layer is accessible with home row pinkies hold, and is synchronized with the base layer; 
  this means the base symbols correspond to the shifted ones on the Symbol layer, it simplifies the layout remembering
- Combos for the Colemak layer:
  - `LCtrl = T + S`, `LAlt = S + R`, `LCtrl + LAlt = T + S + R`     
  - `RCtrl = N + E`, `LAlt = E + I`, `RCtrl + LAlt = N + E + I`     
- Combos for the Russian layer:
  - `LCtrl = А + В`, `LAlt = В + Ы`, `LCtrl + LAlt = А + В + Ы`
  - `RCtrl = О + Л`, `LAlt = Л + Д`, `RCtrl + LAlt = О + Л + Д`

- Hotkeys and symbols don't depend on the English/Russian system layout, achieved with `hotkey_conv` module.

## Installation

Clone [`ZSA QMK fork`](https://github.com/zsa/qmk_firmware), and there `firmware21` branch.
**TODO**

## Integration with `hotkey_conv` and/or `layer_lock`

The description of the `layer_lock` module is [done by its author, Pascal Getreuer](https://getreuer.info/posts/keyboards/layer-lock/index.html)
The description of the `hotkey_conv` module goes below.

## Hotkey conversion

People use not only languages with Latin letters, and the way OSes propose to work with other languages is to use
system layouts. I.e. if one writes something in English and then decides to switch to Russian (e.g. to answer to a
friend in a social network), he needs to press a keyboard shortcut to switch the system layout to Russian, and then
it presses the usual buttons on the keyboard, but instead of, say, `a` (assume it is Qwerty layout) the `ф` is being
entered. Now imagine the user wants to issue a hotkey in the text box, say, select all the text, so he presses `Ctrl+a`.
But the system is switched to the Russian layout already and instead obtains `Ctrl+ф` instead and the hotkey fails. 
Some applications do the translation, assuming we use Qwerty layout, some just ignore the hotkeys.

The thing gets much more complicated, when the one decides to learn Colemak layout to 
[increase his efficiency](https://typingdonewell.com/blog/qwerty-vs-dvorak-vs-colemak-detailed-comparison-with-my-tests/) 
and reduce the strain that was put on his hands. Then hotkeys are moved to the new positions, e.g. `Ctrl+p` moves from 
right pinky to the left pointer finger, but the user eventually gets used to them. The Russian layout, however,
is interpreted (if interpreted!) as mirror of the Qwerty layout, and the hotkeys get absolutely broken, the user
has to switch layout back to English, so he can issue even single hotkey and then has to switch to the Russian layout
again to continue typing his letter to the friend. So inconvenient!

So the approach I want to present is the following (QMK firmware is required, of course):

1. Do not touch the system, it should think the English layout is Qwerty and the Russian layout is Йцукен. The only 
change recommended is to make the shortcut between the languages to be `CapsLock` (but it is not mandatory).    
2. Create the separate layer in the keyboard, that contains Russian letters.
3. Implement the language switch keycode.
4. Add `hotkey_conv` to the firmware code. 
5. Add the `process_hotkey_conversion` call to the `keymap.c`.
6. Fix the errors.

### Implementing the language switch keycode.

### Adding `hotkey_conv` to the firmware code.

1. Create `features` dir in your firmware code, and copy `hotkey_conv.h` and `hotkey_conv.c` there.
2. Add the line `SRC += features/hotkey_conv.c` to the `rules.mk`.

### Adding the `process_hotkey_conversion` call to the `keymap.c`

### Fixing the errors

The most funny part goes here

## Layout Screenshots

<img src="img/0_colemak.png" width="768">
<img src="img/1_russian.png" width="768">
<img src="img/2_nav.png" width="768">
<img src="img/3_num.png" width="768">
<img src="img/4_mouse.png" width="768">
<img src="img/5_sym.png" width="768">
<img src="img/6_qwerty.png" width="768">
<img src="img/7_plover.png" width="768">
