#include <iostream>
#include <unordered_map>
#include <queue>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){

	// adjancency list
	unordered_map<int, list<int>> adj;
	for (int i = 0; i < m; i++) {

		int u = edges[i].first;
		int v = edges[i].second;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	// required Data Structures
	unordered_map<int, bool> visited;
	unordered_map<int, int> parent;
	queue<int> q;

	// start with s
	q.push(s);
	parent[s] = -1;
	visited[s] = true;

	// --- do bfs----
	while (!q.empty()) {
		int front = q.front();
		q.pop();

		for (auto neighbour : adj[front]) {
			if (!visited[neighbour]) {
				q.push(neighbour);
				parent[neighbour] = front;
				visited[neighbour] = true;
			}
		}
	}

	// ----prepare shortest path-----
	vector<int> ans;

	// start creating path from last
	int current_node = t;
	ans.push_back(current_node);

	while (current_node != s) {
		current_node = parent[current_node];
		ans.push_back(current_node);
	}

	std::reverse(ans.begin(), ans.end());
	return ans;
}
