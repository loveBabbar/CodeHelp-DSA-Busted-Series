#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

bool detect_cycle_using_bfs(int node, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited) {

    // parent data structure
    unordered_map<int, int> parent;

    // ----step1: mark node true-----
    visited[node] = true;

    // ----step2: mark its parent----
    parent[node] = -1;

    // ----step3: push in queue-----
    queue<int> q;
    q.push(node);

    // keep doing same thing until cycle detected or queue becomes empty
    while (!q.empty()) {

        // pop node from queue (FIFO)
        int node_to_process = q.front();
        q.pop();

        // repeat step 1 to 3 for node's neighbours
        for (auto neighbour : adj[node_to_process]) {

            // cycle detected: if already visited and not a parent of 'current node'
            if (visited[neighbour] && parent[node_to_process] != neighbour) {
                return true;
            }
            else {

                // if neighbour is not visited, now repeat 1 to 3
                if (!visited[neighbour]) {

                    // 1.
                    visited[neighbour] = true;

                    // 2
                    parent[neighbour] = node_to_process;

                    // 3
                    q.push(neighbour);
                }
            }
        }
    }
    return false;
}

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

            bool is_cycle = detect_cycle_using_bfs(node, adj, visited);

            if (is_cycle) {
                return "Yes";
            }
        }
    }
    return "No";
}
