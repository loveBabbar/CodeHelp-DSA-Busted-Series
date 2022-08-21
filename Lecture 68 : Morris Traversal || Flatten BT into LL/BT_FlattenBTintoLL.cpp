#include <iostream>
#include <queue>
#include <map>

using namespace std;

// construct tree

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }

    
};

void flattenTree(Node *root)
{
    Node* curr = root;
    while (curr != NULL)
    {
        if (curr -> left)
        {
            Node* pred = curr -> left;
            while (pred -> right != NULL)
            {
                pred = pred -> right;
            }
            pred -> right = curr -> right;
            curr -> right = curr -> left;
            curr -> left = NULL; // curr ka left null krdo jaisa ques main bola hai
        }
        
        curr = curr -> right;
    }
}

int main(int argc, char const *argv[])
{
    Node* root = new Node(10);

    flattenTree(root);
    

    return 0;
}
