#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <algorithm>
using namespace std;

void dfs(int node, int parent, vector<int> &discovery_time, vector<int> &lowest_possible_time, unordered_map<int, bool> &visited, 
        unordered_map<int, list<int>> &adj, vector<int> &articulated_points, int &timer) {

    visited[node] = 1;
    discovery_time[node] = lowest_possible_time[node] = timer++;

    int child = 0; // edge case, for starting node

    // neighbours
    for (auto nbr : adj[node]) {

        if (nbr == parent) continue;

        // neighbour not visited -> call dfs
        if (!visited[nbr]) {

            int parent_nbr = node;
            dfs(nbr, parent_nbr, discovery_time, lowest_possible_time, visited, adj, articulated_points, timer);

            // when returned, update the low of node if smaller root founds by its neighbours
            lowest_possible_time[node] = min(lowest_possible_time[node], lowest_possible_time[nbr]);

            // ------**check for articulated points**---------
            if (lowest_possible_time[nbr] >= discovery_time[node] && parent != -1) {
                articulated_points[node] = 1;
            }
            child++;
        }
        else {
            // means node is visited already, update low from here,
            lowest_possible_time[node] = min(lowest_possible_time[node], discovery_time[nbr]);
        }
    }

    // starting node
    if (parent == -1 && child > 1) articulated_points[node] = 1;
}

int main() {

    int n = 5;
    int e = 5;

    // create edges vector, (src, dest)
    vector<pair<int, int>> edges;
    edges.push_back({0, 3});
    edges.push_back({3, 4});
    edges.push_back({0, 4});
    edges.push_back({0, 1});
    edges.push_back({1, 2});

    // create adjancency list
    unordered_map<int, list<int>> adj;
    for (int row = 0; row < edges.size(); row++) {

        int u = edges[row].first;
        int v = edges[row].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // start the algorithm
    int timer = 0;

    // required data structures
    vector<int> discovery_time(n);
    vector<int> lowest_possible_time(n);
    unordered_map<int, bool> visited;
    vector<int> articulated_points(n, 0);

    // initialisation
    for (int node = 0; node < n; node++) {
        discovery_time[node] = -1;
        lowest_possible_time[node] = -1;
    }

    // process all nodes using dfs
    for (int node = 0; node < n; node++) {

        if (!visited[node]) {

            int parent = -1;
            dfs(node, parent, discovery_time, lowest_possible_time, visited, adj, articulated_points, timer);
        }
    }

    // print articulated points
    for (int node = 0; node < n; node++) {
        cout << articulated_points[node] << " ";
    }
    cout << endl;

    return 0;
}