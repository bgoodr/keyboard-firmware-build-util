#!/bin/bash

# This script allows us to maintain our own local copies of keymap
# files outside of the firmware directory by creating symbolic links
# to them:

firmware_subdir="$1"
op="$2"
reldots=$(echo $firmware_subdir | sed -e 's%/$%%g' -e 's%[^/][^/]*%..%g')

for local_keymap_file in keymap_*.c
do
  if [ ! -h $firmware_subdir/$local_keymap_file ]
  then
    if [ "$op" = clean ]
    then
      rm -f $firmware_subdir/$local_keymap_file
    else
      ln -s $reldots/$local_keymap_file $firmware_subdir/$local_keymap_file
    fi
  fi
done
