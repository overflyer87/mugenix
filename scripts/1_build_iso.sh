#!/bin/bash

OSDEVPTH=/mnt/ssd_data/git/mugenix

rm $OSDEVPTH/isodir/mugenix.iso
mkdir -p $OSDEVPTH/isodir/boot/grub
grub-mkrescue -o $OSDEVPTH/isodir/mugenix.iso $OSDEVPTH/isodir
