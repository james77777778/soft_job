#include <stdio.h>

typedef struct person {
    char name[16]; 
    int age;
    struct person *ptr;  
    // 不能含有自己，但可以有自己型別的指標。
} PERSON;

int main () {
    PERSON person1 = {"Amy", 20 }; // 初始化
    person1.age = 21; // 操作
    printf("%s\n", person1.name);
    printf("%d\n", person1.age);
}