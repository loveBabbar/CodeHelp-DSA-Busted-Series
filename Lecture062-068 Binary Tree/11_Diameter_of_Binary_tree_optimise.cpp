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
pair<int, int> diameter_fast(Node* root){
    if(root == NULL){
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    pair<int, int> left = diameter_fast(root->left);
    pair<int, int> right = diameter_fast(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second) + 1;

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

    pair<int, int> ans = diameter_fast(root);
    cout << ans.first << endl;
    // cout << ans.second << endl;
    return 0;
}