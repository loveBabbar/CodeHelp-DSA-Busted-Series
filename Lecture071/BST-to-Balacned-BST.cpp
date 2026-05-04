#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class TreeNode {
    public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
};

void inorder(TreeNode<int>* root, vector<int> &in) {

    if (root == NULL) return;

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

TreeNode<int>* inorderToBST(int start, int end, vector<int> &in) {

    // base case
    if (start > end) {
        return NULL;
    }

    // find mid
    int mid = end + (start - end) / 2;

    // create a node for the middle data
    TreeNode<int>* newNode = new TreeNode<int>(in[mid]);

    // do same for left and right, rest reccurssion will handle
    newNode->left = inorderToBST(start, mid-1, in);
    newNode->right = inorderToBST(mid+1, end, in);

    return newNode;
}

TreeNode<int>* balancedBst(TreeNode<int>* root) {
    // Write your code here.

    // find inorder of BST
    vector<int> in;
    inorder(root, in);

    // convert inorder to balanced BST
    int start = 0;
    int end = in.size()-1;
    return inorderToBST(start, end, in);
}
