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
bool isIdentical(Node* f_root, Node* s_root){
    if(f_root == NULL && s_root == NULL){
        return true;
    }
    if(f_root == NULL && s_root != NULL){
        return false;
    }
    if(f_root != NULL && s_root == NULL){
        return false;
    }
    
    bool left = isIdentical(f_root->left, s_root->left);
    bool right = isIdentical(f_root->right, s_root->right);

    bool val = f_root->data == s_root->data;

    if(left && right && val)
        return true;

    else    
        return false;
    
}
int main()
{
    Node* root = new Node(10);
    root->left = new Node(80);
    root->right = new Node(70);

    root->left->right = new Node(45);
    root->left->left = new Node(56);
    root->right->left = new Node(60);
    root->right->right = new Node(11);


    Node* Joeroot = new Node(10);
    Joeroot->left = new Node(80);
    Joeroot->right = new Node(70);

    Joeroot->left->right = new Node(45);
    Joeroot->left->left = new Node(56);
    Joeroot->right->left = new Node(60);
    Joeroot->right->right = new Node(11);


    bool ans = isIdentical(root, Joeroot);

    cout << ans << endl;

    return 0;
}