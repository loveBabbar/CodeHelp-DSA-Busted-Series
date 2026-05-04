#include <bits/stdc++.h> 
using namespace std;

bool is_safe(int row, int col, vector<vector<int>> &board, int val) {

    for (int i = 0; i < board.size(); i++) {

        // row check
        if (board[row][i] == val) return false;

        // column check
        if (board[i][col] == val) return false;

        // 3*3 matrix check
        if (board[3*(row/3) + i/3][3*(col/3) + i%3] == val) return false;
    }
    return true;
}

bool solve(vector<vector<int>>& board) {

    int n = board.size();

    for (int row = 0; row < n; row++) {
        
        for (int col = 0; col < n; col++) {

            // if this block is empty,
            if (board[row][col] == 0) {

                // check for all possible number, for this block
                for (int val = 1; val <= 9; val++) {

                    // push a number
                    if (is_safe(row, col, board, val)) {
                        board[row][col] = val;
                    
                        // go deep and deep with this number until eihter you get a solution,
                        // or a not dead end
                        bool nextPossible = solve(board);

                        if (nextPossible) {
                            return true;
                        }
                        else {

                            // ------backtrack-------
                            board[row][col] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<int>>& sudoku)
{
	// Write your code here
    // No need to print the final sudoku
    // Just fill the values in the given matrix

    solve(sudoku);
}