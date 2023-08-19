// here is the diameter question solution with O(n) code very simple without the pair , height function.

class Solution {

    private:
    int solve(TreeNode* root,int &d)
    {
        if(root==NULL) return 0 ;
        int ld = solve(root->left,d);
        int rd = solve(root->right, d);
        d = max(d,ld+rd);
        int temp = max(ld,rd)+1;
        return temp;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        solve(root,diameter);
        return diameter;
    }
};
