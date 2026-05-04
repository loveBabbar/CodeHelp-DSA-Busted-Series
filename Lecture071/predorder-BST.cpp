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

        ~BinaryTreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
};

// preorder = 10 4 3 7 40 55 
/*
    i = 0, pre[i] = 10      10
    i = 1, pre[i] = 4      /  \
    i = 2, pre[i] = 3     4   40
                         / \  /\
    i = 3, pre[i] = 7   3       55
                       / \
                          7
    i = 4, pre[i] = 40   / \
    i = 5, pre[i] = 55
                          

*/

BinaryTreeNode<int>* solve(vector<int> &preorder, int min, int max, int &currIndex) {

    // -------out of preorder array-----------
    if (currIndex >= preorder.size()) {
        return NULL;
    }

    // not in current range (a, b)
    if (preorder[currIndex] < min || preorder[currIndex] > max) {
        return NULL;
    }

    // if in range, create a node for that, and increment array index
    BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(preorder[currIndex++]);

    // rest reccurssion will handle
    // left range -> (min, root->data)
    newNode->left = solve(preorder, min, newNode->data, currIndex);

    // right range -> (root->data, max)
    newNode->right = solve(preorder, newNode->data, max, currIndex);

    // return this node after processing
    return newNode;
}

BinaryTreeNode<int>* preorderToBST(vector<int> &preorder) {
    // Write your code here.

    int min = INT_MIN;
    int max = INT_MAX;

    int startIndex = 0;
    return solve(preorder, min, max, startIndex);
}