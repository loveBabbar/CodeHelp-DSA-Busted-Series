#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int v, int e, int src)
{
    // Creation of distance array with Infinite value Initially
    vector<int> distance(v, INT_MAX);

    // Creation of set on basis of (distance, node)
    set<pair<int, int>> st;

    unordered_map<int, list<pair<int, int>>> adjList;

    // Creating Adjacency List
    for (int i = 0; i < e; i++)
    {
        int u = vec[i][0], v = vec[i][1];
        int w = vec[i][2];

        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    // Initialize distance and Set with Source Node
    distance[src] = 0;
    st.insert({0, src});

    while (!st.empty())
    {
        // Fetch Top Record
        auto top = *(st.begin());

        int nodeDist = top.first;
        int topNode = top.second;

        // Erasing Top Record
        st.erase(st.begin());

        // Traversing on Neighbours
        for (auto neighbour : adjList[topNode])
        {
            if ((nodeDist + neighbour.second) < (distance[neighbour.first]))
            {
                auto record = st.find({distance[neighbour.first], neighbour.first});

                // If record found, then erase it
                if (record != st.end())
                {
                    st.erase(record);
                }

                // Update Distance
                distance[neighbour.first] = (nodeDist + neighbour.second);

                // Push Record in Set
                st.insert({distance[neighbour.first], neighbour.first});
            }
        }
    }

    return distance;
}

int main()
{
    int vertices = 5, edges = 7, source = 0;
    vector<vector<int>> v = {{0, 1, 7}, {0, 2, 1}, {0, 3, 2}, {1, 2, 3}, {1, 3, 5}, {1, 4, 1}, {3, 4, 7}};

    vector<int> ans = dijkstra(v, vertices, edges, source);

    cout << endl
         << "Shortest Paths from Source 0 : ";

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    cout << endl
         << endl;

    return 0;
}
