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
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        
        inorder(root,ans);
        int start = 0;
        int end = ans.size()-1;
        while(start<end){
            if(ans[start]+ans[end]==k){
                return true;
            }
            else if(ans[start]+ans[end]>k){
                end--;
            }
            else if(ans[start]+ans[end]<k){
                start++;
            }
        }
        
        return false;
    }
};

//Optimal Solution
class Solution {
public:
    bool check(TreeNode*root,TreeNode*hold,int kk){
        if(root==NULL)return false;
        return ((root->val==kk)&&(root!=hold))||((root->val<kk) && check(root->right,hold, kk))||((root->val>kk) && check(root->left,hold, kk));
    }
    bool dfs(TreeNode*root,TreeNode*temp,int k){
        if(temp ==NULL)return false;
        return check(root,temp,k-temp->val) || dfs(root,temp->right,k) || dfs(root,temp->left,k);
    }
    bool findTarget(TreeNode* root, int k) {
        return dfs(root,root,k);
    }
};