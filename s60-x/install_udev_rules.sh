#!/bin/bash

# Reference "Linux udev rules" section of https://github.com/tmk/tmk_keyboard/wiki/FAQ-Build

keyboard_subdir="$1"
if [ -z "$keyboard_subdir" ]
then
  echo "ERROR: USAGE: $0 KEYBOARD_SUBDIR"
  exit 1
fi

# I am utterly confused by this. The VENDOR_ID and PRODUCT_ID listed
# in the config.h do not match what I see when I click the reset
# button while tailing /var/log/syslog like this:
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
# So this means we should not use the vendor id and product id from the file as I thought, which means commenting out this:
#
#     VENDOR_ID=$(sed -n 's%^# *define *VENDOR_ID *0x\(.*\) *$%\1%gp' $keyboard_subdir/config.h)
#     echo "VENDOR_ID==\"${VENDOR_ID}\""
#     PRODUCT_ID=$(sed -n 's%^# *define *PRODUCT_ID *0x\(.*\) *$%\1%gp' $keyboard_subdir/config.h)
#     echo "PRODUCT_ID==\"${PRODUCT_ID}\""
#
# and instead doing this which matches what we see in the "Linux udev
# rules" section of https://github.com/tmk/tmk_keyboard/wiki/FAQ-Build
# in the first place:
#
VENDOR_ID=03eb
echo "VENDOR_ID==\"${VENDOR_ID}\""
PRODUCT_ID=2ff4
echo "PRODUCT_ID==\"${PRODUCT_ID}\""

udev_rule_file=/etc/udev/rules.d/50-atmel-dfu.rules
if [ ! -f $udev_rule_file -o "$UDEV_RULE_FILE_OVERWRITE_FORCE" = 1 ]
then
  echo
  echo "Executing sudo to update $udev_rule_file ..."
  echo
  sudo sh -c "cat > $udev_rule_file" <<EOF
# Atmel ATMega32U4
SUBSYSTEMS=="usb", ATTRS{idVendor}=="$VENDOR_ID", ATTRS{idProduct}=="$PRODUCT_ID", MODE:="0666"
EOF

  # Currently we are not certain the other rules listed in the "Linux
  # udev rules" section of
  # https://github.com/tmk/tmk_keyboard/wiki/FAQ-Build are needed so
  # they were omited.
  
fi
