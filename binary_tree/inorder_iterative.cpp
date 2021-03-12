#include <iostream>
#include <stack>
#include "TreeNode.h"
using namespace std;

void inorderIterative(TreeNode* root) {
    if (!root) return;
    stack<TreeNode*> stk;
    TreeNode* curr = root;
    while (curr || !stk.empty()) {
        if (curr) {
            stk.push(curr);
            curr = curr->left;
        } else {
            curr = stk.top();
            cout << curr->val << ' ';  // visit
            stk.pop();
            curr = curr->right;
        }
    }
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    inorderIterative(root);
    cout << endl;
    return 0;
}
