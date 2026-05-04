#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>

using namespace std;

bool isCyclic(int node, unordered_map<int, list<int>> adj, unordered_map<int, bool> visited, unordered_map<int, bool> dfsVisited) {

  visited[node] = true;
  dfsVisited[node] = true;

  for (auto it : adj[node]) {
    if (!visited[it]) {
      bool isCycle = isCyclic(it, adj, visited, dfsVisited);
      if (isCycle) {
        return true;
      }
    }
    else if (dfsVisited[it]) {
      return true;
    }
  }
  
  dfsVisited[node] = false;
  return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.

    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }

    // to handle disconnected components
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            bool isCycle = isCyclic(i, adj, visited, dfsVisited);
            if (isCycle) return true;
        }
    }
    return false;
}