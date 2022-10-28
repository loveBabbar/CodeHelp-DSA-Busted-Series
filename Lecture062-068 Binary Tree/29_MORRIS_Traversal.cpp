//Morris Traversal
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
// Predecessor
Node* find(Node* curr){
    Node* pred = curr->left;

    while(pred->right != NULL && pred->right != curr){
        pred = pred->right;
    }

    return pred;
}
void MorrisTraversal(Node* root){
    Node* curr = root;
    while(curr != NULL){
        if(curr->left == NULL){
            cout << curr->data << " ";
            curr = curr->right;
        }

        else{
            Node* pred = find(curr);

            if(pred->right == NULL){
                pred->right = curr;
                curr = curr->left;
            }
            else{
                pred->right = NULL;
                cout << curr->data << " ";
                curr = curr->right;
            }
        }
    }
    cout << endl;
}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->left->right = new Node(7);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    MorrisTraversal(root);
    return 0;
}