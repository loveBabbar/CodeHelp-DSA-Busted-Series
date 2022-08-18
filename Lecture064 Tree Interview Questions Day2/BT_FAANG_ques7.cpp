#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// zig zag traversal or spiral traversal

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

class Solution{
    public:

    vector <int> zigZagTraversal(Node* root)
    {
        vector<int> result;
        if(root == NULL)
        {
            return result;
        }
        queue<Node*> q;

        q.push(root);

        bool leftToRight = true;

        while(!q.empty())
        {
            // ek level main kitne elements hain vo nikalo
            int size = q.size();
            vector<int> ans(size); // queue ke ek block main jo store hoga ek level traverse krte hue

           // level process kro

           for (int i = 0; i < size; i++)
           {
               Node* frontNode = q.front();
               q.pop();

               int index = leftToRight? i : size - i - 1;
               ans[index] = frontNode -> data;

               if (frontNode -> left)
               {
                   q.push(frontNode -> left);
               }
               if (frontNode -> right)
               {
                   q.push(frontNode -> right);
               }
               // change flag
               leftToRight = !leftToRight; // true hai toh false ho jayega aur false hai toh true ho jauyega
            
           }
           
           // result vale array main daalo ans vale array ki value
           for(auto int i : ans)
           {
               result.push_back(i);
           }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    
    
    return 0;
}
