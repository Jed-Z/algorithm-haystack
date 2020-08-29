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
    //�ҵ�Ҫɾ���Ľڵ�nowptr�����������ĸ���lastptr
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
        }  //������
    }
    if (nowptr == nullptr) {
        return;
    }

    //�����ɾ���ڵ���Ҷ��
    if (nowptr->left == nullptr && nowptr->right == nullptr) {
        // nowptr�Ǹ��ڵ�
        if (lastptr == nullptr) {
            delete nowptr;
            root = nullptr;
        }
        // nowptr�������׵������
        else if (nowptr == lastptr->left) {
            lastptr->left = nullptr;
            delete nowptr;
        }
        // nowptr�������׵��Ҷ���
        else if (nowptr == lastptr->right) {
            lastptr->right = nullptr;
            delete nowptr;
        }
    }
    //�����ɾ���ڵ�ֻ�������û���Ҷ���
    else if (nowptr->left != nullptr && nowptr->right == nullptr) {
        // nowptr�Ǹ��ڵ�
        if (lastptr == nullptr) {
            root = nowptr->left;
        }
        // nowptr�������׵������
        else if (nowptr == lastptr->left) {
            lastptr->left = nowptr->left;
        }
        // nowptr�������׵��Ҷ���
        else if (nowptr == lastptr->right) {
            lastptr->right = nowptr->left;
        }
        delete nowptr;
    }
    //�����ɾ���ڵ�ֻ���Ҷ���û�������
    else if (nowptr->right != nullptr && nowptr->left == nullptr) {
        // nowptr�Ǹ��ڵ�
        if (lastptr == nullptr) {
            root = nowptr->right;
        }
        // nowptr�������׵������
        else if (nowptr == lastptr->left) {
            lastptr->left = nowptr->right;
        }
        // nowptr�������׵��Ҷ���
        else if (nowptr == lastptr->right) {
            lastptr->right = nowptr->right;
        }
        delete nowptr;
    }

    //�����ɾ���ڵ�����������
    else if (nowptr->right && nowptr->left) {
        //����nowptr��ڵ����ұߵ��ӽڵ�r�����ĸ���rfather
        node *r = nowptr->left, *rfather = nowptr;
        while (r->right) {
            rfather = r;
            r = r->right;
        }
        // nowptr�Ǹ��ڵ�
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
        // nowptr�������׵������
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
        // nowptr�������׵��Ҷ���
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