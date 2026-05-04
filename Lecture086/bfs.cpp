// https://www.naukri.com/code360/problems/bfs-in-graph_973002?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar&leftPanelTabValue=SUBMISSION

#include <bits/stdc++.h>    
#include <queue>
using namespace std;

vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    
    vector<int> visited(n, 0);
    queue<int> q;
    q.push(0);
    visited[0] = 1;

    vector <int> ans;
    while (!q.empty()) {

        int frontNode = q.front();
        q.pop();

        ans.push_back(frontNode);
        // cout << "front node: " << frontNode << endl;

        // append its nieghbours those are not visited yet
        for (int j = 0; j < adj[frontNode].size(); j++) {
            int node = adj[frontNode][j];
            
            if (!visited[node]) {
                visited[node] = 1;
                q.push(node);
            }
        }
    }
    return ans;
}