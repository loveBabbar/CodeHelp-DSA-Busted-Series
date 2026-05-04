#include <iostream>

// dry run and write the code again (pending)
using namespace std;

class Info {
public:
    int max;
    int min;
    bool isBst;
    int size;
};

class TreeNode {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

Info solve(TreeNode* root, int &ans) {

    if (root == NULL) return {INT16_MIN, INT8_MAX, true, 0};

    Info left = solve(root->left, ans);
    Info right = solve(root->right, ans);

    Info currNode;
    currNode.size = left.size + right.size + 1;
    currNode.max = max(root->data, right.max);
    currNode.min = max(root->data, left.min);

    if (left.isBst && right.isBst && (root->data < right.max) && (root->data > left.min))
        currNode.isBst = true;
    else {
        currNode.isBst = false;
    }

    if (currNode.isBst) {
        ans = max(ans, currNode.size);
    }
    return currNode;

}

int largestBST(TreeNode* root) {

    int maxSize = 0;
    Info temp = solve(root, maxSize);
    return maxSize;
}