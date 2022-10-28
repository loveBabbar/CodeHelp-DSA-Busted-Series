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
int height(Node* root){
    //base case
    if(root == NULL){
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);

    int ans = max(left, right) + 1;
    return ans;
}
int diameter(Node* root){
    //base case
    if(root == NULL)
        return 0;

    //start
    int op1 = diameter(root->left);
    int op2 = diameter(root->right);
    int op3 = height(root->left) + height(root->right) + 1; // here time complexity is O(n^2)
    // int op3 = height(root);

    int ans = max(op1, max(op2, op3));
    return ans;
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(5);
    root->left->right = new Node(6);
    root->left->right->left = new Node(10);

    int ans = diameter(root);
    cout << ans << endl;
    return 0;
}