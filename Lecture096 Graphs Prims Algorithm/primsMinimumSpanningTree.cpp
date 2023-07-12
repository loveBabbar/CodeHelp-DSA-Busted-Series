#include <bits/stdc++.h>
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Adjacency List
    unordered_map<int, list<pair<int, int>>> adjList;

    vector<int> key(n + 1, INT_MAX), parent(n + 1, -1);
    vector<bool> mst(n + 1, false);

    vector<pair<pair<int, int>, int>> ans;

    // Creating Adjacency List
    for (int i = 0; i < m; i++)
    {
        int u = g[i].first.first, v = g[i].first.second;
        int w = g[i].second;

        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    // Let's Start the Algo
    // Prims Algorithm
    key[1] = 0, parent[1] = -1;

    for (int i = 1; i < n; i++)
    {
        int mini = INT_MAX;
        int u;

        // Finding the Node with Minimum Value
        for (int v = 1; v <= n; v++)
        {
            if (mst[v] == false && key[v] < mini)
            {
                u = v;
                mini = key[v];
            }
        }

        // Mark Minimum Node as True
        mst[u] = true;

        // Check its adjacent Nodes
        for (auto it : adjList[u])
        {
            int v = it.first;
            int w = it.second;

            if (mst[v] == false && w < key[v])
            {
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        ans.push_back({{parent[i], i}, key[i]});
    }

    return ans;
}

int main()
{
    int n = 5, m = 14;
    vector<pair<pair<int, int>, int>> g = {{{1, 2}, 2}, {{1, 4}, 6}, {{2, 1}, 2}, {{2, 3}, 3}, {{2, 4}, 8}, {{2, 5}, 5}, {{3, 2}, 3}, {{3, 5}, 7}, {{4, 1}, 6}, {{4, 2}, 8}, {{4, 5}, 9}, {{5, 2}, 5}, {{5, 3}, 7}, {{5, 4}, 9}};

    vector<pair<pair<int, int>, int>> ans = calculatePrimsMST(n, m, g);

    cout << endl
         << "Answer -> \n"
         << endl;

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].first.first << " " << ans[i].first.second << " " << ans[i].second << endl;
    }

    cout << endl;

    return 0;
}
