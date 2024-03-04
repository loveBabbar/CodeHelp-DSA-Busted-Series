#include <bits/stdc++.h> 
using namespace std;
template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
    
};

void Inorder(BinaryTreeNode<int>* root, vector<int> &storage){
    if( root == NULL){
        return;
    }
    Inorder(root->left,storage);
    storage.push_back(root->data);
    Inorder(root->right,storage);
}


bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	vector<int> storage;
    Inorder(root,storage);
    int i = 0, j = storage.size()-1;
    while(i < j){
        if(storage[i] + storage[j] == target)
            return true;
        else if(storage[i] + storage[j] < target )
            i++;
        else
            j--;
    }
    return 0;
}