#include <bits/stdc++.h> 
using namespace std;
template <typename T>

class BinaryTreeNode 
{
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

int solve(BinaryTreeNode<int>* root, int  &k){
    if(root == NULL){
        return -1;
    }
    int left = solve(root -> left,k);
    if( k == 0){
        return left;
    }
        k--;
    // cout << root -> data << " " << k << endl;
    if( k == 0){
        return root->data;
    }
    int right = solve(root->right,k);
    if( k == 0){
        return right;
    }
    return -1;
}

int kthSmallest(BinaryTreeNode<int>* root, int k) {
    
    return solve(root,k);
}