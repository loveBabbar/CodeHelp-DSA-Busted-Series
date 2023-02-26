

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    int findposition(int in[], int element,int n){
        for(int i=0;i<n;i++){
            if(in[i]== element)
            return i;
        }
        return -1;
    }
    Node* solve(int in[],int pre[],int &index , int inorderStart, int inorderEnd,int n){
        if(index>=n || inorderStart>inorderEnd){
            return NULL;
        }
        int element = pre[index++];
        Node* root = new Node(element);
        int position = findposition(in,element,n);
        root->left = solve(in,pre,index,inorderStart,position-1,n);
        root->right = solve(in, pre,index,position+1,inorderEnd,n);
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
            int preOrderIndex = 0;
       Node* ans = solve(in,pre,preOrderIndex,0,n-1,n);
       return ans;
    }
};
