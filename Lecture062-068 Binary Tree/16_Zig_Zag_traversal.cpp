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
vector<int> zig_zag_traversal(Node* root){
    vector<int> result;
    if(root == NULL){
        return result;
    }

    queue<Node*> q;
    q.push(root);

    bool leftToRight = true;

    while(!q.empty()){

        int size = q.size();
        vector<int> ans(size);

        //level process
        for(int i=0; i<size; i++){
            Node* frontNode = q.front();
            q.pop();

            int index = leftToRight ? i : size - i - 1;
            ans[index] = frontNode->data;

            if(frontNode->left){
                q.push(frontNode->left);
            }
            if(frontNode->right){
                q.push(frontNode->right);
            }

        }

        //direction change ka logic
        leftToRight = !(leftToRight);

        for(auto i : ans){
            result.push_back(i);
        }
        
    }
    return result;
} 

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(4);
    root->left->left = new Node(3);
    root->left->right = new Node(5);

    root->right->right = new Node(6);
    root->right->right->left = new Node(7);
    root->right->right->right = new Node(8);


    vector<int> ans = zig_zag_traversal(root);

    for(auto i = ans.begin(); i != ans.end(); i++){
        cout << *i << " ";
    }
    return 0;
}
