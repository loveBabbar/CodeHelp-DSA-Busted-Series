#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printPostOrder(Node *root)
{
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
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
class Solution
{
public:
    // for creating map of inorder array element with their index
    void createMapping(int in[], map<int, int> &nodeToIndex, int n)
    {
        for (int i = 0; i < n; i++)
            nodeToIndex[in[i]] = i;
    }
    Node *solve(int in[], int pre[], int n, int &index, map<int, int> &nodeToIndex, int inorderStart, int inorderEnd)
    {
        // base case
        if (index >= n || inorderStart > inorderEnd)
            return NULL;

        int element = pre[index++];
        Node *root = new Node(element);
        int position = nodeToIndex[element];

        // recursive function
        root->left = solve(in, pre, n, index, nodeToIndex, inorderStart, position - 1);
        root->right = solve(in, pre, n, index, nodeToIndex, position + 1, inorderEnd);

        return root;
    }
    Node *buildTree(int in[], int pre[], int n)
    {
        // Code here
        int index = 0, inorderStart = 0, inorderEnd = n - 1;
        map<int, int> nodeToIndex;
        createMapping(in, nodeToIndex, n);
        Node *root = solve(in, pre, n, index, nodeToIndex, inorderStart, inorderEnd);
        return root;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int inorder[n], preorder[n];
        for (int i = 0; i < n; i++)
            cin >> inorder[i];
        for (int i = 0; i < n; i++)
            cin >> preorder[i];
        Solution obj;
        Node *root = obj.buildTree(inorder, preorder, n);
        printPostOrder(root);
        cout << endl;
    }
}
// } Driver Code Ends