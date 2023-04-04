bool solve(Node *root, int start, int end)
{
    // base case
    if (root == NULL)
        return true;

    // value of node is within range
    if (start < root->data && root->data < end)
    {
        bool left = solve(root->left, start, root->data);
        bool right = solve(root->right, root->data, end);

        if (left && right)
            return true;
        else
            return false;
    }
    else
        return false;
}


// Function to check whether a Binary Tree is BST or not.
bool isBST(Node *root)
{
    bool ans = solve(root, INT_MIN, INT_MAX);
    return ans;
}