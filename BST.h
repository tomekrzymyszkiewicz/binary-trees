#pragma once
#include<iostream>
#include <iomanip>
using namespace std;
struct BST
{
	int key;
	BST* left;
	BST* right;
};

BST* insert_node(BST *&root, int key)
{
	if (!root)
	{
		BST* temp = new BST();
		temp->key = key;
		temp->left = temp->right = nullptr;
		root = temp;
		return root;
	}
	else if (key <= root->key)
	{
		insert_node(root->left, key);
	}
	else
	{
		insert_node(root->right, key);
	}
	return root;
}

void displayTreeInorder(BST* root)
{
	if (root)
	{
		cout << root->key << " ";
		displayTreeInorder(root->left);
		displayTreeInorder(root->right);
	}
}

void postorder(BST* root, int indent)
{
	if (root)
	{
		if (root->right)
		{
			postorder(root->right, indent + 4);
		}
		if (indent) 
		{
			cout << setw(indent) << ' ';
		}
		if (root->right)
		{
			cout << " /\n" << setw(indent) << ' ';
		}
		cout << root->key << "\n ";
		if (root->left) {
			cout << setw(indent) << ' ' << " \\\n";
			postorder(root->left, indent + 4);
		}
	}
}