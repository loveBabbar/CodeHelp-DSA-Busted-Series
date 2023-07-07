/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
int findpos(int in[],int inorderstart,int inorderend , int element , int n){
        for(int i=inorderstart; i<=inorderend ; i++){
            if(in[i]==element){
                return i;
            }
            
        }
        return -1;
    }
    
      
    Node * solve(int in[], int post[], int &index , int inorderstart , int inorderend , int n){
        //base case
        if(index<0 || inorderstart > inorderend){
            return NULL;
        }
        
        int element=post[index--];
        Node * root= new Node(element);
        int position = findpos(in, inorderstart, inorderend,element , n);
        
        //recursive calls
        //post order- LRN  (start from n-1 , right part coming so build right tree first)
        root->right=solve(in , post , index , position+1,  inorderend , n);
        root->left=solve(in , post , index , inorderstart, position-1, n);
        
        
        return root;
    }
Node *buildTree(int in[], int post[], int n) {
      int postorderindex=n-1;
       Node * ans =solve(in , post, postorderindex, 0 , n-1 , n);
       return ans;
}










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
  
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
     
    }
};
