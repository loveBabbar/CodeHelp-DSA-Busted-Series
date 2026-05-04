#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
/*
    
    1 2 3 4 5 6 7
            
            1
           / \
          2   3
         / \ / \
        4  5 6  7
        
        target = 2
        
        ## 1.
        time = 0
        
        q = | {2}
        visited = | 2 -> true
        
        ## 2.
        time = 1
        
        q = | {4, 5, 1}
        visited = | 2 -> true, 4 -> true, 1 -> ture|
        
        ## 3.
        time = 2
        
        q = | {3}
        visited = | 2 -> true, 4 -> true, 1 -> ture, 3 -> true|
        
        ## 4.
        time = 3
        
        q = | {6, 7}
        visited = | 2 -> true, 4 -> true, 1 -> ture, 3 -> true, 6 -> true
                    7 -> true|
                    
        ## 5.
        time = 3 (not incremented)
        
        q = | {}
        visited = | 2 -> true, 4 -> true, 1 -> ture, 3 -> true, 6 -> true
                    7 -> true|
        
        ## 6.
        queue is empty now -> return time
        

*/
class Solution {
  private:
    Node* createParentMapping(Node* root, int target, map<Node*, Node*> &nodeToParent) {
        
        Node* startOfTargetNode = NULL;
        
        queue<Node*> qNodes;
        qNodes.push(root);
        
        nodeToParent[root] = NULL;
        
        // level order traversal
        while (!qNodes.empty()) {
            
            Node* front = qNodes.front();
            qNodes.pop();
            
            if (front->data == target) startOfTargetNode = front;
            
            if (front->left) {
                nodeToParent[front->left] = front;
                qNodes.push(front->left);
            }
            
            if (front->right) {
                nodeToParent[front->right] = front;
                qNodes.push(front->right);
            }
        }
        return startOfTargetNode;
    }
    
    int burnTree(Node* root, map<Node*, Node*> &nodeToParent) {
        
        // keep track of visited nodes
        map<Node*, bool> visited;
        
        queue<Node*> q;
        
        q.push(root);
        visited[root] = true;
        
        int time = 0;
        
        while (!q.empty()) {
                
            bool flag = false;
            int size = q.size();
            
            for (int i = 0; i < size; i++) {
                
                Node* front = q.front();
                q.pop();
                
                if (front->left && !visited[front->left]) {
                    flag = true;
                    q.push(front->left);
                    visited[front->left] = true;
                }
                
                if (front->right && !visited[front->right]) {
                    flag = true;
                    q.push(front->right);
                    visited[front->right] = true;
                }
                
                if (nodeToParent[front] && !visited[nodeToParent[front]]) {
                    flag = true;
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]] = true;
                }
            }
            
            // go level by level , in all three directions -> up, left and right
            if (flag) time++;
        }
        return time;
    }
  public:
    int minTime(Node* root, int target) {
        
        
        // create node to parent mapping
        map<Node*, Node*> nodeToParent;
        
        // find target node
        Node* targetNode = createParentMapping(root, target, nodeToParent);
        
        // burn the tree in minimum time
        int time = burnTree(targetNode, nodeToParent);
        
        return time;
    }
};