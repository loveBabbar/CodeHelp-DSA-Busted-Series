//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) 
{
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
//User function template for C++

/*
struct Node 
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution{
  public:
  
    void solve2(Node* root, int k, long long int sum, int &count){
        
        if(root == NULL){
            return;
        }
        
        sum+=root->data;
        if(sum == k){
            count++;
        }
        cout << root -> data << " " << sum << " " << count << endl;
        Node* l = root->left;
        Node* r = root->right;
        solve(r,k,sum,count);
        solve(r,k,0,count);
        solve(l,k,0,count);
        solve(l,k,sum,count);
    }
    void solve(Node* root, int k, long long int sum, int &count ,int flag = 0){
        
        if(root == NULL){
            return;
        }
        Node* l = root->left;
        Node* r = root->right;
        if(flag == 0){
        solve(r,k,0,count,0);
        solve(l,k,0,count,0);
        }
        sum+=root->data;
        if(sum == k){
            count++;
        }
        // cout << root -> data << " " << sum << " " << count << endl;
        solve(r,k,sum,count,1);
        solve(l,k,sum,count,1);
    }
    
  
    int sumK(Node *root,int k)
    {
        vector<int> path;
        int count = 0;
        solve(root,k,0,count);
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    string tc;
    getline(cin, tc);
    int t = stoi(tc);
  
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);

        string key;
        getline(cin, key);
        int k=stoi(key);
        Solution ob;
        cout << ob.sumK(root, k) << "\n";
    }
    return 0;
}
// } Driver Code Ends