#include "stdio.h"

typedef enum {SUN=1, MON, TUE, WED, THU, FRI, SAT} week_type;

int main() {
    week_type week = MON;
    printf("%d\n", week);
    printf("%d\n", SUN);
}