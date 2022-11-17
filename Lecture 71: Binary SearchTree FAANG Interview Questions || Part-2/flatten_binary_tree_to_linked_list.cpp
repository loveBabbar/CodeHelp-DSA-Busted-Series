/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 //Time Taken = 3ms
class Solution {
private:
    void inorder(TreeNode* root,vector<int> &a){
        if(root==NULL){
            return;
        }
        a.push_back(root->val);
        inorder(root->left,a);
        
        inorder(root->right,a);
    }    
public:
    void flatten(TreeNode* root) {
        vector<int> a;
        inorder(root,a);


        TreeNode* curr = root;

        for(int i=1;i<a.size();i++){
            TreeNode* temp = new TreeNode(a[i]);

            curr->left = NULL;
            curr->right = temp;
            curr = temp;
        }

    }
};

//Optimal
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
TreeNode* helper(TreeNode* node){
    if(node== NULL) return node;
    if(node->left == NULL and node->right == NULL) return node;
    TreeNode* left = helper(node->left);
    TreeNode* right = helper(node->right);
    
    if(left and right){
       left->right=node->right;
       node->right=node->left;
       node->left = NULL;
    }
    else if(left){
        left->right = node->right;
        node->right = node->left;
        node->left = NULL;
        return left;
    }
    
    return right;
}
//     TreeNode* helper(TreeNode* node){
//         if(node == NULL) return node;
//         if(node->left == NULL and node->right == NULL ) return node;
        
//         TreeNode* left = helper(node->left);
//         TreeNode*right = helper(node->right);
        
//         if(left and right){
//             left->right = node->right;
//             node->right = node->left;
//             node->left = NULL;
//         }
//         if(left){
//             left->right = node->right;
//             node->right = node->left;
//             node->left = NULL;
//             return left;
            
            
//         }
//         return right;
//     }
    
    void flatten(TreeNode* root) {
        helper(root);
    }
};

