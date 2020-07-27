#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_map>
#include <limits.h>
#include <stack>
#include <queue>
#include <math.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void printSubtree(TreeNode* root, const string& prefix);
void printTree(TreeNode* root)
{
    if (root == NULL)
    {
            return;
    }

    cout << root->val << endl;
    printSubtree(root, "");
    cout << endl;
}

void printSubtree(TreeNode* root, const string& prefix)
{
    if (root == NULL)
    {
        return;
    }

    bool hasLeft = (root->left != NULL);
    bool hasRight = (root->right != NULL);

    if (!hasLeft && !hasRight)
    {
        return;
    }

    cout << prefix;
    cout << ((hasLeft  && hasRight) ? "├── " : "");
    cout << ((!hasLeft && hasRight) ? "└── " : "");

    if (hasRight)
    {
        bool printStrand = (hasLeft && hasRight && (root->right->right != NULL || root->right->left != NULL));
        string newPrefix = prefix + (printStrand ? "│   " : "    ");
        cout << root->right->val << endl;
        printSubtree(root->right, newPrefix);
    }

    if (hasLeft)
    {
        cout << (hasRight ? prefix : "") << "└── " << root->left->val << endl;
        printSubtree(root->left, prefix + "    ");
    }
}