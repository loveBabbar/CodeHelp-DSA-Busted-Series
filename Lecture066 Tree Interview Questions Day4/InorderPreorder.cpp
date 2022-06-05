// { Driver Code Starts
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
    void createMapping(int in[], map<int, int> &nodeToindex, int n)
    {
        for (int i = 0; i < n; i++)
        {
            nodeToindex[in[i]] = i;
        }
    }
    Node *solve(int in[], int pre[], int &index, int inorderstart, int inorderend, int n,map<int,int> &nodeToindex)
    {
        if (index >= n || inorderstart > inorderend)
        {
            return NULL;
        }
        int element = pre[index++];
        Node *root = new Node(element);
        int position;

        position = nodeToindex[element];

        root->left = solve(in, pre, index, inorderstart, position - 1, n,nodeToindex);
        root->right = solve(in, pre, index, position + 1, inorderend, n,nodeToindex);
        return root;
    }
    Node *buildTree(int in[], int pre[], int n)
    {
        int preorderIndex = 0;
        
        map<int, int> nodeToindex;
        createMapping(in, nodeToindex, n);

        Node *ans = solve(in, pre, preorderIndex, 0, n - 1, n,nodeToindex);
        return ans;
    }
};

// { Driver Code Starts.
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