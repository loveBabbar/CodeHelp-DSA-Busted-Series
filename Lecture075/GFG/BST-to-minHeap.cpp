// C++ implementation to convert the given
// BST to Min Heap

// https://www.geeksforgeeks.org/dsa/convert-bst-min-heap/  <- refer
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

// Function to perform inorder traversal of BST
// and store the node values in a vector
void inorderTraversal(Node* root, 
                        vector<int>& inorderArr) {
    if (root == nullptr) {
        return;
    }
  
    // Traverse the left subtree Store the current 
    // node value Traverse the right subtree
    inorderTraversal(root->left, inorderArr);  
    inorderArr.push_back(root->data);          
    inorderTraversal(root->right, inorderArr); 
}

// Function to perform preorder traversal of the tree
// and copy the values from the inorder array to nodes
void preorderFill(Node* root, vector<int>& inorderArr, 
                                          int& index) {
    if (root == nullptr) {
        return;
    }

    // Copy the next element from the inorder array
    root->data = inorderArr[index++];

    // Fill left and right subtree
    preorderFill(root->left, inorderArr, index);  
    preorderFill(root->right, inorderArr, index);
}

// Function to convert BST to Min Heap
void convertBSTtoMinHeap(Node* root) {
  
    vector<int> inorderArr;

    // Step 1: Perform inorder traversal 
    // to store values in sorted order
    inorderTraversal(root, inorderArr);

    int index = 0;

    // Step 2: Perform preorder traversal and 
    // fill nodes with inorder values
    preorderFill(root, inorderArr, index);
}

// Function to print preorder traversal of the tree
void preorderPrint(Node* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->data << " "; 
    preorderPrint(root->left); 
    preorderPrint(root->right); 
}

int main() {
  
    // Constructing the Binary Search Tree (BST)
    //          4
    //        /   \
    //       2     6
    //      / \   / \
    //     1   3 5   7
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    convertBSTtoMinHeap(root);
    preorderPrint(root);

    return 0;
}