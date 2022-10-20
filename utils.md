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
