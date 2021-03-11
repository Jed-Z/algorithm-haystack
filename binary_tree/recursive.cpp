#include <iostream>

#include "TreeNode.h"
using namespace std;

void preorderRecursive(TreeNode* root) {
    if (root) {
        cout << root->val << ' ';
        preorderRecursive(root->left);
        preorderRecursive(root->right);
    }
}

void inorderRecursive(TreeNode* root) {
    if (root) {
        inorderRecursive(root->left);
        cout << root->val << ' ';
        inorderRecursive(root->right);
    }
}

void postorderRecursive(TreeNode* root) {
    if (root) {
        postorderRecursive(root->left);
        postorderRecursive(root->right);
        cout << root->val << ' ';
    }
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    preorderRecursive(root);
    cout << endl;
    inorderRecursive(root);
    cout << endl;
    postorderRecursive(root);
    cout << endl;
    return 0;
}