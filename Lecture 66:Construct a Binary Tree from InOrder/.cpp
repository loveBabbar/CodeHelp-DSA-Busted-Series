  Question 1).https://practice.geeksforgeeks.org/problems/construct-tree-1/1
  Approach 1
  class Solution{
    public:
    int findPosition(int in[], int start, int end, int data){
        for(int i = start; i <= end; i ++){
            if(in[i] == data){
                return i;
            }
        }
        return -1;
    }
    Node* solve(int in[], int pre[], int &preOrderIndex, int inOrderStart, int inOrderEnd, int n){
        if(preOrderIndex >= n || inOrderStart > inOrderEnd){
            return NULL;
        }    
        Node* root = new Node(pre[preOrderIndex++]);
        
        int position = findPosition(in, inOrderStart, inOrderEnd, root->data);
        
        root->left = solve(in, pre, preOrderIndex, inOrderStart, position - 1, n);
        root->right = solve(in, pre, preOrderIndex, position + 1, inOrderEnd, n);
        
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int preOrderIndex = 0;
        Node* result = solve(in, pre, preOrderIndex, 0, n-1, n);
        return result;
    }
};

 Approach 2
 class Solution {
public:
    void createmapping(vector<int>& inorder,map<int,int>& nodetoindex){
        for(int i=0;i<inorder.size();i++){
            nodetoindex[inorder[i]]=i;
        }
    }
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int &index,int &insize,int &presize,int instart,int inend,map<int,int> &nodetoindex){
        if(instart>inend || index>presize){
            return NULL;
        }
        int element=preorder[index++];
        int position=nodetoindex[element];
        TreeNode* root=new TreeNode(element);
        root->left=solve(preorder,inorder,index,insize,presize,instart,position-1,nodetoindex);
        root->right=solve(preorder,inorder,index,insize,presize,position+1,inend,nodetoindex);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>nodetoindex;
        createmapping(inorder,nodetoindex);
        int insize=inorder.size();
        int presize=preorder.size();
        int preorderindex=0;
        TreeNode* ans=solve(preorder,inorder,preorderindex,insize,presize,0,insize-1,nodetoindex);
        return ans;

 }
};

QUESTION2)https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
class Solution {
public:
    void createmapping(vector<int>& inorder,map<int,int>& nodetoindex){
        for(int i=0;i<inorder.size();i++){
            nodetoindex[inorder[i]]=i;
        }
    }
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,int &index,int &insize,int &postsize,int instart,int inend,map<int,int> &nodetoindex){
        if(instart>inend || index<0){
            return NULL;
        }
        int element=postorder[index--];
        int position=nodetoindex[element];
        TreeNode* root=new TreeNode(element);
        
        root->right=solve(inorder,postorder,index,insize,postsize,position+1,inend,nodetoindex);
        root->left=solve(inorder,postorder,index,insize,postsize,instart,position-1,nodetoindex);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>nodetoindex;
        createmapping(inorder,nodetoindex);
        int insize=inorder.size();
        int postsize=postorder.size();
        int postorderindex=postorder.size()-1;
        TreeNode* ans=solve(inorder,postorder,postorderindex,insize,postsize,0,insize-1,nodetoindex);
        return ans;

 }
};
