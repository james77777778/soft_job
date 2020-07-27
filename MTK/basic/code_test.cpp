#include "leetcode.h"

ListNode* reverseList(ListNode* head) {
    ListNode* newHead = nullptr;
    ListNode* next;
    while(head != nullptr) {
        next = head->next;
        head->next = newHead;
        newHead = head;
        head = next;
    }
    return newHead;
}


int maxSubarray(int nums[], int n) {
    int ans = nums[0];
    int sum = 0;
    for(int i=1; i<n; i++) {
        sum += nums[i];
        ans = max(ans, sum);
        sum = max(sum, 0);
    }
    return ans;
}

void sway(int &a, int &b) {
    if(a != b) {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
}

#define INC(x) x*=2; x+=1

int main() {
    // 1. linked list reverse
    // make linked list: 7->2->3->5->nullptr
    ListNode a(5);
    ListNode b(3, &a);
    ListNode c(2, &b);
    ListNode d(7, &c);

    ListNode* new_head = reverseList(&d);
    // new linked list: 5->3->2->7->nullptr
    while(new_head != nullptr) {
        cout << new_head->val << " ";
        new_head = new_head->next;
    }
    cout << endl;

    // 2. maximum subarray
    int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSubarray(nums, 9) << endl;

    // 3. swap with bit operation
    int x = 3, y = 10;
    swap(x, y);
    cout << "After swap: x = " << x << " y = " << y << endl;

    // 4.
    int j = 1;
    for(int i=0; i<5; i++) {
        INC(j);
    }
    cout << j << endl;  // 63

    // 5. string vs. char array
    string s1 = "abc";
    char s2[] = "abc";
    cout << (s1 == s2) << endl;

    // 6.
    int a1[5] = {1,2,3,4,5};
    int *p1 = a1;
    *(p1++) += 123;
    *(++p1) += 123;
    for(int i=0; i<5; i++)
        cout << a1[i] << " ";
    cout << endl;
}