# s60-x

Parent: [keyboard-firmware-build-util](../../README.md)

Builds the s60-x firmware and uploads it.

Description of the keyboard from MassDrop: https://www.massdrop.com/buy/sentraq-60-diy-keyboard-kit/

Firmware for the S60-X keyboard: https://github.com/VinnyCordeiro/tmk_keyboard/blob/master/keyboard/s60-x/README.md

The instructions there state that you have to download install tooling
to upload to the firmware. This downloads and installs required system
packages such as dfu-programmer, and also checks out a copy of the
firmware.

You can use a different tmk firmware by changing the variables at the
top of the Makefile.

## Allow the user to store their own local keymaps

The user of this directory can store their own set of keymap files
without having to clone the entire tmk firmware directory just to add
them to that clone directory. The idea is that the user forks a copy
of this repository, and adds their own (no need to push it back to
this repo of course).  See Examples below.

## Local Keymaps

The following are local keymaps defined by this repository:

* [keymap_standard_capslockctrlswap.c](keymap_standard_capslockctrlswap.c): Same as tmk_keyboard/keyboard/s60-x/keymap_standard.c but with capslock and control key swapped.
* [keymap_spacefn_capslockctrlswap.c](keymap_spacefn_capslockctrlswap.c): Same as tmk_keyboard/keyboard/s60-x/keymap_spacefn.c but with capslock and control key swapped.
* [keymap_spacefn_capslockctrlswap_mousekeys.c](keymap_spacefn_capslockctrlswap_mousekeys.c): Same as keymap_spacefn_capslockctrlswap.c but with a mouse keys layer added.
* [keymap_spacefn_hjklarrow_capslockctrlswap_mousekeys.c]: Same as keymap_spacefn_capslockctrlswap_mousekeys.c, but with SpaceFN layer changed to have H, J, K, L be the left, down, up, and right arrow keys which is in alignment with the mouse keys mouse left, down, up, and right, respectively. I did this because I found it difficult, in heavy usage, to keep them separate in my head when using mouse keys and SpaceFN. PgDwn and PgUp also moved to the left side under D and F, respectively, because the left hand is mostly unused when the space bar is held down when the SpaceFN layer is active.

## Printing Side labels

For SpaceFN
([keymap_spacefn_capslockctrlswap.c](keymap_spacefn_capslockctrlswap.c)),
it is nice to have side labels on the keys (front side).

Open the avery_6240_grid_tiled_keycap_side_labels.svg file under
Inkscape and follow the directions there. An attempt was made to use a
fill color close to the color of my keys. Alter as you see fit.

These align to a grid for Avery 6240 labels.

See http://i.imgur.com/0Gdwp3J.jpg for a photo of the first keyboard I
did this on. That shows the space bar not reversed.

Later on, when I built my second Sentraq keyboard, I found my thumb
hit the edge of the spacebar, so I reversed it. Find a picture of the
second keyboard: http://i.imgur.com/i1PCgsn.jpg

## Build

Move to this directory then just run `make` like:

    $ make KEYMAP=your_chosen_key_map_here build load

This will install Ubuntu packages as needed, and load the firmware
(see examples below). This currently limited to Ubuntu, but might work
on some other Debian-based Linux variants.

Expect to see successful output of the form:

    .
    .
    .
    mkdir -p obj_S60-X_lufa/common
    Compiling C: ../../tmk_core/common/mousekey.c
    avr-gcc -c -mmcu=atmega32u4 -gdwarf-2 -DF_CPU=16000000UL -DINTERRUPT_CONTROL_ENDPOINT -DBOOTLOADER_SIZE=4096 -DF_USB=16000000UL -DARCH=ARCH_AVR8 -DUSB_DEVICE_ONLY -DUSE_FLASH_DESCRIPTORS -DUSE_STATIC_OPTIONS="(USB_DEVICE_OPT_FULLSPEED | USB_OPT_REG_ENABLED | USB_OPT_AUTO_PLL)" -DFIXED_CONTROL_ENDPOINT_SIZE=8  -DFIXED_NUM_CONFIGURATIONS=1 -DPROTOCOL_LUFA -DBOOTMAGIC_ENABLE -DMOUSEKEY_ENABLE -DMOUSE_ENABLE -DEXTRAKEY_ENABLE -DCONSOLE_ENABLE -DCOMMAND_ENABLE -DVERSION=0f2963a -Os -funsigned-char -funsigned-bitfields -ffunction-sections -fdata-sections -fno-inline-small-functions -fpack-struct -fshort-enums -fno-strict-aliasing -Wall -Wstrict-prototypes -Wa,-adhlns=obj_S60-X_lufa/common/mousekey.lst -I. -I../../tmk_core -I../../tmk_core/protocol/lufa -I../../tmk_core/protocol/lufa/LUFA-git -I../../tmk_core/common -std=gnu99 -include config.h -MMD -MP -MF .dep/obj_S60-X_lufa_common_mousekey.o.d  ../../tmk_core/common/mousekey.c -o obj_S60-X_lufa/common/mousekey.o 
    
    mkdir -p obj_S60-X_lufa/common
    Compiling C: ../../tmk_core/common/command.c
    avr-gcc -c -mmcu=atmega32u4 -gdwarf-2 -DF_CPU=16000000UL -DINTERRUPT_CONTROL_ENDPOINT -DBOOTLOADER_SIZE=4096 -DF_USB=16000000UL -DARCH=ARCH_AVR8 -DUSB_DEVICE_ONLY -DUSE_FLASH_DESCRIPTORS -DUSE_STATIC_OPTIONS="(USB_DEVICE_OPT_FULLSPEED | USB_OPT_REG_ENABLED | USB_OPT_AUTO_PLL)" -DFIXED_CONTROL_ENDPOINT_SIZE=8  -DFIXED_NUM_CONFIGURATIONS=1 -DPROTOCOL_LUFA -DBOOTMAGIC_ENABLE -DMOUSEKEY_ENABLE -DMOUSE_ENABLE -DEXTRAKEY_ENABLE -DCONSOLE_ENABLE -DCOMMAND_ENABLE -DVERSION=0f2963a -Os -funsigned-char -funsigned-bitfields -ffunction-sections -fdata-sections -fno-inline-small-functions -fpack-struct -fshort-enums -fno-strict-aliasing -Wall -Wstrict-prototypes -Wa,-adhlns=obj_S60-X_lufa/common/command.lst -I. -I../../tmk_core -I../../tmk_core/protocol/lufa -I../../tmk_core/protocol/lufa/LUFA-git -I../../tmk_core/common -std=gnu99 -include config.h -MMD -MP -MF .dep/obj_S60-X_lufa_common_command.o.d  ../../tmk_core/common/command.c -o obj_S60-X_lufa/common/command.o 
    
    Linking: S60-X_lufa.elf
    avr-gcc -mmcu=atmega32u4 -gdwarf-2 -DF_CPU=16000000UL -DINTERRUPT_CONTROL_ENDPOINT -DBOOTLOADER_SIZE=4096 -DF_USB=16000000UL -DARCH=ARCH_AVR8 -DUSB_DEVICE_ONLY -DUSE_FLASH_DESCRIPTORS -DUSE_STATIC_OPTIONS="(USB_DEVICE_OPT_FULLSPEED | USB_OPT_REG_ENABLED | USB_OPT_AUTO_PLL)" -DFIXED_CONTROL_ENDPOINT_SIZE=8  -DFIXED_NUM_CONFIGURATIONS=1 -DPROTOCOL_LUFA -DBOOTMAGIC_ENABLE -DMOUSEKEY_ENABLE -DMOUSE_ENABLE -DEXTRAKEY_ENABLE -DCONSOLE_ENABLE -DCOMMAND_ENABLE -DVERSION=0f2963a -Os -funsigned-char -funsigned-bitfields -ffunction-sections -fdata-sections -fno-inline-small-functions -fpack-struct -fshort-enums -fno-strict-aliasing -Wall -Wstrict-prototypes -Wa,-adhlns=S60-X_lufa.elf -I. -I../../tmk_core -I../../tmk_core/protocol/lufa -I../../tmk_core/protocol/lufa/LUFA-git -I../../tmk_core/common -std=gnu99 -include config.h -MMD -MP -MF .dep/S60-X_lufa.elf.d  obj_S60-X_lufa/keymap_standard.o obj_S60-X_lufa/keymap_common.o obj_S60-X_lufa/matrix.o obj_S60-X_lufa/led.o obj_S60-X_lufa/protocol/lufa/lufa.o obj_S60-X_lufa/protocol/lufa/descriptor.o obj_S60-X_lufa/protocol/lufa/LUFA-git/LUFA/Drivers/USB/Class/Common/HIDParser.o obj_S60-X_lufa/protocol/lufa/LUFA-git/LUFA/Drivers/USB/Core/AVR8/Device_AVR8.o obj_S60-X_lufa/protocol/lufa/LUFA-git/LUFA/Drivers/USB/Core/AVR8/EndpointStream_AVR8.o obj_S60-X_lufa/protocol/lufa/LUFA-git/LUFA/Drivers/USB/Core/AVR8/Endpoint_AVR8.o obj_S60-X_lufa/protocol/lufa/LUFA-git/LUFA/Drivers/USB/Core/AVR8/Host_AVR8.o obj_S60-X_lufa/protocol/lufa/LUFA-git/LUFA/Drivers/USB/Core/AVR8/PipeStream_AVR8.o obj_S60-X_lufa/protocol/lufa/LUFA-git/LUFA/Drivers/USB/Core/AVR8/Pipe_AVR8.o obj_S60-X_lufa/protocol/lufa/LUFA-git/LUFA/Drivers/USB/Core/AVR8/USBController_AVR8.o obj_S60-X_lufa/protocol/lufa/LUFA-git/LUFA/Drivers/USB/Core/AVR8/USBInterrupt_AVR8.o obj_S60-X_lufa/protocol/lufa/LUFA-git/LUFA/Drivers/USB/Core/ConfigDescriptors.o obj_S60-X_lufa/protocol/lufa/LUFA-git/LUFA/Drivers/USB/Core/DeviceStandardReq.o obj_S60-X_lufa/protocol/lufa/LUFA-git/LUFA/Drivers/USB/Core/Events.o obj_S60-X_lufa/protocol/lufa/LUFA-git/LUFA/Drivers/USB/Core/HostStandardReq.o obj_S60-X_lufa/protocol/lufa/LUFA-git/LUFA/Drivers/USB/Core/USBTask.o obj_S60-X_lufa/common/host.o obj_S60-X_lufa/common/keyboard.o obj_S60-X_lufa/common/action.o obj_S60-X_lufa/common/action_tapping.o obj_S60-X_lufa/common/action_macro.o obj_S60-X_lufa/common/action_layer.o obj_S60-X_lufa/common/action_util.o obj_S60-X_lufa/common/print.o obj_S60-X_lufa/common/debug.o obj_S60-X_lufa/common/util.o obj_S60-X_lufa/common/avr/suspend.o obj_S60-X_lufa/common/avr/xprintf.o obj_S60-X_lufa/common/avr/timer.o obj_S60-X_lufa/common/avr/bootloader.o obj_S60-X_lufa/common/keymap.o obj_S60-X_lufa/common/bootmagic.o obj_S60-X_lufa/common/avr/eeconfig.o obj_S60-X_lufa/common/mousekey.o obj_S60-X_lufa/common/command.o --output S60-X_lufa.elf -Wl,-Map=S60-X_lufa.map,--cref -Wl,--gc-sections     -lm 
    
    Creating load file for Flash: S60-X_lufa.hex
    avr-objcopy -O ihex -R .eeprom -R .fuse -R .lock -R .signature S60-X_lufa.elf S60-X_lufa.hex
    
    Creating load file for EEPROM: S60-X_lufa.eep
    avr-objcopy -j .eeprom --set-section-flags=.eeprom="alloc,load" \
    --change-section-lma .eeprom=0 --no-change-warnings -O ihex S60-X_lufa.elf S60-X_lufa.eep || exit 0
    
    Creating Extended Listing: S60-X_lufa.lss
    avr-objdump -h -S -z S60-X_lufa.elf > S60-X_lufa.lss
    
    Creating Symbol Table: S60-X_lufa.sym
    avr-nm -n S60-X_lufa.elf > S60-X_lufa.sym
    
    Size after:
       text	   data	    bss	    dec	    hex	filename
      20876	     50	    162	  21088	   5260	S60-X_lufa.elf
    
    -------- end --------
    
    make[1]: Leaving directory '/home/someuser/bgoodr/keyboard-firmware-build-util/s60-x/tmk_keyboard/keyboard/s60-x'

## Examples

You can store your keymap_*.c files into the current working directory
and they will get picked up by the build. An example is checked in
here, keymap_standard_capslockctrlswap.c, that swaps the caps lock and control
keys, but is otherwise identical to
tmk_keyboard/keyboard/s60-x/keymap_standard.c.  

    sleep 5; make KEYMAP=standard_capslockctrlswap build load

The above sleeps for 5 seconds, giving you enough time to press the
reset button (puts the microcontroller into DFU bootloader mode, ready
to receive the firmware from the dfu-programmer), and builds the
keymap_standard_capslockctrlswap.c file that happens to be loaded in the current
working directory, and loads it into the keyboard.

I have found on Ubuntu that I sometimes have to unplug and plug back
in the USB cable, as otherwise you will get a "not present" error from
dfu-programmer.

    sleep 5; make KEYMAP=standard build load

Does the samething as the previous example, but builds the
keymap_standard.c file that is maintained in the firmware directory
(see firmware_subdir variable in the Makefile).

## Helpful Resources

 1. Introduction to the TMK Firmware: http://blog.roastpotatoes.co/2015/03/30/introduction-to-the-tmk-firmware/
 1. Definitions of certain macros: ACTION_LAYER_MOMENTARY, ACTION_LAYER_TOGGLE, and ACTION_LAYER_TAP_KEY: https://deskthority.net/workshop-f7/how-to-build-your-very-own-keyboard-firmware-t7177.html#p141386

