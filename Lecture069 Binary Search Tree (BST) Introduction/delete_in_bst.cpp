// Function to find the minimum value 
int minval(Node* root){
    
    while(root->left!=NULL){
        root = root->left;
    }
    return root->data;  
}

// Function to delete a node from BST.
Node *deleteNode(Node *root, int k) {
    
    if (root == NULL)
        return NULL;
 
 
    if (root->data > k) 
        root->left = deleteNode(root->left, k);
        
    else if (root->data < k)
        root->right = deleteNode(root->right, k);
    
    else{
        
        // 3 case can arise 
        
        // node with 0 child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        
        // node with 1 child
        if(root->left!=NULL && root->right==NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        if(root->right!=NULL && root->left==NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        
        //node with 2 child
        if(root->left!=NULL && root->right!=NULL){
            int mini = minval(root->right);
            root->data = mini;
            root->right = deleteNode(root->right,mini);
            return root;
        }
    }
    return root;
}