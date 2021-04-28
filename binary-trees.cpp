#include <iostream>
#include "BST.h"

using namespace std;
int main()
{
    BST* root = nullptr;
    insert_node(root, 5);
    insert_node(root, 2);
    insert_node(root, 6);
    insert_node(root, 1);
    insert_node(root, 3);
    insert_node(root, 4);
    insert_node(root, 7);
    postorder(root,1);
    return 0;
}
