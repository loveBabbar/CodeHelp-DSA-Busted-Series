void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{

    if(root == NULL)
        return;
    
    //got the element whose suc and pre is asked   
    if(root->key == key){
        //predecessor is max element of left subtree
        if(root->left){
            Node* temp = root->left;
            while(temp->right)
                temp = temp->right;
            pre = temp;
        }
        
        //successor is min element of right subtree
        if(root->right){
            Node* temp = root->right;
            while(temp->left)
                temp = temp->left;
            suc = temp;
        }
    }
    
    //if key is greater then check in right subtree and store pre
    if(root->key < key){
        pre = root;
        findPreSuc(root->right,pre,suc,key);
    }
    
    //if key is smaller then check in left subtree and store suc
    if(root->key > key){
        suc = root;
        findPreSuc(root->left,pre,suc,key);
    }

}