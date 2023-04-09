/*struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};*/

class Solution
{

    class info
    {
    public:
        int maxi;
        int mini;
        bool isBst;
        int size;
    };

    info solve(Node *root)
    {

        if (root == NULL)
            return {INT_MIN, INT_MAX, true, 0};

        info left = solve(root->left);
        info right = solve(root->right);

        info curr;
        curr.maxi = max(right.maxi, root->data);
        curr.mini = min(left.mini, root->data);

        if (left.isBst && right.isBst && (root->data > left.maxi && root->data < right.mini))
        {
            curr.isBst = true;
            curr.size = left.size + right.size + 1;
        }
        else
        {
            curr.isBst = false;
            curr.size = max(left.size, right.size);
        }
        return curr;
    }

public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
        info x = solve(root);
        return x.size;
    }
};