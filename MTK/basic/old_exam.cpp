#include<iostream>
using namespace std;


// bit count
int bitcount(unsigned int n)
{
    int count = 0;
    while(n)
    {
        count++;
        n &= (n-1);
    }
    return count;
}


int main() {
    // 1.
    unsigned long v1 = 0x00001111;
    unsigned long v2 = 0x00001202;
    unsigned long v;
    v = v1 & (~v2);
    v = v | v2;
    printf("%#010lx\n", v);
    // v1 & (~v2) = 0x00000111
    // v | v2 = 0x00000111 | 0x00001202 = 0x00001313

    // 2.
    int a[5] = {1, 2, 3, 4, 5};
    printf("%d\n", *(a+1));
    int *p = (int *)(&a+1);
    printf("%d\n", *(p-1));

    // 3.
    unsigned int bits = 0x00001111;
    printf("clear specific bit:\t%#010x\n", bits & ~(1 << 0));
    printf("set specific bit:\t%#010x\n", bits | (1 << 1));
    printf("inverse specific bit:\t%#010x\n", bits ^ (1 << 1));

    printf("%d", bitcount(8));

}
