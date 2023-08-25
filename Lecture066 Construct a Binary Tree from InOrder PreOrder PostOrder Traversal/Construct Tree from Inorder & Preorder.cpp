//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

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
    
    int findposition(int element , int in[] , int start , int end)
    {
        for(int i = start ; i <= end ; i++)
        {
            if(in[i] == element)
            {
                return i;
            }
        }
        return -1;
    }
    
    Node* solve(int in[],int pre[], int n, int& preorderindex , int inorder_start , int  inorder_end)
    {
        if(preorderindex >= n || inorder_start > inorder_end)
        {
            return NULL;
        }
        
        int element = pre[preorderindex];
        Node* root = new Node(element);
        
        int position = findposition(element,in ,inorder_start , inorder_end);
        
        preorderindex++;
        root->left = solve(in,pre,n,preorderindex, inorder_start , position - 1);
        root-> right = solve(in , pre , n , preorderindex, position + 1 , inorder_end);
        
        
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        int preorderindex = 0;
        
        Node* temp = solve(in,pre,n, preorderindex, 0 , n-1);
        
        return temp;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends