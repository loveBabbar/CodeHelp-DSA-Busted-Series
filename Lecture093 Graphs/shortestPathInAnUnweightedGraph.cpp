#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t)
{
    queue<int> q;
    vector<int> ans;
    unordered_map<int, list<int>> adjList;
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;

    // Creating Adjacency List
    for (int i = 0; i < m; i++)
    {
        int u = edges[i].first, v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    q.push(s);
    parent[s] = -1;
    visited[s] = true;

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        for (auto i : adjList[frontNode])
        {
            if (!visited[i])
            {
                visited[i] = true;
                parent[i] = frontNode;

                q.push(i);
            }
        }
    }

    // Prepare Shortest Path
    int currentNode = t;
    ans.push_back(t);

    while (currentNode != s)
    {
        currentNode = parent[currentNode];
        ans.push_back(currentNode);
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    int nodes = 8, totalEdges = 9;
    int source = 1, destination = 8;
    vector<pair<int, int>> edges = {{1, 2}, {1, 3}, {1, 4}, {2, 5}, {5, 8}, {3, 8}, {4, 6}, {6, 7}, {7, 8}};

    vector<int> ans = shortestPath(edges, nodes, totalEdges, source, destination);

    cout << endl
         << "Shortest Path : ";

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    cout << endl
         << endl;

    return 0;
}
