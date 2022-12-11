// Leetcode Solution 
class Solution {
public:
void mapping(vector<int>&inorder,map<int,int>&m){
    for(int i=0;i<inorder.size();i++){
        m[inorder[i]] = i;
    }
}
TreeNode* solve(vector<int>& postorder, vector<int>& inorder,int&index,int inorderstart,int inorderend,map<int,int>&m){
    if((index<0)||(inorderstart>inorderend)){
        return NULL;
    }   
    int element=postorder[index--];
    TreeNode*temp=new TreeNode(element);
    int position=m[element];
    temp->right=solve(postorder,inorder,index,position+1,inorderend,m);
    temp->left=solve(postorder,inorder,index,inorderstart,position-1,m);
    return temp;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size=inorder.size();
        int postorderindex=size-1;
        map<int,int> m;
        mapping(inorder,m);
        TreeNode*ans=solve(postorder,inorder,postorderindex,0,size-1,m);
        return ans;
    }
};
