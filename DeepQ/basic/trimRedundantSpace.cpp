#include <iostream>
#include <vector>
#include <string>
using namespace std;


string trimRedundantSpace(string &s) {
    string res = "";
    for(int i=0; i<s.size(); i++) {
        if(s[i] != ' ')
            res += s[i];
    }
    return res;
}


int main() {
    string s = "hello world hahah     haha";
    string res = trimRedundantSpace(s);

    cout << res << endl;
}