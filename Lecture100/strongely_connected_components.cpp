#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <list>
using namespace std;

void dfs(int node, unordered_map<int, bool> &vis, 
		unordered_map<int, list<int>> &adj, stack<int> &st) {

	vis[node] = true;

	for (auto nbr : adj[node]) {

		if (!vis[nbr]) {
			dfs(nbr, vis, adj, st);
		}
	}

	// push while returing, from end (oviousely)
	st.push(node);
}

void rev_dfs(int node, unordered_map<int, bool> &vis, 
			unordered_map<int, list<int>> &adj) {

	vis[node] = true;

	for (auto nbr : adj[node]) {

		if (!vis[nbr]) {
			rev_dfs(nbr, vis, adj);
		}
	}
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	
	// adjancecny list
	unordered_map<int, list<int>> adj;
	for (int row = 0; row < edges.size(); row++) {

		int u = edges[row][0];
		int w = edges[row][1];

		adj[u].push_back(w);
	}

	// 1: topological sort
	stack<int> st;
	unordered_map<int, bool> vis;
	for (int node = 0; node < v; node++) {

		if (!vis[node]) {
			dfs(node, vis, adj, st);
		}
	}

	// 2: transpose graph
	unordered_map<int, list<int>> transpose;
	for (int node = 0; node < v; node++) {

		vis[node] = 0;
		for (auto nbr : adj[node]) {
			transpose[nbr].push_back(node);
		}
	}

	// 3: dfs call using above ordering
	int count = 0;
	while (!st.empty()) {

		int top = st.top();
		st.pop();

		if (!vis[top]) {
			count++;

			rev_dfs(top, vis, transpose);
		}
	}
	return count;
}