#include <bits/stdc++.h> 
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    
    // ------adjancency list--------
    unordered_map<int, list<pair<int, int>>> adj;
    for (int row = 0; row < edges; row++) {

        int src = vec[row][0];
        int dest = vec[row][1];
        int weight = vec[row][2];

        adj[src].push_back(make_pair(dest, weight));
        adj[dest].push_back(make_pair(src, weight));
    }

    // distance array
    vector<int> distance(vertices);
    for (int node = 0; node < vertices; node++) {
        distance[node] = INT_MAX;
    }

    // set data structure to get minimum distance node first each time,
    set<pair<int, int>> st;

    // source diatnce to itself is -> 0
    distance[source] = 0;

    // push in set (distance, node)
    st.insert(make_pair(0, source));

    while (!st.empty()) {

        // fetch top record having minimum distance
        auto top = *(st.begin());

        int node_distance = top.first;
        int top_node = top.second;

        // remove this record
        st.erase(st.begin());

        // process neighbours
        for (auto neighbour : adj[top_node]) {

            // if previous distance of this node in array is greater than,
            // this one then update minimum distance
            if (distance[neighbour.first] > node_distance + neighbour.second) {

                // cout << "indide condition";

                // check if this node with some distance is already in out set,
                // if yes then remove it, b/c now we have smaller distance
                // than previos one
                auto record = st.find(
                    make_pair(distance[neighbour.first], neighbour.first)
                ); // (distnace, node)

                if (record != st.end()) {
                    st.erase(record);
                }

                // update diatance in distance array
                distance[neighbour.first] = node_distance + neighbour.second;

                // push in set
                st.insert(
                    make_pair(distance[neighbour.first], neighbour.first)
                );
            }
        }
    }

    return distance;
}
