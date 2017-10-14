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
	bool str_are_same = strcmp("Hello World", "Hello World");
	if (str_are_same) {
		printchar('Y', 0, 0);
	} 

}

