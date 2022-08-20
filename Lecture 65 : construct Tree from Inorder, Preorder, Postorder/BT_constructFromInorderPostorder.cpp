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

class Solution
{
    public:

    void createMapping(int in[], map<int, int> &nodeToIndex, int n)
    {
        for (int i = 0; i < n; i++)
        {
            nodeToIndex[in[i]] = i;
        }
        
    }

    Node* solve(int in[], int post[], int &index, int inorderStart, int inorderEnd, int n, map<int, int> &nodeToIndex)
    {
        if (index < 0 || inorderStart > inorderEnd)
        {
            return NULL;
        }

        // create a root node for element
        int element = post[index--];// index is decremented after initialisation
        Node* root = new Node(element);
        // find element's index in inorder
        int position = nodeToIndex[element]; // M2
        // M1 : int position = findPosition(in, element, n);

        // recursive calls
        root -> right = solve(in, post, index, position + 1, inorderEnd, n, nodeToIndex);
        root -> left = solve(in, post, index, inorderStart, position - 1, n, nodeToIndex);

        return root;
    }

    Node* bulidTree(int in[], int post[], int n)
    {
        int postOrderIndex = n - 1;
        map<int, int> nodeToIndex; // map to find position
        createMapping(in, nodeToIndex, n);
        
        Node* ans = solve(in, post, postOrderIndex, 0, n-1, n, nodeToIndex); // 0 is the starting index of inorder and n-1 is the ending index of inorder
        return ans;
    }
};