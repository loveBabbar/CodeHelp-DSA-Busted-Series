#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

class Solution {
  public:
    void createMapping(vector<int> inorder, map<int, int> &nodeToIndex) {
        
        for (int i = 0; i < inorder.size(); i++) {
            nodeToIndex[inorder[i]] = i;
        }
    }
    
    Node* solve(vector<int> inorder, vector<int> postorder, int inorderStart, int inorderEnd, int &index, map<int, int> nodeToIndex) {
        
        if (index < 0 || inorderStart > inorderEnd) {
            return NULL;
        }
        
        int element = postorder[index--];
        Node* root = new Node(element);
        int position = nodeToIndex[element];
        
        root->right = solve(inorder, postorder, position+1, inorderEnd, index, nodeToIndex);
        root->left = solve(inorder, postorder, inorderStart, position-1, index, nodeToIndex);
        
        return root;
    }
    
    Node *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // code here
        int index = postorder.size()-1;
        
        // create a mapping for inorder elements
        map<int, int> nodeToIndex;
        createMapping(inorder, nodeToIndex);
        
        Node* root = solve(inorder, postorder, 0, inorder.size()-1, index, nodeToIndex);
        return root;
        
    }
};