#!/bin/bash

OSDEVPTH=/home/overflyer/mugenix

rm $OSDEVPTH/isodir/mugenix.iso
mkdir -p $OSDEVPTH/isodir/boot/grub
grub-mkrescue -o $OSDEVPTH/isodir/mugenix.iso $OSDEVPTH/isodir
