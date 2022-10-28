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
void solve(Node* root, vector<int> &ans, int level){
    if(root == NULL)
        return;

    if(level == ans.size())
        ans.push_back(root->data);

    solve(root->left, ans, level+1);
    solve(root->right, ans, level+1);
}
vector<int> leftView(Node* root){
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}
int main(){
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(50);
    root->left->right = new Node(60);
    root->right->left = new Node(80);
    root->right->right = new Node(90);

    vector<int> ans = leftView(root);

    for(auto i:ans){
        cout << i << " ";
    }

}