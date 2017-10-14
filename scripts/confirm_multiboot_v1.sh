#!/bin/bash

OSDEVPTH=/mnt/ssd_data/git/mugenix

if grub-file --is-x86-multiboot $OSDEVPTH/isodir/boot/kernel.bin; then
  echo multiboot confirmed
else
  echo the file is not multiboot
fi
