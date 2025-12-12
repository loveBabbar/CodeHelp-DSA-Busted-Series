#include <bits/stdc++.h>
using namespace std;

void BFS(int start, vector<vector<int>>& graph) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS Traversal: ";

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

int main() {
    int V = 5;
    vector<vector<int>> graph(V);

    graph[0] = {1, 2};
    graph[1] = {3, 4};

    BFS(0, graph);
    return 0;
}
