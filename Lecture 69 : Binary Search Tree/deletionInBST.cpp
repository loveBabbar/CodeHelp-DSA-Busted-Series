#include <iostream>
#include <queue>

using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {

        this -> data = d;
        this -> left = NULL;
        this -> right == NULL;

    }
};

Node* minVal(Node* root)
{
    // base case
    if (root == NULL)
    {
        return NULL;
    }
    if (root -> left == NULL)
    {
        return root;
    }
    

    minVal(root -> left);
}

Node* deleteFromBST(Node* root, int val) {

    // base case
    if (root == NULL)
    {
        return root;
    }
    if (root -> data == val)
    {
        // 0 child
        if (root -> left == NULL && root -> right == NULL)
        {
            delete root;
            return NULL; 
        }
        

        // 1 child

        // left child
        if (root -> left != NULL && root -> right == NULL)
        {
            Node* temp = root -> left;
            delete root;
            return temp;
        }
        

        // right child
        if (root -> right != NULL && root -> left == NULL)
        {
            Node* temp = root -> right;
            delete root;
            return temp;
        }
        
        // 2 child
        if (root -> left != NULL && root -> right != NULL)
        {
            int mini = minVal(root -> right) -> data;
            root -> data = mini;
            root -> right = deleteFromBST(root -> right, mini);
            return root;
        }
        

    }
    else if (root -> data > val)
    {
        root -> left = deleteFromBST(root -> left, val);
    }
    else
    {
        root -> right = deleteFromBST(root -> right, val);
    }
    
    
}

int main(int argc, char const *argv[])
{
    Node* root = NULL;

    root = deleteFromBST(root, 30);
    
    return 0;
}
