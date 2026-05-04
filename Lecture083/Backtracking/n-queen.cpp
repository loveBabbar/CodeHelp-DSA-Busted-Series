#include <bits/stdc++.h> 
using namespace std;
void add_solution(vector<vector<int>> &ans, vector<vector<int>> &board, int n) {

	vector<int> temp;

	// store flatten form of answer that is stored in borad to a vector say 'temp'
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {
			temp.push_back(board[i][j]);
		}
	}

	// append the temp in ans
	ans.push_back(temp);
}

bool is_safe(int row, int col, vector<vector<int>> &board, int n) {

	int x = row;
	int y = col;

	// check for same row
	while (y >= 0) {
		if (board[x][y] == 1) {
			return false;
		}
		y--;
	}

	x = row;
	y = col;

	// check for diagonal
	while (x >= 0 && y >= 0) {
		if (board[x][y] == 1) {
			return false;
		}
		y--;
		x--;
	}

	x = row;
	y = col;

	// check for diagonal
	while (x < n && y >= 0) {
		if (board[x][y] == 1) {
			return false;
		}
		y--;
		x++;
	}

	// return true if no single queen is attacking our queen
	return true;
}

void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n) {

	if (col == n) {
		// this is one possible solution
		add_solution(ans, board, n);
		return;
	}

	for (int row = 0; row < n; row++) {
		if (is_safe(row, col, board, n)) {
			board[row][col] = 1;

			// now place next queen in next column for this particular root
			solve(col+1, ans, board, n);

			// backtrack
			board[row][col] = 0;
		}
	}
}

vector<vector<int>> nQueens(int n)
{
	vector<vector<int>> board(n, vector<int>(n, 0));
	vector<vector<int>> ans;

	int start_col = 0;
	solve(start_col, ans, board, n);
	return ans;
	
}