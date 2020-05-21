#include <iostream>
#include <string.h>

using namespace std;

char* strcpy(char* s1,const char* s2);
char* strncpy(char* s1, const char * s2,size_t n);

char* strcpy(char* s1, const char* s2) {
    if(s1 == nullptr || s2 == nullptr)
        return nullptr;
    for(; *s2 != '\0'; s1++, s2++)
        *s1 = *s2;
    return s1;
}

char* strncpy(char* s1, const char * s2,size_t n) {
    if(s1 == nullptr || s2 == nullptr)
        return nullptr;
    for(; n; s1++, s2++, n--)
        *s1 = *s2;
    return s1;
}

int main() {
    char s1[] = "aaaaaaaaaaa";
    char s2[] = "hello world";
    strcpy(s1, s2);
    for(int i=0; i<strlen(s1); i++)
        cout << s1[i];
    cout << endl;
    
    char s3[] = "aaaaaaaaaaa";
    char s4[] = "hello world";
    strncpy(s3, s4, 3);
    for(int i=0; i<strlen(s1); i++)
        cout << s3[i];
    cout << endl;
}