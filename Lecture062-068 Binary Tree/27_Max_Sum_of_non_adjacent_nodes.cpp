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
pair<int, int> solve(Node* root){
    //base case
    if(root == NULL){
        pair<int, int> p = make_pair(0, 0);
        return p;
    }
    pair<int, int> left = solve(root->left);
    pair<int, int> right = solve(root->right);

    pair<int, int> res;

    res.first = root->data + left.second + right.second;
    res.second = max(left.first, left.second) + max(right.first, right.second);

    return res;
}
int maxSumNonAdjNodes(Node* root){
    pair<int, int> ans = solve(root);
    return max(ans.first, ans.second);
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);

    int ans = maxSumNonAdjNodes(root);
    cout << ans << endl;
    return 0;
}