#include "BST_Tree.h"

void BST_Tree::insert_node(int key)
{
    if (this->root == nullptr) {
        BST_Node* new_node = new BST_Node(key);
        this->root = new_node;
    }
}

void BST_Tree::print()
{
    this->root->print();
}

BST_Tree::BST_Tree()
{
    this->root = nullptr;
}
