// Approach 1 inorder traversal iss sorted
// Approach 2 left subtree all nodes contains value less than root and right has greater
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


bool isBST(BinaryTreeNode<int> *root, int up, int low){
    if(root == NULL){
        return true;
    }
    bool check = (root -> data >= low) && (root -> data <= up);
    bool left = isBST(root->left,root->data,low);
    bool right = isBST(root -> right,up,root->data);
    return left && right && check;
}


bool validateBST(BinaryTreeNode<int> *root) {
    return isBST(root,INT_MAX,INT_MIN);
}