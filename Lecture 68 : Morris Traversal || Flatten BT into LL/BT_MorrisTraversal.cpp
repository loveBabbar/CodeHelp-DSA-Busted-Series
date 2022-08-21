#include <iostream>
#include <queue>
#include <map>

using namespace std;

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

Node* find(Node* curr)
{
    curr = curr -> left;
    while (curr -> right != NULL)
    {
        curr = curr -> right;
    }
    return curr;
}

void morrisTraversal(Node* root, vector<int> &ans)
{
    Node* curr = root;

    if (root == NULL)
    {
        return;
    }
    

    while (curr != NULL)
    {
        if (!curr -> left)
        {
            ans.push_back(curr -> data);
            curr = curr -> right;
        }
        else
        {
            Node* pred = find(curr);
            if (pred -> right == NULL)
            {
                pred -> right = curr;
                curr = curr -> left;
            }
            else
            {
                pred -> right = NULL;
                ans.push_back(curr-> data);
                curr = curr -> right; 
            }
        }
        
    }
    
}

int main(int argc, char const *argv[])
{
    vector<int> ans;
    Node* root = new Node(10);
    morrisTraversal(root, ans);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " " ;
    }cout << endl;
    
    
    return 0;
}
