//Flatten_a_Binary_tree_into_Linked_List
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
void printLL(Node* curr){
    while(curr != NULL){
        cout << curr->data << " ";
        curr = curr->right;
    }
}
// Predecessor
Node* find(Node* curr){
    Node* pred = curr->left;

    while(pred->right != NULL){
        pred = pred->right;
    }

    return pred;
}
Node* binary_tree_in_a_Linked_List(Node* root){
    Node* curr = root;
    while(curr != NULL){
        if(curr->left){

            Node* pred = find(curr);
            
            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
    return root;

}
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(6);

    Node* head = binary_tree_in_a_Linked_List(root);

    printLL(head);
    return 0;
}