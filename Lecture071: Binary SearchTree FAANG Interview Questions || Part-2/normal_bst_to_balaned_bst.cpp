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
private:
    void inorder(TreeNode* root,vector<int> &a){
        if(root==NULL){
            return;
        }

        inorder(root->left,a);
        a.push_back(root->val);
        inorder(root->right,a);
    }

    TreeNode* inorderToBst(int start,int end,vector<int> &a){
        if(start>end){
            return NULL;
        }
        int mid = start + (end-start)/2;

        TreeNode* temp = new TreeNode(a[mid]);
        temp->left = inorderToBst(start,mid-1,a);
        temp->right = inorderToBst(mid+1,end,a);

        return temp;
    }    
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);

        return inorderToBst(0,ans.size()-1,ans);
    }
};