#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d)
    {
        this->data=d;
        this->right=NULL;
        this->left=NULL;
    }
};
Node* insertIntoBST(Node* &root,int d)
{
    if(root==NULL)
    root =new Node(d);
    return root;
    if(d>root->data)
    {
        //insert in right part
        root->right=insertIntoBST(root->right,d);
    }
    else{
        // insert into left part
         root->left=insertIntoBST(root->left,d);
    }
    return root;

}
void takeInput(Node* &root)
{
    int data;
    cin>>data;
    while(data!=-1)
    {
        root= insertIntoBST(root,data);
        cin>>data;


    }
}
void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            cout << endl;
            if(!q.empty()) { 
                //queue still has some child nodes
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }

}

int main()
{
    Node* root =NULL;
    cout<<"ENTER DATA TO ADD IN BST"<<endl;
    takeInput(root);
    cout<<"THE BST IS :"<<endl;
    levelOrderTraversal(root);
return 0;
}
