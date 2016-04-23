#!/bin/bash

# This script allows us to maintain our own local copies of keymap
# files outside of the firmware directory by creating symbolic links
# to them:

keyboard_subdir="$1"
op="$2"
reldots=$(echo $keyboard_subdir | sed -e 's%/$%%g' -e 's%[^/][^/]*%..%g')

for local_keymap_file in keymap_*.c
do
  if [ ! -h $keyboard_subdir/$local_keymap_file ]
  then
    if [ "$op" = clean ]
    then
      rm -f $keyboard_subdir/$local_keymap_file
    else
      ln -s $reldots/$local_keymap_file $keyboard_subdir/$local_keymap_file
    fi
  fi
done
