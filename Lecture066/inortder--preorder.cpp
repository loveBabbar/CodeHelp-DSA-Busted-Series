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
    void createMapping(vector<int> inorder, map<int, int> &nodeToIndex) {
        
        for (int i = 0; i < inorder.size(); i++) {
            nodeToIndex[inorder[i]] = i;
        }
    }
    
    int findPos(vector<int> inorder, int element) {
        
        for (int i = 0; i < inorder.size(); i++) {
            
            if (inorder[i] == element) return i;
        }
        return -1;
    }
    
    Node* solve(vector<int> inorder, vector<int> preorder, int inorderStart, int inorderEnd, int &index, map<int, int> nodeToIndex) {
        
        if (index >= inorder.size() || inorderStart > inorderEnd) {
            return NULL;
        }
        
        int element = preorder[index++];
        Node* root = new Node(element);
        int position = nodeToIndex[element];
        
        root->left = solve(inorder, preorder, inorderStart, position-1, index, nodeToIndex);
        root->right = solve(inorder, preorder, position+1, inorderEnd, index, nodeToIndex);
        
        return root;
    }
    
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        
        int index = 0;
        
        // create a mapping for inorder elements
        map<int, int> nodeToIndex;
        createMapping(inorder, nodeToIndex);
        
        Node* root = solve(inorder, preorder, 0, inorder.size()-1, index, nodeToIndex);
        return root;
    }
};