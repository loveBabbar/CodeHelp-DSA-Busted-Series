#include <bits/stdc++.h>
using namespace std;

bool checkCycleDfs(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited, unordered_map<int, list<int>> &adj)
{
    visited[node] = true, dfsVisited[node] = true;

    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            bool detected = checkCycleDfs(neighbour, visited, dfsVisited, adj);

            if (detected)
            {
                return true;
            }
        }
        else if (dfsVisited[neighbour])
        {
            return true;
        }
    }

    dfsVisited[node] = false;

    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    int ans = 0;
    queue<int> q;
    vector<int> indegree(n);
    unordered_map<int, list<int>> adj;

    // Create Adjacency List
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first - 1;
        int x = edges[i].second - 1;

        adj[u].push_back(x);
    }

    // Find all Indegree
    for (auto i : adj)
    {
        for (auto j : i.second)
        {
            indegree[j]++;
        }
    }

    // Push into queue whose indegree is 0
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // Do Bfs
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        // Store Answer
        ans++;

        // Update Indegree's Neighbour
        for (auto i : adj[front])
        {
            indegree[i]--;

            // Push into queue whose indegree is 0
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
    }

    // Returning Answer
    return (ans != n);
}

int main()
{
    int n = 5;
    vector<pair<int, int>> edges = {{1, 2}, {4, 1}, {2, 4}, {3, 4}, {5, 2}, {1, 3}};

    int ans = detectCycleInDirectedGraph(n, edges);

    cout << endl
         << "Answer : " << ans << endl;

    return 0;
}
