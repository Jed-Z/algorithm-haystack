#include <iostream>
#include <stack>
#include "TreeNode.h"
using namespace std;

void preorderIterative(TreeNode *root) {
    if (!root) return;
    stack<TreeNode *> stk;
    stk.push(root);
    while (!stk.empty()) {
        TreeNode *node = stk.top();
        stk.pop();
        cout << node->val << ' ';
        if (node->right) stk.push(node->right);
        if (node->left) stk.push(node->left);
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
