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
void level_order_traversal(Node* root, stack<int> &s){
    cout << endl;
    queue <Node*> q;

    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        cout << temp->data << " ";
        s.push(temp->data);

        if(temp->left){
            q.push(temp->left);
        }

        if(temp->right){
            q.push(temp->right);
        }
    }

}
void show(stack <int> s){
    cout << endl;
    cout << "reverse order printing ";
    while(!s.empty()){
        int d = s.top();
        s.pop();
        cout << d << " ";
    }
}
int main()
{
    Node* root = new Node(3);
    
    root->left = new Node(4);
    root->left->left = new Node(15);
    root->left->right = new Node(13);
    root->right = new Node(8);
    root->right->left = new Node(76);
    root->right->right = new Node(55);

    stack <int> s;

    level_order_traversal(root, s);

    show(s);
    

    return 0;
}