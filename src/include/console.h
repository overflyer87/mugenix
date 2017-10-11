#ifndef CONSOLE_H
#define CONSOLE_H

#include "typedef.h"

/* Hardware text mode constants. */
/*Text res: 80×25 	Char size: 9×16 	Screen res: 720×400 	16 colors 	Mode: VGA*/

#define VGA_SCREEN_WIDTH_MAX	80
#define VGA_SCREEN_HEIGHT_MAX	25
#define VGA_BUF_MEM_ADDRESS		0xB8000
#define	VGA_COLOR_BLACK			0x00
#define	VGA_COLOR_BLUE			0x1
#define	VGA_COLOR_GREEN			0x2
#define	VGA_COLOR_CYAN			0x3
#define	VGA_COLOR_RED			0x4
#define	VGA_COLOR_MAGENTA		0x5
#define	VGA_COLOR_BROWN			0x6
#define	VGA_COLOR_LIGHT_GREY	0x7
#define	VGA_COLOR_DARK_GREY		0x8
#define	VGA_COLOR_LIGHT_BLUE	0x9
#define	VGA_COLOR_LIGHT_GREEN	0xA
#define	VGA_COLOR_LIGHT_CYAN	0xB
#define	VGA_COLOR_LIGHT_RED		0xC
#define	VGA_COLOR_LIGHT_MAGENTA	0xD
#define	VGA_COLOR_LIGHT_BROWN	0xE
#define	VGA_COLOR_WHITE			0xF
 
uint8_t inportb(uint16_t);
void outportb(uint16_t, uint8_t);
void update_cursor(uint8_t, uint8_t);
void cls(void);
void cll(short, short);

void printchar(char, uint8_t, uint8_t);
void printstr(string);

#endif
