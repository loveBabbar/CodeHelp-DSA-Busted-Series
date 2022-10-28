#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
Node* build_tree(Node* root){
    cout << "Enter the data: " ;
    int data;
    cin >> data;

    root = new Node(data);

    if(data == -1){
        return NULL;
    }

    cout << "Enter the data for left Node: " << endl;
    root->left = build_tree(root->left);

    cout << "Enter the data for right Node: " << endl;
    root->right = build_tree(root->right);
}

void level_order_traversal_separator(Node* root){
    cout << endl;

    queue <Node*> q;
    q.push(root);
    q.push(NULL);

    

    while(!q.empty()){

        Node* temp = q.front();
        q.pop();

        if(temp != NULL){
            cout << temp->data << " ";
            
            if(temp->left)
                q.push(temp->left);

            if(temp->right)
                q.push(temp->right);
        }

        else{
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }

        }
    }
}
int main()
{
    Node* root = NULL;

    root = build_tree(root);

    level_order_traversal_separator(root);
    return 0;
}