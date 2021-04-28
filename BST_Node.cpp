#include<iostream>
#include "BST_Node.h"

using namespace std;

BST_Node::BST_Node()
{
    this->key = NULL;
    this->left = nullptr;
    this->right = nullptr;
}

BST_Node::BST_Node(int key)
{
    this->key = key;
    this->left = nullptr;
    this->right = nullptr;
}

BST_Node::~BST_Node()
{
}

void BST_Node::print()
{
    cout << this->key;
    if(this->left != nullptr)
        this->left->print();
    if (this->right != nullptr)
        this->right->print();
}

void BST_Node::insert(BST_Node* root, int key)
{
    if (root == nullptr) {
        return new BST_Node(key);
    }
    else {
        BST_Node* current;
        if (key <= root->key) {
            current = insert(root->left, key);
            root->left = current;
        }
        else {
            current = insert(root->right, key);
            root->right = current;
        }
        return root;
    }
}
