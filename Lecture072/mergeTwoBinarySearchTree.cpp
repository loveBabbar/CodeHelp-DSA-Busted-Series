#include <iostream>
#include <vector>
using namespace std;

class TreeNode {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};


void inorder(TreeNode *root, vector<int> &in) {

    if (root == NULL) return;

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

vector<int> mergeArrays(vector<int> &bst1, vector<int> &bst2) {

    vector<int> ans(bst1.size() + bst2.size());

    int i = 0;
    int j = 0;
    int k = 0;
    while (i != bst1.size() && j != bst2.size()) {

        if (bst1[i] < bst2[j]) {
            ans[k++] = bst1[i++];
        }
        else {
            ans[k++] = bst2[j++];
        }
    }

    while (i != bst1.size()) {
        ans[k++] = bst1[i++];
    }

    while (j < bst2.size()) {
        ans[k++] = bst2[j++];
    }

    return ans;
}

TreeNode* inorderToBST(int start, int end, vector<int> &in) {

    // base case
    if (start > end) {
        return NULL;
    }

    // find mid
    int mid = end + (start - end) / 2;

    // create a node for the middle data
    TreeNode* newNode = new TreeNode(in[mid]);

    // do same for left and right, rest reccurssion will handle
    newNode->left = inorderToBST(start, mid-1, in);
    newNode->right = inorderToBST(mid+1, end, in);

    return newNode;
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    // #1. find inorder of both BST's 
    vector<int> bst1;
    vector<int> bst2;

    inorder(root1, bst1);
    inorder(root2, bst2);

    // #2. merge both inorder 
    vector<int> mergedArray = mergeArrays(bst1, bst2);

    // // #3. create bst using inorder
    // int s = 0, e = mergedArray.size()-1;
    // return inorderToBST(s, e, mergedArray);

    return mergedArray;
}