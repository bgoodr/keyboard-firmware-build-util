s60-x
=====

Parent: [keyboard-firmware-build-util](../../README.md)

Builds the s60-x firmware and uploads it.

Description of the keyboard from MassDrop: https://www.massdrop.com/buy/sentraq-60-diy-keyboard-kit/

Firmware for the S60-X keyboard://github.com/VinnyCordeiro/tmk_keyboard/tree/master/keyboard/s60-x

The instructions there state that you have to download install tooling
to upload to the firmware. This downloads and installs tooling that is
required including the firmware.

## Build

Move to this directory then just run `make` like:

    $ make

## Problems

This build fails out and I have yet to debug exactly why:

    mkdir -p obj_S60-X_lufa
    Compiling C: keymap_standard.c
    avr-gcc -c -mmcu=atmega32u4 -gdwarf-2 -DF_CPU=16000000UL -DINTERRUPT_CONTROL_ENDPOINT -DBOOTLOADER_SIZE=4096 -DF_USB=16000000UL -DARCH=ARCH_AVR8 -DUSB_DEVICE_ONLY -DUSE_FLASH_DESCRIPTORS -DUSE_STATIC_OPTIONS="(USB_DEVICE_OPT_FULLSPEED | USB_OPT_REG_ENABLED | USB_OPT_AUTO_PLL)" -DFIXED_CONTROL_ENDPOINT_SIZE=8  -DFIXED_NUM_CONFIGURATIONS=1 -DPROTOCOL_LUFA -DBOOTMAGIC_ENABLE -DMOUSEKEY_ENABLE -DMOUSE_ENABLE -DEXTRAKEY_ENABLE -DCONSOLE_ENABLE -DCOMMAND_ENABLE -DVERSION=0f2963a -Os -funsigned-char -funsigned-bitfields -ffunction-sections -fdata-sections -fno-inline-small-functions -fpack-struct -fshort-enums -fno-strict-aliasing -Wall -Wstrict-prototypes -Wa,-adhlns=obj_S60-X_lufa/keymap_standard.lst -I. -I../../tmk_core -I../../tmk_core/protocol/lufa -I../../tmk_core/protocol/lufa/LUFA-git -I../../tmk_core/common -std=gnu99 -include config.h -MMD -MP -MF .dep/obj_S60-X_lufa_keymap_standard.o.d  keymap_standard.c -o obj_S60-X_lufa/keymap_standard.o 
    In file included from keymap_common.h:20:0,
                     from keymap_standard.c:1:
    /usr/lib/gcc/avr/4.8.1/include/stdint.h:9:26: fatal error: stdint.h: No such file or directory
     # include_next <stdint.h>
                              ^
    compilation terminated.
    ../../tmk_core/rules.mk:550: recipe for target 'obj_S60-X_lufa/keymap_standard.o' failed
    make[1]: *** [obj_S60-X_lufa/keymap_standard.o] Error 1
    make[1]: Leaving directory '/home/brentg/bgoodr/keyboard-firmware-build-util/s60-x/tmk_keyboard/keyboard/s60-x'
    Makefile:30: recipe for target 'build' failed
    make: *** [build] Error 2

I would think the include_next would find the one coming from libc6-dev but that does not seem to be the case
