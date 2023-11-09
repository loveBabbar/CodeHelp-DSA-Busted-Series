Iterative
bool searchInBST(BinaryTreeNode<int> *root, int x) {
    // Write your code here.
    BinaryTreeNode<int>* current = root;
    while(current){
        if(current->data == x) return true;
        if(current->data>x) current=current->left;
        else current=current->right;
    }
    return false;
}
Recursive 
bool searchInBST(BinaryTreeNode<int> *root, int x) {
    if (!root)
        return false;
    if (root->data == x)
        return true;

    if (root->data > x)
        searchInBST(root->left, x);
    else
        searchInBST(root->right, x);
}
}
