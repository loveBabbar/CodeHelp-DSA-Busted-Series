#include <bits/stdc++.h>
using namespace std;

void DFS(int node, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            DFS(neighbor, graph, visited);
        }
    }
}

int main() {
    int V = 5;
    vector<vector<int>> graph(V);

    graph[0] = {1, 2};
    graph[1] = {3, 4};

    vector<bool> visited(V, false);

    cout << "DFS Traversal: ";
    DFS(0, graph, visited);
    cout << endl;

    return 0;
}
