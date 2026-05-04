#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class Graph {

public:
    unordered_map<int, list<int>> adjList;

    void addEdge(int u, int v, bool direction) {

        // create an edge from u to v
        adjList[u].push_back(v);

        // if undirected, create an edge from v to u
        if (!direction) {
            adjList[v].push_back(u);
        }
    }

    void printAdjList() {
        for (auto it : adjList) {
            cout << it.first << "-->";
            for (auto entry : it.second) {
                cout << entry << ",";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g;

    // g.addEdge(0, 1, 0);
    // g.addEdge(0, 4, 0);
    // g.addEdge(1, 3, 0);
    // g.addEdge(1, 2, 0);
    // g.addEdge(2, 3, 0);
    // g.addEdge(3, 4, 0);
    // g.printAdjList();

    int n;
    cout << "enter number of nodes: " << endl;
    cin >> n;

    int m;
    cout << "enter number of edges: " << endl;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cout << "enter edge (u v): " << endl;
        cin >> u >> v;
        g.addEdge(u, v, 0);
    }
    g.printAdjList();

    return 0;

}