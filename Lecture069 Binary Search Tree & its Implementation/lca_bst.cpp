/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//BHAIYA SOLUTION
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root!=NULL){
            if(root->val < p->val && root->val < q->val){
                root = root->right;
            }
            else if(root->val > p->val && root->val > q->val){
                root = root->left;
            }
            else{
                return root;
            }
        }

        return nullptr;
    }
};

//OPTIMAL SOLUTION

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    vector<TreeNode*> getPath(TreeNode* root, TreeNode*p) {
        vector<TreeNode*> path;
        
        while(root != p) {
            path.emplace_back(root);
            
            if(root->val > p->val)
                root = root->left;
            else
                root = root->right;
        }
        
        path.emplace_back(root);
        
        return path;

    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto const pPath = getPath(root, p);
        auto const qPath = getPath(root, q);
        
        TreeNode* minNode= new TreeNode(numeric_limits<int>::max());
        
        int n = min(pPath.size(), qPath.size());
        
        for (int i = 0; i < n; i++) {
            if (pPath[i]->val != qPath[i]->val)
                break;
            
                minNode = pPath[i];
        }
        
        return minNode;
    }
};