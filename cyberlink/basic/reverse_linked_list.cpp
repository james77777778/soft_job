#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr)
            return head;
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
};

int main() {
    // make linked list 7->2->3->5->nullptr
    ListNode a(5);
    ListNode b(3, &a);
    ListNode c(2, &b);
    ListNode d(7, &c);

    Solution s;
    ListNode* new_head = s.reverseList(&d);
    while(new_head != nullptr) {
        cout << new_head->val << " ";
        new_head = new_head->next;
    }
    cout << endl;
}
