#!/bin/bash

TOOLBIN=/home/overflyer/opt/cross/bin
OSDEVPTH=/home/overflyer/mugenix

rm $OSDEVPTH/obj/*.o
rm $OSDEVPTH/isodir/boot/kernel.bin

$TOOLBIN/i386-elf-as $OSDEVPTH/src/boot.s -o $OSDEVPTH/obj/boot.o
$TOOLBIN/i386-elf-gcc -c $OSDEVPTH/src/kernel.c -o $OSDEVPTH/obj/kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
$TOOLBIN/i386-elf-gcc -c $OSDEVPTH/src/string.c -o $OSDEVPTH/obj/string.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
$TOOLBIN/i386-elf-gcc -c $OSDEVPTH/src/console.c -o $OSDEVPTH/obj/console.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
$TOOLBIN/i386-elf-gcc -T $OSDEVPTH/src/linker.ld -o $OSDEVPTH/isodir/boot/kernel.bin -ffreestanding -O2 -nostdlib $OSDEVPTH/obj/boot.o $OSDEVPTH/obj/kernel.o $OSDEVPTH/obj/string.o $OSDEVPTH/obj/console.o -lgcc
