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
void left_traversal(Node* root, vector<int> &result){

    if(root == NULL)
        return;

    if(root->left == NULL && root->right == NULL){
        return;
    }

    result.push_back(root->data);

    if(root->left){
        left_traversal(root->left, result);
    }
    else{
        left_traversal(root->right, result);
    }
}
void leaf_node_traversal(Node* root, vector<int> &result){
    //base case
    if(root == NULL){
        return;
    }

    if(root->left == NULL && root->right == NULL){
        result.push_back(root->data);
        return;
    }

    leaf_node_traversal(root->left, result);
    leaf_node_traversal(root->right, result);

}
void right_traversal(Node* root, vector<int> &result){
    if(root == NULL)
        return;

    if(root->left == NULL && root->right == NULL)
        return;


    if(root->right){
        right_traversal(root->right, result);
    }
    else{
        right_traversal(root->left, result);
    }
    result.push_back(root->data);

}
vector<int> boundary_traversal(Node* root){
    vector<int> result;
    if(root == NULL)
        return result;

    result.push_back(root->data);

    left_traversal(root->left, result);

    leaf_node_traversal(root, result);

    right_traversal(root->right, result);

    return result;
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(4);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);

    root->right->right = new Node(7);
    root->right->right->right = new Node(9);
    root->right->right->right->left = new Node(10);
    root->right->right->right->right = new Node(11);

    vector<int> ans = boundary_traversal(root);
    for(auto i : ans){
        cout << i << " ";
    }
    return 0;
}