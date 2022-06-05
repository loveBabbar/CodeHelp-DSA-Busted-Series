// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    //create mapping 
    //return target node
    Node *createParentMapping(Node *root,int target,map<Node *,Node *> &nodeToParent){
        Node *res=NULL;
        queue<Node *> q;
        q.push(root);
        nodeToParent[root]=NULL;
        while (!q.empty())
        {
            Node *frontNode=q.front();
            q.pop();
            if(frontNode->data==target){
                res=frontNode;
            }
            if(frontNode->left){
                nodeToParent[frontNode->left]=frontNode;
                q.push(frontNode->left);
            }
            if(frontNode->right){
                nodeToParent[frontNode->right]=frontNode;
                q.push(frontNode->right);
            }
        }
        return res;
        
    }
    void burnTree(Node *root,map<Node *,Node *> nodeToParent,int &ans){
        map<Node *,bool> visited;
        queue<Node *> q; 
        q.push(root);
        // int ans=0;
        bool flag=false;
        while (!q.empty())
        {
            int size=q.size();
            for (int i = 0; i < size; i++)
            {
                Node *front=q.front();
                q.pop();
                if(front->left and !visited[front->left]){
                    q.push(front->left);
                    visited[front->left]=true;
                    flag=true;
                    
                }
                if(front->right and !visited[front->right]){
                    q.push(front->right);
                    visited[front->right]=true;
                    flag=true;
                }
                if(nodeToParent[front] and !visited[nodeToParent[front]]){
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]]=true;
                    flag=true;
                }
            }
            if(flag==true){
                ans++;
            }
            flag=false;
        }
        

    }
    int minTime(Node* root, int target) 
    {
        // create nodetoparent mapping
        //find target node
        //burn the tree
        int ans=0;
        map<Node *,Node *> nodeToParent; 
        Node *targetNode=createParentMapping(root,target,nodeToParent);
        burnTree(targetNode,nodeToParent,ans);
        
        return ans;
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends