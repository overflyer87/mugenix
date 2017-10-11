#include <stdarg.h>
#include <iso646.h>
#include <limits.h>
#include "include/string.h"
#include "include/console.h"
#include "include/typedef.h"

void kmain(void)
{
	/* Initialize screen in terminal mode*/
	cls();
	printstr("Hello World!");
}

