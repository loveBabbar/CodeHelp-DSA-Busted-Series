#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    unordered_map<int, list<pair<int, int>>> adj;

public:
    void addEdge(int u, int v, int weight)
    {
        pair<int, int> p = make_pair(v, weight);

        adj[u].push_back(p);
    }

    void printAdj()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";

            for (auto j : i.second)
            {
                cout << "(" << j.first << ", " << j.second << "), ";
            }

            cout << endl;
        }
    }

    void dfs(int node, unordered_map<int, bool> &vis, stack<int> &s)
    {
        vis[node] = 1;

        for (auto neighbour : adj[node])
        {
            if (!vis[neighbour.first])
            {
                dfs(neighbour.first, vis, s);
            }
        }

        s.push(node);
    }

    void getShortestPath(int src, vector<int> &distance, stack<int> &s)
    {
        distance[src] = 0;

        while (!s.empty())
        {
            int top = s.top();
            s.pop();

            if (distance[top] != INT_MAX)
            {
                for (auto i : adj[top])
                {
                    if ((distance[top] + i.second) < distance[i.first])
                    {
                        distance[i.first] = (distance[top] + i.second);
                    }
                }
            }
        }
    }
};

int main()
{
    Graph g;

    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    // Printing Adjacency List
    cout << "Adjacency List -> " << endl;
    g.printAdj();

    int n = 6;

    // Topological Sort
    stack<int> s;
    unordered_map<int, bool> visited;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            g.dfs(i, visited, s);
        }
    }

    int source = 1;
    vector<int> distance(n, INT_MAX);

    g.getShortestPath(source, distance, s);

    cout << endl
         << "Paths : ";

    for (int i = 0; i < distance.size(); i++)
    {
        cout << distance[i] << " ";
    }

    cout << endl
         << endl;

    return 0;
}
