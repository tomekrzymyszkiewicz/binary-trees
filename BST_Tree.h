#pragma once
#include "BST_Node.h"
class BST_Tree
{
public:
    BST_Node* root;
    void insert_node(int key);
    void delete_node();
    void print();
    BST_Tree();
};

