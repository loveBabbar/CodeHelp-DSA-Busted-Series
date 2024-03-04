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

class Solution{
    public:
  
    Node* buildTree(int in[],int pre[], int n)
    {
        if( n == 0 ){
            return NULL;
        }
        
        if( n == 1){
            Node* ans = new Node(in[0]);
            return ans;
        }
        


	    // ! to optimize we can use map
   		// !     |
    	// !    \/ 
        int i = 0;
        while( in[i] != pre[0]){
            i++;
        }
        
        
        Node* ans = new Node(pre[0]);
        ans -> left = buildTree(in,pre+1,i);
        ans -> right = buildTree(in+i+1,pre+1+i,n-i-1);
        return ans;
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