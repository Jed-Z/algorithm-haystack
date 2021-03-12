#include <iostream>
#include <stack>
#include "TreeNode.h"
using namespace std;

void preorderIterative(TreeNode *root) {
    if (!root) return;
    stack<TreeNode *> stk;
    stk.push(root);
    while (!stk.empty()) {
        TreeNode *curr = stk.top();
        cout << curr->val << ' ';  // visit
        stk.pop();
        if (curr->right) stk.push(curr->right);
        if (curr->left) stk.push(curr->left);
    }
}

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    preorderIterative(root);
    cout << endl;
    return 0;
}
