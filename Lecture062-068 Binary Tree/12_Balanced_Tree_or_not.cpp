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
bool isBalanced(Node* root){
    //base case
    if(root == NULL)
        return true;

    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);
    bool diff = abs(height(root->left) - height(root->right) <= 1);

    if(left && right && diff)
        return true;

    else
        return false;
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(7);
    root->left->right->left = new Node(8);
    root->right->right = new Node(9);

    // Node* root = new Node(12);
    // root->left = new Node(2);
    // root->left->left = new Node(3);

    //Time complexity is O(n^2)

    bool ans = isBalanced(root);
    cout << ans << endl;
    return 0;
}