#include "BST_Tree.h"

void BST_Tree::insert_node(int key)
{
    this->root->insert(this->root, key);
    //BST_Node* new_node = new BST_Node(key);
    //if (this->root == nullptr) {
    //    this->root = new_node;
    //}
    //BST_Node* current_node = this->root;
    //while (current_node != nullptr) {
    //    if (new_node->key <= current_node->key) {
    //        current_node = current_node->left;
    //    }
    //    else{
    //        current_node = current_node->right;
    //    }
    //}
    //current_node = new_node;
}

void BST_Tree::print()
{
    this->root->print();
}

BST_Tree::BST_Tree()
{
    this->root = nullptr;
}
