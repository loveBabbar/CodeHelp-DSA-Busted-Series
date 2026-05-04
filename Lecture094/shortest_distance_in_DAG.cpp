#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <stack>
#include <limits>
using namespace std;

class Graph {
private:

    // src ---> (dest, weight)
    unordered_map<int, list<pair<int, int>>> adj;

public:
    void add_edge(int src, int dest, int weight) {
        pair<int, int> dest_and_weight = make_pair(dest, weight);
        adj[src].push_back(dest_and_weight);
    }

    void print() {
        for (auto src : adj) {

            cout << src.first << "-->";
            for (auto dest_and_W : src.second) {
                cout << "(" << dest_and_W.first << ", " << dest_and_W.second << "), ";
            }
            cout << endl;
        }
    }

    // return topological order in a stack
    void dfs(int cur_node, unordered_map<int, bool> &visited, stack<int> &s) {

        visited[cur_node] = true;

        // check for neighbours
        for (auto neigbour : adj[cur_node]) {
            if (!visited[neigbour.first]) {
                dfs(neigbour.first, visited, s);
            }
        }

        // push node with no recursive call left
        s.push(cur_node);
    }

    void shortest_path(int src, vector<int> &dist, stack<int> &s) {
        dist[src] = 0;

        while (!s.empty()) {
            int top = s.top();
            s.pop();

            // if node if not visited yet
            if (dist[top] != INT16_MAX) {

                // visit its neighbours
                for (auto neighbour : adj[top]) {

                    // if prev dist is not greater than new one, replace
                    if (dist[top] + neighbour.second < dist[neighbour.first]) {
                        dist[neighbour.first] = dist[top] + neighbour.second;
                    }
                }
            }
        }
    }
};

int main() {
    
    Graph g;
    g.add_edge(0, 1, 5);
    g.add_edge(0, 2, 3);
    g.add_edge(1, 2, 2);
    g.add_edge(1, 3, 6);
    g.add_edge(2, 3, 7);
    g.add_edge(2, 4, 4);
    g.add_edge(2, 5, 2);
    g.add_edge(3, 4, -1);
    g.add_edge(4, 5, -2);

    g.print();

    // step1: find topological order
    int total_node = 6;
    unordered_map<int, bool> visited;
    stack<int> s;
    for (int node = 0; node < total_node; node++) {
        if (!visited[node]) {
            g.dfs(node, visited, s);
        }
    }

    // int i = 0;
    // while (!s.empty()) {
    //     cout << s.top() << " ";
    //     s.pop();
    // }
    // cout << endl;

    // -----------distance array----------
    int src = 1;
    vector<int> dist(total_node);

    for (int i = 0; i < total_node; i++) {
        dist[i] = INT16_MAX;
    }

    g.shortest_path(src, dist, s);

    for (int i = 0; i < dist.size(); i++) {
        cout << dist[i] << endl;
    }

    return 0;
}