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
void calculate_leaf_node(Node* root, int &cnt){

    if(root == NULL)
        return;

    if(root->left == NULL && root->right == NULL){
        cnt++;
    }

    calculate_leaf_node(root->left, cnt);
    calculate_leaf_node(root->right, cnt);

    

}
int main()
{
    Node* root = new Node(49);
    root->left = new Node(12);
    root->right = new Node(15);
    root->left->left = new Node(62);
    root->left->right = new Node(98);
    root->right->left = new Node(35);
    root->right->right = new Node(87);

    int cnt = 0;
    calculate_leaf_node(root, cnt);

    cout << cnt << endl;
    

    return 0;
}