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

    int findPosition(int in[], int element, int n)
    {
        // M1 : use loop -> O(n)
        for (int i = 0; i < n; i++)
        {
            if (in[i] == element)
            {
                return i;
            }
            
        }

        // M2 : use Map -> O(1)
        // store the index of element in map and return immediately. watch above funciton for code

        return -1;
    }

    Node* solve(int in[], int pre[], int &index, int inorderStart, int inorderEnd, int n, map<int, int> &nodeToIndex)
    {
        if (index > n || inorderStart > inorderEnd)
        {
            return NULL;
        }

        // create a root node for element
        int element = pre[index++];// index is incremented  after initialisation
        Node* root = new Node(element);
        // find element's index in inorder
        int position = nodeToIndex[element]; // M2
        // M1 : int position = findPosition(in, element, n);

        // recursive calls
        root -> left = solve(in, pre, index, inorderStart, position - 1, n, nodeToIndex);
        root -> right = solve(in, pre, index, position + 1, inorderEnd, n, nodeToIndex);

        return root;
    }

    Node* bulidTree(int in[], int pre[], int n)
    {
        int preOrderIndex = 0;
        map<int, int> nodeToIndex; // map to find position
        createMapping(in, nodeToIndex, n);
        
        Node* ans = solve(in, pre, preOrderIndex, 0, n-1, n, nodeToIndex); // 0 is the starting index of inorder and n-1 is the ending index of inorder
        return ans;
    }

};

int main(int argc, char const *argv[])
{
    
    
    return 0;
}
