#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution {
  public:
    int findPos(vector<int> inorder, int element) {
        
        for (int i = 0; i < inorder.size(); i++) {
            
            if (inorder[i] == element) return i;
        }
        return -1;
    }
    
    Node* solve(vector<int> inorder, vector<int> preorder, int inorderStart, int inorderEnd, int &index) {
        
        if (index >= inorder.size() || inorderStart > inorderEnd) {
            return NULL;
        }
        
        int element = preorder[index++];
        Node* root = new Node(element);
        int position = findPos(inorder, element);
        
        root->left = solve(inorder, preorder, inorderStart, position-1, index);
        root->right = solve(inorder, preorder, position+1, inorderEnd, index);
        
        return root;
    }
    
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        
        int index = 0;
        Node* root = solve(inorder, preorder, 0, inorder.size()-1, index);
        return root;
    }
};