#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode {
public: 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
    
};

void inorder(BinaryTreeNode<int>* root, vector<int> &in) {

    if (root == NULL) return;

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	//Write your code here

    vector<int> inorderVal;

    inorder(root, inorderVal);

    int i = 0, j = inorderVal.size()-1;
    while (i < j) {

        int sum = inorderVal[i] + inorderVal[j];

        if (sum == target) return true;

        if (sum > target) j--;
        else {
            i++;
        }
    }
    return false;
}