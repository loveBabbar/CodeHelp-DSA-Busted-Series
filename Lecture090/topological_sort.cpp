#include <bits/stdc++.h> 
using namespace std;

void topo_sort(int node, vector<bool> &visited, stack<int> &ans, unordered_map<int, list<int>> &adj) {

    visited[node] = 1;

    for (auto neighbour : adj[node]) {

        if (!visited[neighbour]) {
            topo_sort(neighbour, visited, ans, adj);
        }
    }

    // push node in stack while return back from call stack,,
    ans.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here

    // cout << "start";

    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    vector<bool> visited(v, false);
    stack<int> s;

    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            topo_sort(i, visited, s, adj);
        }
    }

    // cout << "push answer";

    vector<int> ans;
    while (!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }

    // cout << "end";

    return ans;
}