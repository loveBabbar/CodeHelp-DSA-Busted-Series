
//NOTE:- map will not work cause input array can have duplicate elements
int findposition(int in[], int element, int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        if (in[i] == element)
            return i;
    }
    return -1;
}
Node *solve(int in[], int pre[], int &index, int inorderstart, int inorderend, int n)
{
    if (index >= n || inorderstart > inorderend)
    {
        return NULL;
    }

    int element = pre[index++];//finding element in inorder array
    Node *root = new Node(element);//creating new node 
    int position = findposition(in, element, inorderstart, inorderend);

    //recursive call for left and right subarray
    root->left = solve(in, pre, index, inorderstart, position - 1, n);
    root->right = solve(in, pre, index, position + 1, inorderend, n);

    return root;
}
Node *buildTree(int in[], int pre[], int n)
{
    // Code here
    int preorderindex = 0;
    Node *ans = solve(in, pre, preorderindex, 0, n - 1, n);
    return ans;
}

