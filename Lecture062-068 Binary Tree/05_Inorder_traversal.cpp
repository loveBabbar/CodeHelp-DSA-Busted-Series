#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;
    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
// Recursion approach
void inorder_traversal(Node* root){
    if(root == NULL){
        return;
    }
    inorder_traversal(root->left);
    cout << root->data << " ";
    inorder_traversal(root->right);
}
int main()
{
    Node* root = new Node(49);
    root->left = new Node(12);
    root->right = new Node(15);
    root->left->left = new Node(62);
    root->left->right = new Node(98);
    root->right->left = new Node(35);

    inorder_traversal(root);

    return 0;
}