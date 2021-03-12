#include "BinaryTree.hpp"
#include <iostream>
using namespace std;

BinaryTree::BinaryTree() : root(nullptr) {}

BinaryTree::BinaryTree(const int* arr, int len) : root(nullptr) {
    for (int i = 0; i < len; i++) {
        insert(arr[i]);
    }
}

BinaryTree::BinaryTree(const BinaryTree& that) { BuildTree(that.root, this->root); }

BinaryTree::~BinaryTree() { clear(); }

void BinaryTree::BuildTree(const int* arr, int len, node*& root) { /*useless*/
}

void BinaryTree::BuildTree(const node* Source_Root, node*& Target_Root) {
    if (Source_Root) {
        Target_Root = new node(Source_Root->ele);
        BuildTree(Source_Root->left, Target_Root->left);
        BuildTree(Source_Root->right, Target_Root->right);
    } else {
        Target_Root = nullptr;
    }
}

void BinaryTree::insert(int e) {
    if (root == nullptr) {
        root = new node(e);
    } else {
        node *nowptr = root, *lastptr = nullptr;
        while (nowptr) {
            lastptr = nowptr;
            if (e < nowptr->ele) {
                nowptr = nowptr->left;
            } else if (e > nowptr->ele) {
                nowptr = nowptr->right;
            } else {
                return;
            }
        }
        if (e < lastptr->ele) {
            lastptr->left = new node(e);
        } else {
            lastptr->right = new node(e);
        }
    }
}

void BinaryTree::print() {
    preorder(root);
    cout << endl;
}

void BinaryTree::preorder(const node* p) {
    if (p) {
        cout << p->ele << " ";
        preorder(p->left);
        preorder(p->right);
    }
}

void BinaryTree::clear() {
    MemoryDelete(root);
    root = nullptr;
}

void BinaryTree::MemoryDelete(node* p) {
    if (p) {
        if (p->left) {
            MemoryDelete(p->left);
        }
        if (p->right) {
            MemoryDelete(p->right);
        }
    }
    delete p;
}

void BinaryTree::ResetTree(const int* arr, int len) {
    clear();
    for (int i = 0; i < len; i++) {
        insert(arr[i]);
    }
}

void BinaryTree::Delete(int e) {
    //找到要删除的节点nowptr，并储存它的父亲lastptr
    node *nowptr = root, *lastptr = nullptr;
    while (nowptr) {
        if (e < nowptr->ele) {
            lastptr = nowptr;
            nowptr = nowptr->left;
        } else if (e > nowptr->ele) {
            lastptr = nowptr;
            nowptr = nowptr->right;
        } else {
            break;
        }  //找完了
    }
    if (nowptr == nullptr) {
        return;
    }

    //如果待删除节点是叶子
    if (nowptr->left == nullptr && nowptr->right == nullptr) {
        // nowptr是根节点
        if (lastptr == nullptr) {
            delete nowptr;
            root = nullptr;
        }
        // nowptr是它父亲的左儿子
        else if (nowptr == lastptr->left) {
            lastptr->left = nullptr;
            delete nowptr;
        }
        // nowptr是它父亲的右儿子
        else if (nowptr == lastptr->right) {
            lastptr->right = nullptr;
            delete nowptr;
        }
    }
    //如果待删除节点只有左儿子没有右儿子
    else if (nowptr->left != nullptr && nowptr->right == nullptr) {
        // nowptr是根节点
        if (lastptr == nullptr) {
            root = nowptr->left;
        }
        // nowptr是它父亲的左儿子
        else if (nowptr == lastptr->left) {
            lastptr->left = nowptr->left;
        }
        // nowptr是它父亲的右儿子
        else if (nowptr == lastptr->right) {
            lastptr->right = nowptr->left;
        }
        delete nowptr;
    }
    //如果待删除节点只有右儿子没有左儿子
    else if (nowptr->right != nullptr && nowptr->left == nullptr) {
        // nowptr是根节点
        if (lastptr == nullptr) {
            root = nowptr->right;
        }
        // nowptr是它父亲的左儿子
        else if (nowptr == lastptr->left) {
            lastptr->left = nowptr->right;
        }
        // nowptr是它父亲的右儿子
        else if (nowptr == lastptr->right) {
            lastptr->right = nowptr->right;
        }
        delete nowptr;
    }

    //如果待删除节点有两个儿子
    else if (nowptr->right && nowptr->left) {
        //先找nowptr左节点最右边的子节点r和它的父亲rfather
        node *r = nowptr->left, *rfather = nowptr;
        while (r->right) {
            rfather = r;
            r = r->right;
        }
        // nowptr是根节点
        if (lastptr == nullptr) {
            if (nowptr == rfather) {
                r->right = nowptr->right;
                root = r;
            } else {
                rfather->right = r->left;
                r->left = nowptr->left;
                r->right = nowptr->right;
                root = r;
            }
        }
        // nowptr是它父亲的左儿子
        else if (nowptr == lastptr->left) {
            if (nowptr == rfather) {
                r->right = nowptr->right;
                lastptr->left = r;
            } else {
                rfather->right = r->left;
                r->left = nowptr->left;
                r->right = nowptr->right;
                lastptr->left = r;
            }
        }
        // nowptr是它父亲的右儿子
        else if (nowptr == lastptr->right) {
            if (nowptr == rfather) {
                r->right = nowptr->right;
                lastptr->right = r;
            } else {
                rfather->right = r->left;
                r->left = nowptr->left;
                r->right = nowptr->right;
                lastptr->right = r;
            }
        }
        delete nowptr;
    }
}
