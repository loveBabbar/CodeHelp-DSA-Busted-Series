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
pair<bool, int> isBalanced(Node* root){
    if(root == NULL){
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    pair<int, int> left = isBalanced(root->left);
    pair<int, int> right = isBalanced(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;

    bool diff = abs(left.second - right.second) <= 1;

    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;

    if(leftAns && rightAns && diff){
        ans.first = true;
    }
    else{
        ans.first = false;
    }

    // cout << "root data " << root->data << " " << ans.first << " " << ans.second << endl;
    return ans;

    
}
int main()
{
    Node* root = new Node(12);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(7);
    root->left->right->left = new Node(8);
    root->right->right = new Node(9);

    pair<bool, int> ans =  isBalanced(root);

    cout << ans.first << endl;

    return 0;
}