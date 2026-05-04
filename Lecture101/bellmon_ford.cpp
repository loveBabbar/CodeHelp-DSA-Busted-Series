#include <bits/stdc++.h>
using namespace std;

vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {
    
    // Bellmon Ford Algorithm

    // initialise distance array
    vector<int> distance(n+1, 1e8);
    distance[src] = 0;

    // do (n-1) times weight updates for every edge
    for (int i = 1; i <= n-1; i++) {

        for (int j = 0; j < m; j++) {

            int u = edges[j][0];
            int v = edges[j][1];

            int wt = edges[j][2];

            // update weight if any weight less than current weight founds
            if (distance[u] != 1e9 && (distance[u] + wt) < distance[v]) {
                distance[v] = distance[u] + wt;
            }
        }
    }

    bool flag = false;
    for (int j = 0; j < m; j++) {

        int u = edges[j][0];
        int v = edges[j][1];

        int wt = edges[j][2];

        // weight update for nth time, if any weight less than current weight founds, then negative cycle exists
        if (distance[u] != 1e9 && (distance[u] + wt) < distance[v]) {
            flag = true;
        }
    }

    if (flag) {
        return {-1};
    }

    return distance;
}