// LeetCode Solution 
class Solution {
public:
void mapping(vector<int>&inorder,map<int,int>&m){
    for(int i=0;i<inorder.size();i++){
        m[inorder[i]] = i;
    }
}
TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int&index,int inorderstart,int inorderend,map<int,int>&m){
    if((index>=inorder.size())||(inorderstart>inorderend)){
        return NULL;
    }   
    int element=preorder[index++];
    TreeNode*temp=new TreeNode(element);
    int position=m[element];
    temp->left=solve(preorder,inorder,index,inorderstart,position-1,m);
    temp->right=solve(preorder,inorder,index,position+1,inorderend,m);
    return temp;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderindex=0;
        int size=inorder.size();
        map<int,int> m;
        mapping(inorder,m);
        TreeNode*ans=solve(preorder,inorder,preorderindex,0,size,m);
        return ans;
    }
};
