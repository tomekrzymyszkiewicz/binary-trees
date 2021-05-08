#pragma once
#include<iostream>
#include <iomanip>
#include <vector>
using namespace std;
struct BT
{
	vector<int> BT_tree;

	void insert_node(int key){
        BT_tree.push_back(key);
    }
    int right_child_index(int index){
        return (2*index+2);
    }
    int left_child_index(int index){
        return (2*index+1);
    }
    int parent_index(int index){
        return ((index-1)/2);
    }
    void display(int index = 0, int indent = 0){
        if(index <= BT_tree.size()){
            if(right_child_index(index) < BT_tree.size()){
                display(right_child_index(index), indent + 4);
            }
            if(indent){
                cout << setw(indent) << ' ';
            }
            if(right_child_index(index) < BT_tree.size()){
                cout << " /\n" << setw(indent) << ' ';
            }
            cout << BT_tree[index] << "\n ";
            if (left_child_index(index) < BT_tree.size()) {
			    cout << setw(indent) << ' ' << " \\\n";
			    display(left_child_index(index), indent + 4);
		    }
        }
    }
    int search(int key){
        for(int i = 0; i < BT_tree.size(); i++){
            if(BT_tree[i] == key)
                return i;
        }
        return -1;
    }
    void delete_node(int key){
        int key_index = search(key);
        if(key != -1){
            BT_tree[key_index] = BT_tree[BT_tree.size()-1];
            BT_tree.pop_back();
        }
    }
};