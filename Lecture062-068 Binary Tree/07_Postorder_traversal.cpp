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
void postorder_traversal(Node* root){
    //base case
    if(root == NULL){
        return;
    }
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    cout << root->data << " ";
}
int main()
{
    Node* root = new Node(49);
    root->left = new Node(12);
    root->right = new Node(15);
    root->left->left = new Node(62);
    root->left->right = new Node(98);
    root->right->left = new Node(35);

    postorder_traversal(root);

    return 0;
}