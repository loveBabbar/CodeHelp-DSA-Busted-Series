#include<iostream>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};


TreeNode *find(TreeNode *root, TreeNode *p, TreeNode *q){
    if(root == NULL){
        return NULL;
    }
    if(p->data <= root->data && q -> data >= root->data){
        return root;
    }
    if(p->data > root -> data){
        return find(root->right, p, q);
    }
        return find(root->left, p, q);
}


TreeNode *LCAinaBST(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if(p -> data < q -> data){
        return find(root,p,q);
    }
    if(p -> data < q -> data){
        return find(root,p,q);
    }
    return root;
}