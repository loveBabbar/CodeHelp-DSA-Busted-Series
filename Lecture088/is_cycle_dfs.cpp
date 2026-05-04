#include <unordered_map>
#include <list>
#include <queue>
#include <iostream>
using namespace std;

bool detect_cycle_using_dfs(int node, int parent, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited) {

    visited[node] = true;

    for (auto neighbour : adj[node]) {

        if (!visited[neighbour]) {
            bool is_cycle = detect_cycle_using_dfs(neighbour, node, adj, visited);

            if (is_cycle) return true;
        }
        else if (neighbour != parent) {
            return true;
        }
    }
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    
    // create adjancancy list from edges
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++) {
        
        // source
        int u = edges[i][0];

        // destination
        int v = edges[i][1];

        // create connections
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // -----visited data structure------
    unordered_map<int, bool> visited;

    // go to all verteces
    for (int node = 0; node < n; node++) {

        // node is not visited, check for cycle
        if (!visited[node]) {

            bool is_cycle = detect_cycle_using_dfs(node, -1, adj, visited);
            // bool is_cycle = detect_cycle_using_bfs(node, adj, visited);

            if (is_cycle) {
                return "Yes";
            }
        }
    }
    return "No";
}
