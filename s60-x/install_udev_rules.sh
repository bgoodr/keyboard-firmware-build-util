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

# When you click the reset button,  the VENDOR_ID and PRODUCT_ID listed
# in the config.h will not match what you see in  /var/log/syslog which will be:
#
#    someuser@wilddog:~/bgoodr/keyboard-firmware-build-util/s60-x$ tail -1lf /var/log/syslog
#    Apr 20 22:22:07 wilddog kernel: [  600.913330] usb 1-2: SerialNumber: 1.0.0
#    Apr 20 22:22:33 wilddog kernel: [  627.227086] usb 1-2: USB disconnect, device number 9
#    Apr 20 22:22:33 wilddog kernel: [  627.727987] usb 1-2: new full-speed USB device number 10 using xhci_hcd
#    Apr 20 22:22:33 wilddog kernel: [  627.859101] usb 1-2: New USB device found, idVendor=03eb, idProduct=2ff4
#    Apr 20 22:22:33 wilddog kernel: [  627.859117] usb 1-2: New USB device strings: Mfr=1, Product=2, SerialNumber=3
#    Apr 20 22:22:33 wilddog kernel: [  627.859118] usb 1-2: Product: ATm32U4DFU
#    Apr 20 22:22:33 wilddog kernel: [  627.859119] usb 1-2: Manufacturer: ATMEL
#    Apr 20 22:22:33 wilddog kernel: [  627.859120] usb 1-2: SerialNumber: 1.0.0
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

  # The docs say to do this:  
  #
  #      sudo sh -c "cat > $udev_rule_file2" <<EOF
  #    # tmk keyboard products     https://github.com/tmk/tmk_keyboard
  #    SUBSYSTEMS=="usb", ATTRS{idVendor}=="feed", MODE:="0666"
  #    EOF
  #
  # But for the s60-x keyboard, I see this as lsusb output:
  #
  #   $ lsusb
  #   Bus 004 Device 001: ID 1d6b:0003 Linux Foundation 3.0 root hub
  #   Bus 003 Device 001: ID 1d6b:0002 Linux Foundation 2.0 root hub
  #   Bus 002 Device 001: ID 1d6b:0003 Linux Foundation 3.0 root hub
  #   Bus 001 Device 003: ID 051d:0002 American Power Conversion Uninterruptible Power Supply
  #   Bus 001 Device 009: ID f0da:0666  
  #   Bus 001 Device 004: ID 046d:c52f Logitech, Inc. Unifying Receiver
  #   Bus 001 Device 002: ID 046d:c318 Logitech, Inc. Illuminated Keyboard
  #   Bus 001 Device 001: ID 1d6b:0002 Linux Foundation 2.0 root hub
  #
  # Notice the blank line after f0da:0666. I reason that the values
  # are not correct and should instead match what is in the config.h
  # file. Therefore, try feeding the same value in config.h over into
  # the udev rule file:

  VENDOR_ID=$(sed -n 's%^# *define *VENDOR_ID *0x\(.*\) *$%\1%gp' $firmware_subdir/config.h)
  echo "VENDOR_ID==\"${VENDOR_ID}\""
  PRODUCT_ID=$(sed -n 's%^# *define *PRODUCT_ID *0x\(.*\) *$%\1%gp' $firmware_subdir/config.h)
  echo "PRODUCT_ID==\"${PRODUCT_ID}\""
  sudo sh -c "cat > $udev_rule_file2" <<EOF
# tmk keyboard products     https://github.com/tmk/tmk_keyboard
SUBSYSTEMS=="usb", ATTRS{idVendor}=="$VENDOR_ID", MODE:="$PRODUCT_ID"
EOF
#   sudo sh -c "cat > $udev_rule_file2" <<EOF
# # tmk keyboard products     https://github.com/tmk/tmk_keyboard
# SUBSYSTEMS=="usb", ATTRS{idVendor}=="feed", MODE:="0666"
# EOF
  
  
fi
