#include <bits/stdc++.h>
using namespace std;

class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    
    int countNodes (Node* tree) {
        
        if (tree == NULL) {
            return 0;
        }
        
        int ans = 1 + countNodes(tree->left) + countNodes(tree->right);
        return ans;
    }
    
    bool isCBT(Node* root, int index, int totalCount) {
        
        if (root == NULL) return true;
        
        if (index >= totalCount) return false;
        
        else {
            bool left = isCBT(root->left, 2 * index + 1, totalCount);
            bool right = isCBT(root->right, 2 * index + 2, totalCount);
            
            return left && right;
        }
    }
    
    bool isMaxOrder(Node* root) {
        
        if (root->left == NULL && root->right == NULL) {
            return true;
        }
        
        if (root->right == NULL) {
            return (root->data > root->left->data);
        }
        else {
            bool left = isMaxOrder(root->left);
            bool right = isMaxOrder(root->right);
            
            return left && right && (root->data > root->left->data 
                        && root->data > root->right->data);
        }
    }
    
    bool isHeap(Node* tree) {
        // code here
        
        int index = 0;
        int totalCount = countNodes(tree);
        if (isCBT(tree, index, totalCount) && isMaxOrder(tree)) {
            return true;
        }
        return false;
    }
};