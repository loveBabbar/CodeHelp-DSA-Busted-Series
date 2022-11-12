

//-> Insertion <-
//Recursive(188ms)
TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            root = new TreeNode(val);
            return root;
        }

        if(val > root->val){
            root->right = insertIntoBST(root->right,val);
        }
        else{
            root->left = insertIntoBST(root->left,val);
        }

        return root;
}

//Iterative(68ms)
TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) return new TreeNode(val);
        TreeNode* cur=root;
        while(root){
            if(cur->val<=val){
                if(cur->right!=NULL) cur=cur->right;
                else{
                    cur->right=new TreeNode(val);
                    break;
                }
            }
            else{
                if(cur->left!=NULL) cur=cur->left;
                else{
                    cur->left=new TreeNode(val);
                    break;
                }
            }
        }
        return root;
}

//Practice Link
//https://leetcode.com/problems/insert-into-a-binary-search-tree/description/