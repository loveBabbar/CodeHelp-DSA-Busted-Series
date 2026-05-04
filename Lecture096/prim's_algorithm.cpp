#include <bits/stdc++.h> 
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // -----adjancency list------
    unordered_map<int, list<pair<int, int>>> adj;
    for (int row = 0; row < g.size(); row++) {

        int src = g[row].first.first;
        int dest = g[row].first.second;
        int weight = g[row].second;

        adj[src].push_back({dest, weight});
        adj[dest].push_back({src, weight});
    }
    // --------------------------

    // --------------------------------
    // create all required Data Structures
    vector<int> key(n+1);
    vector<bool> mst(n+1);
    vector<int> parent(n+1);

    // initialse all of them
    for (int node = 0; node <= n; node++) {

        // weight
        key[node] = INT_MAX; 

        // parent
        parent[node] = -1;

        // status, visited or not
        mst[node] = false;
    }
    // ---------------------------------------

    // -------Starting of Algothim----------
    int start = 1;
    key[start] = 0;
    parent[start] = -1;

    // now explore all nodes, one by one
    for (int node = 1; node <= n; node++) {

        int min_weight = INT_MAX;
        int node_with_min_w;

        // ---find minimum distance node from our Data structure 'key'--- // not required if you use a min heap
        for (int cur_node = 1; cur_node <= n; cur_node++) {

            // if node 'cur_node' status is false and have smaller distance than min_weight, then process
            if (
                mst[cur_node] == false &&
                key[cur_node] < min_weight
            )  {

                node_with_min_w = cur_node;
                min_weight = key[cur_node];
            }
        }
        // ------------------------------------------------------------

        // mark 'node_with_min_w' as true
        mst[node_with_min_w] = true;

        // check for adjacent nodes
        for (auto neighbour : adj[node_with_min_w]) {

            // node value
            int v = neighbour.first;

            // node weight in adj list
            int weight_v_in_graph = neighbour.second;

            // previous weight, in key vector
            int weight_v_in_key = key[v];

            // update parent and weight if they are smaller than what is stored in 'key' vector
            if (mst[v] == false && weight_v_in_graph < weight_v_in_key) {
                parent[v] = node_with_min_w;
                key[v] = weight_v_in_graph;
            }
        }
    }

    // create MST(minimum spannnign tree)
    vector<pair<pair<int, int>, int>> result;
    for (int node = 2; node <= n; node++) {
        // ((src, dest), weight)
        result.push_back({{parent[node], node}, key[node]});
    }
    return result;
}
