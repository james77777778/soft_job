#include <iostream>
#include <vector>

using namespace std;

void bubble_sort(vector<int> &arr) {
    int temp;
    for(int i=0; i<arr.size(); i++) {
        for(int j=0; j<i; j++) {
            if(arr[j] < arr[i]) {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}


int main() {
    vector<int> arr = {2, 4, 6, 19, 3, 188, 37, 23, 0};
    bubble_sort(arr);
    for(int i: arr) {
        cout << i << " ";
    }
    cout << endl;
}