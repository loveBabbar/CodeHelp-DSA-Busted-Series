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
    if(root == NULL)
        return 0;
    
    int left = height(root->left);
    int right = height(root->right);

    int ans = max(left, right) + 1;
    return ans;
}
int main()
{
    Node* root = new Node(10);
    root->left = new Node(78);
    root->right = new Node(12);
    root->left->left = new Node(56);

    int ans = height(root);
    cout << ans;

    return 0;
}