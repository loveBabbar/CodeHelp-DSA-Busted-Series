#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;
    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};
Node* lca(Node* root, int n1, int n2){
    if(root == NULL){
        return NULL;
    }
    if(root->data == n1 || root->data == n2){
        return root;
    }

    Node* leftAns = lca(root->left, n1, n2);
    Node* rightAns = lca(root->right, n1, n2);

    if(leftAns != NULL && rightAns != NULL){
        return root;
    }
    else if(leftAns != NULL && rightAns == NULL){
        return leftAns;
    }
    else if(leftAns == NULL && rightAns != NULL){
        return rightAns;
    }
    else{
        return NULL;
    }
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(6);
    root->left->left->right = new Node(8);
    root->right->left = new Node(4);
    root->right->right = new Node(5);
    root->right->right->left = new Node(21);

    int n1 = 4;
    int n2 = 21;

    Node* ancestor = lca(root, n1, n2);
    cout << ancestor->data << endl;

    return 0;
}