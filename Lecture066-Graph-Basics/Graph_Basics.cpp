#include <bits/stdc++.h>
using namespace std;

int main() {
    // Number of vertices
    int V = 5;

    // Graph represented as adjacency list
    vector<vector<int>> adj(V);

    // Creating a simple graph
    adj[0] = {1, 2};
    adj[1] = {3, 4};

    cout << "Graph Representation (Adjacency List):\n";
    for (int i = 0; i < V; i++) {
        cout << i << " -> ";
        for (auto node : adj[i]) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
