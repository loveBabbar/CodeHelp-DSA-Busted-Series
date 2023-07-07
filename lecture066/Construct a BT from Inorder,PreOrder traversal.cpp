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
    int findpos(int in[],int inorderstart,int inorderend , int element , int n){
        for(int i=inorderstart; i<=inorderend ; i++){
            if(in[i]==element){
                return i;
            }
            
        }
        return -1;
    }
    Node * solve(int in[], int pre[], int &index , int inorderstart , int inorderend , int n){
        //base case
        if(index>=n || inorderstart > inorderend){
            return NULL;
        }
        int element=pre[index++];
        Node * root= new Node(element);
        int position = findpos(in, inorderstart, inorderend,element , n);
        
        //recursive calls
        //pre order- NLR  (start from 0 , left part coming so build left tree first)
        root->left=solve(in , pre , index , inorderstart, position-1, n);
        root->right=solve(in , pre , index , position+1,  inorderend , n);
        
        return root;
    }
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
       int preorderindex=0;
       Node * ans =solve(in , pre , preorderindex, 0 , n-1 , n);
       return ans;
    }
};
