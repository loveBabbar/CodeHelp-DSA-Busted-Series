#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b) {
  return a[2] < b[2];
}

void make_set(vector<int> &parent, vector<int> &rank, int n) {

  for (int node = 0; node < n; node++) {
    parent[node] = node;
    rank[node] = 0;
  }
}

int find_parent(vector<int> &parent, int node) {

  if (parent[node] == node) {
    return node;
  }

  // reccursively search for parent with 'path compression'
  return parent[node] = find_parent(parent, parent[node]);
}

void union_set(int u, int v, vector<int> &parent, vector<int> &rank) {

  u = find_parent(parent, u);
  v = find_parent(parent, v);

  if (rank[u] < rank[v]) {
    parent[u] = v;
  }
  else if (rank[u] > rank[v]) {
    parent[v] = u;
  }
  else {
    parent[v] = u;
    rank[u]++;
  }
}

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
  // sort the edges according to weights
  sort(edges.begin(), edges.end(), cmp);

  // required data structures
  vector<int> parent(n);
  vector<int> rank(n);

  // initialise all them with required values
  make_set(parent, rank, n);

  // ------starting of alogithm--------
  int min_weight = 0;
  for (int row = 0; row < edges.size(); row++) {

    int u = find_parent(parent, edges[row][0]);
    int v = find_parent(parent, edges[row][1]);
    int weight = edges[row][2];

    // both nodes are not in same group
    if (u != v) {

      min_weight += weight;

      // make them in same group
      union_set(u, v, parent, rank);
    }
  }
  return min_weight;
}