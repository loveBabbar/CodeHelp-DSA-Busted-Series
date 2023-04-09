Node* insertNode(Node* root, int key) {
        
    //base case
    if(root==NULL){
        Node* temp = new Node(key);
        return temp;
    }
    
    //key is absent so insert it
    if(root->data < key)
        root->right = insertNode(root->right,key);
    else
        root->left = insertNode(root->left,key);
        
    return root;
        
}