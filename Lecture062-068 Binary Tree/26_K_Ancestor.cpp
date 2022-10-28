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
Node* solve(Node* root, int n, int &k){
    if(root == NULL)
        return NULL;

    if(root->data == n){
        return root;
    }
    Node* leftAns = solve(root->left, n, k);
    Node* rightAns = solve(root->right, n, k);

    if(leftAns != NULL && rightAns == NULL){
        k--;
        if(k <= 0){
            //answer lock
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    if(leftAns == NULL && rightAns != NULL){
        k--;
        if(k <= 0){
            //answer lock
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
}
int ancestorK(Node* root, int n, int k){
    Node* ans = solve(root, n, k);
    // edge case (ans->data == n)
    
    if(ans == NULL || ans->data == n)
        return -1;
    else{
        return ans->data;
    }
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    int k = 2;
    int n = 4;

    int ans = ancestorK(root, n, k);

    cout << ans << endl;
    
    return 0;
}