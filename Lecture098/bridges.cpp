#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;

void dfs(int node, int parent, int &timer, vector<int> &discovery_time, 
        vector<int> &lowest_time, vector<vector<int>> &result,
        unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited) {

    visited[node] = true;
    discovery_time[node] = lowest_time[node] = timer++;

    // neighbours
    for (auto neighbour : adj[node]) {

        // skip this,
        if (neighbour == parent) continue;

        // node if not visited yet
        if (!visited[neighbour]) {
            dfs(neighbour, node, timer, discovery_time, lowest_time, result, adj, visited);

            // when returned, check if neighbour gets shorter path
            lowest_time[node] = min(lowest_time[node], lowest_time[neighbour]);

            // bridge edge, if no other path founded means: 
            if (lowest_time[neighbour] > discovery_time[node]) {
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(neighbour);
                result.push_back(ans);
            }
        }
        else {

            // neighbour is not parent, and visited
            lowest_time[node] = min(lowest_time[node], discovery_time[neighbour]);
        }
    }
}


vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    
    // create adjency list
    unordered_map<int, list<int>> adj;
    for (int row = 0; row < e; row++) {

        int u = edges[row][0];
        int v = edges[row][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // -----reqiured data structures------
    vector<int> discovery_time(v);
    vector<int> lowest_time(v);
    unordered_map<int, bool> visited;
    int parent = -1;

    // initialise them
    for (int node = 0; node < v; node++) {
        discovery_time[node] = -1;
        lowest_time[node] = -1;
    }

    int timer = 0;
    vector<vector<int>> result;

    // ------DFS-------
    for (int node = 0; node < v; node++) {
        if (!visited[node]) {
            dfs(node, parent, timer, discovery_time, lowest_time, result, adj, visited);
        }
    }
    return result;
}