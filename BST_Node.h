#pragma once
class BST_Node
{
public:
    int key;
    BST_Node* left, * right;
    BST_Node();
    BST_Node(int key);
    ~BST_Node();
    void print();
};

