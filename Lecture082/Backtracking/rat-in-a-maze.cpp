#include <bits/stdc++.h> 
using namespace std;

bool isSafe(int x, int y, vector<vector<bool>> &vis, vector<vector<int>> &arr, int n) {

    if (((x >= 0 && x < n) && (y >=0 && y < n)) && (arr[x][y] == 1) && (vis[x][y] == 0)) {
        return true;
    }
    return false;
}

void solve(int x, int y, vector<vector<int>> &arr, int n, vector<string> &ans, vector<vector<bool>> &vis, string path) {

    if (x == n-1 && y == n-1) {
        ans.push_back(path);
        return;
    }

    vis[x][y] = 1;

    // cout << x << " " << y << endl;

    // D
    if (isSafe(x+1, y, vis, arr, n)) {
        // cout << "inside" << endl;
        solve(x+1, y, arr, n, ans, vis, path+'D');
    }

    // L
    if (isSafe(x, y-1, vis, arr, n)) {
        solve(x, y-1, arr, n, ans, vis, path+'L');
    }

    // R
    if (isSafe(x, y+1, vis, arr, n)) {
        solve(x, y+1, arr, n, ans, vis, path+'R');
    }

    // U
    if (isSafe(x-1, y, vis, arr, n)) {
        solve(x-1, y, arr, n, ans, vis, path+'U');
    }

    // after returning if path found, or not found
    vis[x][y] = 0;

    // cout << x << " " << y << endl;
}

vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    
    vector<string> ans;
    vector<vector<bool>> vis(n, vector<bool>(n, 0));
    string path = "";

    if (arr[0][0] == 0) return ans;

    solve(0, 0, arr, n, ans, vis, path);
    return ans;
}