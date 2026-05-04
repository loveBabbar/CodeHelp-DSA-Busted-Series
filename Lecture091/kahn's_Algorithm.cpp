#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    
    // by kahn's algorithm

    // -------create adjacency list------------
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    // ----find indegree----
    vector<int> in_degree(v);
    for (auto i : adj) {
        for (auto j : i.second) {
            in_degree[j]++;
        }
    }

    // push node having 0 indegree
    queue<int> q;
    for (int i = 0; i < v; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    // ------do BFS-------
    vector<int> ans;
    while (!q.empty()) {
        
        // 1
        int front = q.front();

        // 2
        q.pop();

        // 3;
        ans.push_back(front);

        // 4: neighbours
        for (auto neighbour : adj[front]) {

            in_degree[neighbour]--;
            if (in_degree[neighbour] == 0) {
                q.push(neighbour);
            }
        }
    }
    return ans;
}