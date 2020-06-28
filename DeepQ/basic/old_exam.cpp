#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define X 90
void A() { printf("%d\n", X); }
#define X 100
void B() { printf("%d\n", X); }


int min(int a, int b, int c) {
    return (a<=b && a<=c) ? a : (b<=a && b<=c) ? b : c;
}

int fibonacii(int n) {
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    int prev = 0, next = 1;
    int temp;
    for(int i=2; i<n+1; i++) {
        temp = prev;
        prev = next;
        next = temp + next;
    }
    return next;
}


int main() {
    // 1.填充題，利用跳脫字元印出含有 " " 以及 \ 的符號
    cout << "\" \" \\" << endl;
    
    // 2.填充題，輸入任意三個整數，最後可以輸出最小的那個
    cout << min(1, 2, 3) << " " << min(3, 2, 1) << endl;
    
    // 3. 計算題，continue的用法
    // 給你一段迴圈，裡面有包含continue、if的敘述，問你最後執行結果是啥
    // ex: for i=0;i<=15;i++
    // if i<=4 && i>=6 continue
    // if i>=10 printf("XXX")
    for(int i=0; i<=15; i++) {
        if(i<=4 && i>=6)
            continue;
        if(i>=10)
            cout << i << " ";
    }
    cout << endl;

    // 5.計算題，考#define位置的觀念
    A();
    B();

    // 12.計算題，寫一個函數，如何不用遞迴的方式寫出費伯納西數列(Fibonacci)?
    cout << fibonacii(10) << endl;
}


