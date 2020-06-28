#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    void reverseString(vector<char>& s) {
        char t;
        int s_len = s.size();
        for(int i=0; i<s_len/2; i++) {
            t = s[i];
            s[i] = s[s_len-1-i];
            s[s_len-1-i] = t;
        }
    }
};


int main(){
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    Solution sol;
    for(char c:s)
        std::cout << c << " ";
    std::cout << std::endl;
    sol.reverseString(s);
    for(char c:s)
        std::cout << c << " ";
    std::cout << std::endl;
}