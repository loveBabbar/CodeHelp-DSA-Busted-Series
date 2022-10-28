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

    cout << "Enter the data : " ;
    int data;
    cin >> data;

    root = new Node(data);

    if(data == -1){
        return NULL;
    }
    

    cout << "Enter data for left node: " ;
    root->left = build_tree(root->left);


    cout << "Enter data for right node: ";
    root->right = build_tree(root->right);

}

void level_order_traversal(Node* root){
    cout << endl;

    queue <Node*> q;
    q.push(root);
    
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if(temp->left)  // if(temp->left != NULL)
            q.push(temp->left);

        if(temp->right)
            q.push(temp->right);
    }
}
int main()
{
    Node* root = NULL;

    root = build_tree(root);

    level_order_traversal(root);

    return 0;
}