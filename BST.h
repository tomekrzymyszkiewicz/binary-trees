#pragma once
#include<iostream>
#include <iomanip>
using namespace std;
struct BST
{
	int key;
	BST* left;
	BST* right;
	BST(){
		key = 0;
		left = nullptr;
		right = nullptr;
	};
	// ~BST(){
	// 	delete this;
	// }
};

void DestroyBST(BST *&root){
	if(root->left){
		DestroyBST(root->left);
	}
	if(root->right){
		DestroyBST(root->right);
	}
	delete root;
}

BST* BST_insert_node(BST *&root, int key)
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
		BST_insert_node(root->left, key);
	}
	else
	{
		BST_insert_node(root->right, key);
	}
	return root;
}

BST* BST_search_node(BST *&root, int key)
{
	if(root == nullptr || root->key == key){
		return root;
	}
	if(root->key < key){
		return BST_search_node(root->right, key);
	}
	return BST_search_node(root->left,key);
}

BST* BST_delete_node(BST *&root, int key){
	if(root == nullptr){
		return nullptr;
	}
	if(root->key > key){
		root->left = BST_delete_node(root->left,key);
		return root;
	}
	else if(root->key < key){
		root->right = BST_delete_node(root->right,key);
		return root;
	}
	if(root->left == nullptr){ //tylko prawe dziecko
		BST* temp = root->right;
		delete root;
		return temp;
	} 
	else if(root->right == nullptr){ //tylko lewe dziecko
		BST* temp = root->left;
		delete root;
		return temp;
	}
	else{
		BST* parent = root;
		BST* successor = root->right;
		while(successor->left != nullptr){ //wyszukiwanie następnika
			parent = successor;
			successor = successor->left;
		}
		if(parent != root){
			parent->left = successor->right;
		}
		else{
			parent->right = successor->right;
		}
		root->key = successor->key;
		delete successor;
		return root;
	}
}

void BST_inorder(BST* root)
{
	if (root)
	{
		cout << root->key << " ";
		BST_inorder(root->left);
		BST_inorder(root->right);
	}
}

void BST_postorder(BST* root, int indent=0)
{
	if (root)
	{
		if (root->right)
		{
			BST_postorder(root->right, indent + 4);
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
			BST_postorder(root->left, indent + 4);
		}
	}
}