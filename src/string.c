#include "include/string.h"
#include "include/console.h"

#define VGA_BUF_MEM_ADRESS 0xB8000

static string* vga_txt_vid_buf = (string*) VGA_BUF_MEM_ADRESS;
static size_t row;
static size_t col;

bool strcmp(const string str_one, const string str_two) 
{
    short len_str_one = strlen(str_one);
    short len_str_two = strlen(str_two);
    
    if (len_str_one != len_str_two) {
        return 0;
    } else {
        short i;

        for (i = 0; i < len_str_one; i++) {
            if (str_one[i] == str_two[i]) {
                if (i == (len_str_one - 1)) {
                    return 1;
                } 
                continue;
            } else {
                return 0;
            }
        }
    }

    //-128 will be Mugenix OS error code for strcmp() failed
    return -128;
}

size_t strlen(string str)
{
    size_t len = 0;

    while (str[len]) {
        len++;
    }
    return len;
}



