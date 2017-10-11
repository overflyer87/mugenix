#include "include/console.h"
#include "include/string.h"

static string vid_vga_txt_buf = (string)VGA_BUF_MEM_ADDRESS;
static uint8_t row;
static uint8_t col;

void cll(short from, short to) 
{
    for (row = 0; row < VGA_SCREEN_WIDTH_MAX; row++) {
        for (col = from; col < to; col++) {
            short pos = (col * VGA_SCREEN_WIDTH_MAX) + row;
            vid_vga_txt_buf[pos * 2] = 0x00;
        }
    }
	update_cursor(from, 0);
}


void cls(void)
{
    cll(0, (VGA_SCREEN_HEIGHT_MAX - 1));
	update_cursor(0, 0);
}


uint8_t inportb (uint16_t _port)
{
        uint8_t rv;
        __asm__ __volatile__ ("inb %1, %0" : "=a" (rv) : "dN" (_port));
        return rv;
}

void outportb (uint16_t _port, uint8_t _data)
{
    __asm__ __volatile__ ("outb %1, %0" : : "dN" (_port), "a" (_data));
}

void update_cursor(uint8_t row, uint8_t col)
{
    uint16_t tmp;
    tmp = row * VGA_SCREEN_WIDTH_MAX + col;
    outportb(0x3D4, 0xE);
    outportb(0x3D5, tmp >> 8);
    outportb(0x3D4, 0xF);
    outportb(0x3D5, tmp);
}

void printchar(char c, uint8_t row, uint8_t col) 
{
	uint16_t char_pos = ((row * VGA_SCREEN_WIDTH_MAX) + col) * 2;
	uint16_t color_pos = char_pos + 1; 

	vid_vga_txt_buf[char_pos] = c;
	vid_vga_txt_buf[color_pos] = VGA_COLOR_LIGHT_GREY;

}

void printstr(string str) 
{
	size_t len = strlen(str);
	size_t i;

	uint8_t row = 0;
	uint8_t col = 0;

	for (i = 0; i < len; i++) {
		printchar(str[i], 0, col++);
	}
}
