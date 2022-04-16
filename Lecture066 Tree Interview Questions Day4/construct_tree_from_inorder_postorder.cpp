#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node *node)
{
    if (node == NULL)
        return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node *buildTree(int in[], int post[], int n);

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++)
            cin >> in[i];
        for (int i = 0; i < n; i++)
            cin >> post[i];
        Node *root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

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

// Function to return a tree created from postorder and inoreder traversals.

void createMapping(int in[], map<int, int> &nodeToIndex, int n)
{
    for (int i = 0; i < n; i++)
        nodeToIndex[in[i]] = i;
}
Node *solve(int in[], int post[], int n, int &index, map<int, int> &nodeToIndex, int inorderStart, int inorderEnd)
{
    // base case
    if (index < 0 || inorderStart > inorderEnd)
        return NULL;

    int element = post[index--];
    Node *root = new Node(element);
    int position = nodeToIndex[element];

    // Building Tree from inorder and postorder right comes first because index starts from end
    root->right = solve(in, post, n, index, nodeToIndex, position + 1, inorderEnd);
    root->left = solve(in, post, n, index, nodeToIndex, inorderStart, position - 1);

    return root;
}
Node *buildTree(int in[], int post[], int n)
{
    // Your code here
    int index = n - 1, inorderStart = 0, inorderEnd = n - 1;
    map<int, int> nodeToIndex;
    createMapping(in, nodeToIndex, n);
    Node *root = solve(in, post, n, index, nodeToIndex, inorderStart, inorderEnd);
    return root;
}