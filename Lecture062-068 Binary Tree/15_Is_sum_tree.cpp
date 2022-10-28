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
pair<bool, int> isSumTree(Node* root){
    //base case
    if(root == NULL){
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    if(root->left == NULL && root->right == NULL){
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }
        

    pair<bool, int> left = isSumTree(root->left);
    pair<bool, int> right = isSumTree(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;

    bool cond =  (root->data == left.second + right.second);

    pair<bool, int> ans;

    if(leftAns && rightAns && cond){
        ans.first = true;

        ans.second = root->data + left.second + right.second;  //2*root->data
    }
    else{
        ans.first = false;
    }


    return ans;

    

    
}
int main()
{
    Node* root = new Node(12);
    root->left = new Node(1);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->right->left = new Node(2);
    root->right->right = new Node(3);

    pair<bool, int> ans = isSumTree(root);
    
    cout << ans.first << endl;
    cout << ans.second << endl;

    return 0;
}