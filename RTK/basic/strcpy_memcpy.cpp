#include <string.h>
#include <stdio.h>

int main (){
    const char *str1 = "abc\0def";
    char str2[16] = {0};
    char str3[16] = {0};

    strcpy(str2, str1);
    memcpy(str3, str1, sizeof(str3)); // 8
    printf("str2 = %s\n", str2);    // str2 = abc
    printf("str3[5] = %c\n", str3[5]); // str3 = e
    printf("str3 = %s\n", str3); // str3 = abc

    char str4[16] = {0};
    strcpy(str4, str3+4);
    printf("str3 = %s\n", str4); // str3 = def
    return 0;
}
