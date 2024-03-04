#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int x){
        this->data = x;
        this->left = NULL;
        this->right = NULL;
    }
};

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()){
        Node* temp = q.front();
        q.pop();
        if( temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << temp -> data << " ";
            if(temp -> left){
                q.push(temp -> left);
            }
            else{
                // cout << "N ";
            }
            if(temp -> right){
                q.push(temp -> right);
            }
            else{
                // cout << "N ";
            }
            // q.push(NULL);
        }
    }
    
    
}

Node* Insert(Node* root, int x){
    if(root == NULL){
        Node* temp = new Node(x);
        return temp;
    }
    int t = root->data;
    if( t > x)
        root -> left = Insert(root->left,x);
    else
        root -> right = Insert(root->right,x);
    
    return root;
}

int maxValue(Node* root){
    while( root -> right != NULL)
        root = root -> right;
    
    return root -> data;
}

int minValue(Node* root){
    while( root -> left != NULL)
        root = root -> left;
    
    return root -> data;
}

Node* Delete(Node* root, int x){
    if(root == NULL){
        return NULL;
    }

    if( root -> data  == x){
        // 0 child
        if( root -> left == NULL && root -> right == NULL){
            delete root;
            return NULL;
        }

        // 1 child
        if( root -> left == NULL && root -> right != NULL){
            Node* temp = root -> right;
            delete root;
            return temp;
        }
        if( root -> left != NULL && root -> right == NULL){
            Node* temp = root -> left;
            delete root;
            return temp;
        }

        //  2 children
        if( root -> left != NULL && root -> right != NULL){
            int mini = minValue(root -> right);
            root -> data = mini;
            root -> right = Delete(root -> right, mini);
            return root;
        }

    }
    else if( root -> data  > x ){
        root -> left = Delete(root -> left,x);
        return root;
    }
        root -> right = Delete(root -> right,x);
        return root;
    

}

void takeInput(Node* &root){
    int d;
    cin >> d;
    while(d != -1){
        root = Insert(root,d);
        cin >> d;
    }
}

int main(){
    Node* root = NULL;
    takeInput(root);
    levelOrderTraversal(root);
    root = Delete(root,5);
    levelOrderTraversal(root);

return 0;
}