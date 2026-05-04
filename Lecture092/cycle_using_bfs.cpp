#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {

    // -------create adjacency list------------
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first - 1;
        int v = edges[i].second - 1;

        adj[u].push_back(v);
    }

    // ----find indegree----
    vector<int> in_degree(n, 0);
    for (auto i : adj) {
        for (auto j : i.second) {
            in_degree[j]++;
        }
    }

    // push node having 0 indegree
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    // ------do BFS-------
    int cnt = 0;
    while (!q.empty()) {
        
        // 1
        int front = q.front();

        // 2
        q.pop();

        // 3;
        cnt++;

        // 4: neighbours
        for (auto neighbour : adj[front]) {

            in_degree[neighbour]--;
            if (in_degree[neighbour] == 0) {
                q.push(neighbour);
            }
        }
    }

    if (cnt == n) return false;
    return true;

}