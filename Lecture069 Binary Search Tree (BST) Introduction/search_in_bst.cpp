bool search(Node* root, int key){
    if(root==NULL)
        return false;
    if(root->data==key)
        return true;
    
    if(root->data < key)//means key is present in right subtree
        return search(root->right,key);
    else//means key is present in left subtree
        return search(root->left,key);
        
}
