void inorder(Node *root, int &k, int &ans)
{

    if (root == NULL)
        return;

    inorder(root->left, k, ans);

    k--;
    if (k == 0)
    {
        ans = root->data;
        return;
    }

    inorder(root->right, k, ans);
}

// Return the Kth smallest element in the given BST
int KthSmallestElement(Node *root, int K)
{

    int ans = -1;
    inorder(root, K, ans);
    return ans;
}