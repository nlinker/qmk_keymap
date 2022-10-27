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



## Layout Screenshots

<img src="img/0_colemak.png" width="768">
<img src="img/1_russian.png" width="768">
<img src="img/2_nav.png" width="768">
<img src="img/3_num.png" width="768">
<img src="img/4_sym.png" width="768">
<img src="img/5_mouse.png" width="768">
<img src="img/6_qwerty.png" width="768">
<img src="img/7_plover.png" width="768">
