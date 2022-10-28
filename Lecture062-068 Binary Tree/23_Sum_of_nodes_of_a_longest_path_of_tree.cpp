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
void solve(Node* root, int len, int &maxLen, int sum, int &maxSum){
    if(root == NULL){
        if(len > maxLen){
            maxLen = len;
            maxSum = sum;
        }
        else if(len == maxLen){
            maxSum = max(sum, maxSum);
        }
        return;
    }
    sum = sum + root->data;
    
    solve(root->left, len+1, maxLen, sum, maxSum);
    solve(root->right, len+1, maxLen, sum, maxSum);
}
int sumOfRootToLeafPath(Node* root){
    int len = 0;
    int maxLen = 0;

    int sum = 0;
    int maxSum = INT_MIN;

    solve(root, len, maxLen, sum, maxSum);

    return maxSum;
} 
int main()
{
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(7);
    root->left->right = new Node(1);
    root->left->right->left = new Node(6);
    root->right->left = new Node(2);
    root->right->right = new Node(3);
    
    int ans = sumOfRootToLeafPath(root);
    cout << ans << endl;
    return 0;
}