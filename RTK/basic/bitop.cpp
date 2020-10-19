#include "stdio.h"

int main() {
    unsigned long num_a = 0x00001111;
    unsigned long num_b = 0x00000202;
    unsigned long num_c;

    // 0001000100010001 (4096+256+16+1 == 4369) & ~0000001000000010 (512+2 == 514)
    // 0001000100010001 & 1111110111111101
    num_c = num_a & (~num_b); 
    // 0001000100010001
    printf("%lx\n", num_c); // 00001111
    
    // 0001000100010001 | 0000001000000010
    // 0001001100010011
    num_c = num_c | num_b;
    printf("%lx\n", num_c); // 00001313

    unsigned long a = 0x00000000; 
    a = a | 0x00000007;    // 最右側 3 位設為 1，其餘不變。
    printf("%lx\n", a);
    a = a & (~7); // 最右側 3 位設為 0，其餘不變。
    printf("%lx\n", a);
    a = a ^ 7;    // 最右側 3 位執行 NOT operator，其餘不變。
    printf("%lx\n", a);
}
