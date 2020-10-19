#include <stdio.h>
#include <stdlib.h>
#include <cstring>

int a=0;   //global 初始化區
char *p1;  //global 未初始化區

static int num_a;
// 專屬於整個檔案的全域變數，其他檔案不能存取

void func (int num_b) { // stack 區 
    int num_c; // stack 區

    static int num_d; 
    //scope不變，只能在函數 func 內呼叫，但 lifetime 是整支程式執行的時間。
    //常常用來實作counter
    //static int counter;
    //counter++;
}

int main(){
    int b;             // stack
    char s[]="abc";    // stack
    char *p2;          // stack
    char *p3="123456"; // 123456\0 在常量區，p3在stack。
    static int c=0;   // global (static) 初始化區
    p1 = (char*)malloc(10);
    p2 = (char*)malloc(20);  //分配得來得10和20位元組的區域在heap
    strcpy(p1,"123456");  
    //123456\0 在常量區，編譯器可能會將它與 p3 中的 123456\0 優化成一個地方。
}