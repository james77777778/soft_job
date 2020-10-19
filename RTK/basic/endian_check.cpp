#include <stdint.h>
#include "stdio.h"

bool is_little_endian(void)
{
    union {
        uint32_t i;
        char c[4];
    } x = {0x01020304};

    if(x.c[0] == 0x01 && x.c[1] == 0x02 && x.c[2] == 0x03 && x.c[3] == 0x04) {
        printf("Big Endian.\n");
        return true;
    }
    if(x.c[0] == 0x04 && x.c[1] == 0x03 && x.c[2] == 0x02 && x.c[3] == 0x01) {
        printf("Little Endian.\n");
        return true;
    }
    else {
        printf("Undefined Endian.\n");
        return false;
    } 
}

int main() {
    printf("%d\n", is_little_endian());  // 1 for linux in x86
}
