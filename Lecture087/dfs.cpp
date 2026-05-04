#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
#include <list>

void dfs(int node, unordered_map<int, list<int>> &adj,  vector<int> &component, unordered_map<int, bool> &visited) {

    component.push_back(node);
    visited[node] = true;

    for (auto it : adj[node]) {
        if (!visited[it]) {
            dfs(it, adj, component, visited);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here

    // create your adjacency list
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // run for all nodes
    unordered_map<int, bool> visited;
    vector<vector<int>> ans;
    for (int i = 0; i < V; i++) {

        // call dfs if node is not visited yet
        if (!visited[i]) {
            vector<int> component;
            dfs(i, adj, component, visited);
            ans.push_back(component);
        }
    }
    return ans;
}