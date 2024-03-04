// ! T-IMP
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

class Solution {
  public:
    Node* findingDaddy(Node* root,Node* papa, map<Node*,Node*> &parent,int target){
        if( root == NULL)
            return NULL;
        
        parent[root] = papa;
        Node* left = findingDaddy(root->left,root,parent,target);
        Node* right = findingDaddy(root->right,root,parent,target);
        
        if(root-> data == target)
            return root;
        
        if(left != NULL)
            return left;
        
        if(right != NULL)
            return right;
        
        return NULL;
    }
  
    int minTime(Node* root, int target) 
    {
        if(root == NULL){
            return 0;
        }
        map<Node*,Node*> parent;
        Node* tNode = findingDaddy(root,NULL,parent,target);
        int time = 0;
        map<Node*,bool> visited ;
        visited[tNode] = true;
        // cout << parent.size() << " ";
        queue<Node*> q;
        q.push(tNode);
        // cout << q.size();
        while(!q.empty()){
            int flag = 0;
            int size = q.size();
            for( int i = 0; i < size; i++){
                Node*temp = q.front();
                q.pop();
                if(parent[temp] != NULL && visited[parent[temp]] == false){
                    q.push(parent[temp]);
                        flag = 1;
                }
                
                    if(temp->left != NULL && visited[temp->left] == false){
                        q.push(temp->left);
                            flag = 1;
                    }
                    if(temp->right != NULL && visited[temp->right] == false){
                        q.push(temp->right);
                            flag = 1;
                    }
                
                
                visited[parent[temp]] = true;
                visited[temp->left] = true;
                visited[temp->right] = true;
            }
                 if(flag) 
                    time++;
            
        }
        return time;
    }
};

//{ Driver Code Starts.

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