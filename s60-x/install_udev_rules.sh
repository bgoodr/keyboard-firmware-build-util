#!/bin/bash

# Reference "Linux udev rules" section of https://github.com/tmk/tmk_keyboard/wiki/FAQ-Build

firmware_subdir="$1"
if [ -z "$firmware_subdir" ]
then
  echo "ERROR: USAGE: $0 firmware_subdir"
  exit 1
fi
do_clean="$2"

udev_rule_file1=/etc/udev/rules.d/50-atmel-dfu.rules
udev_rule_file2=/etc/udev/rules.d/52-tmk-keyboard.rules

if [ "$do_clean" = clean ]
then
  sudo rm -f $udev_rule_file1 $udev_rule_file2
  exit $?
fi

# When you click the reset button, lsusb output will show:
#
#    $ lsusb
#    ...
#    Bus 001 Device 040: ID 03eb:2ff4 Atmel Corp. atmega32u4 DFU bootloader
#    ...
#
# The VENDOR_ID and PRODUCT_ID listed there is for the DFU booloader,
# and not the id of the keyboard firmware when it gets loaded. See the
# config.h file for the values you will see when it is programmed.
#
if [ ! -f $udev_rule_file1 -o "$UDEV_RULE_FILE1_OVERWRITE_FORCE" = 1 ]
then
  echo
  echo "Executing sudo to update $udev_rule_file1 ..."
  echo
  sudo sh -c "cat > $udev_rule_file1" <<EOF
# Atmel ATMega32U4
SUBSYSTEMS=="usb", ATTRS{idVendor}=="03eb", ATTRS{idProduct}=="2ff4", MODE:="0666"
# Atmel USBKEY AT90USB1287
SUBSYSTEMS=="usb", ATTRS{idVendor}=="03eb", ATTRS{idProduct}=="2ffb", MODE:="0666"
# Atmel ATMega32U2
SUBSYSTEMS=="usb", ATTRS{idVendor}=="03eb", ATTRS{idProduct}=="2ff0", MODE:="0666"
EOF

 
fi

if [ ! -f $udev_rule_file2 -o "$UDEV_RULE_FILE1_OVERWRITE_FORCE" = 1 ]
then
  echo
  echo "Executing sudo to update $udev_rule_file2 ..."
  echo

  # My guess, and it is a wild guess, is that this next udev rule is
  # for hid_listen. See
  # https://github.com/tmk/tmk_keyboard/wiki/FAQ#linux-or-unix-like-system-requires-super-user-privilege
  sudo sh -c "cat > $udev_rule_file2" <<EOF
# tmk keyboard products     https://github.com/tmk/tmk_keyboard
SUBSYSTEMS=="usb", ATTRS{idVendor}=="feed", MODE:="0666"
EOF
  
fi
