#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

// Boundary Traversal

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class Solution 
{
    public:
    
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }
        
        map<int, int> topNode;
        queue<pair<Node*, int> >q;

        q.push(make_pair(root, 0));

        while (!q.empty())
        {
            pair<Node*, int> temp = q.front();
            q.pop();

            Node* frontNode = temp.first;
            int hd = temp.second;

            // if one value is present for a hd, then do nothing
            if (topNode.find(hd) == topNode.end())
            {
                topNode[hd] = frontNode -> data;

            }
            if (frontNode -> left)
            {
                q.push(make_pair(frontNode -> left, hd - 1));
            }
            if (frontNode -> right)
            {
                q.push(make_pair(frontNode->right, hd + 1));
            }
            
            
        }

        // for(auto i : topNode)
        // {
        //     ans.push_back(i.second);
        // }
        // return ans;
    }
};