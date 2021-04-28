#include<iostream>
#include "BST_Node.h"

using namespace std;

BST_Node::BST_Node()
{
    this->key = 0;
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
