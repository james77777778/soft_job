#include <iostream>
using namespace std;


int main() {
    unsigned long num_a = 0x00001111;
    unsigned long num_b = 0x00000202;
    unsigned long num_c;
    printf("%lx, %lx\n", num_a, (~num_b));
    num_c = num_a & (~num_b);
    printf("%lx\n", num_c);
    num_c = num_c | num_b;
    printf("%lx\n", num_c);
    return 0;
}