#include <iostream>

using namespace std;

class TreeNode {
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    // Write your code here.

    TreeNode* curr = root;

    // -------find the key node---------
    int pred = -1;
    int succ = -1;
    while (curr && curr->data != key) {

        if (curr->data > key) {
            succ = curr->data;
            curr = curr->left;
        }
        else {
            pred = curr->data;
            curr = curr->right;
        }
    }

    if (curr) {
        // now curr is pointing to key node
        TreeNode* left = curr->left;
        while (left) {
            pred = left->data;
            left = left->right;
        }

        TreeNode* right = curr->right;
        while (right) {
            succ = right->data;
            right = right->left;
        }
    }

    return {pred, succ};
}