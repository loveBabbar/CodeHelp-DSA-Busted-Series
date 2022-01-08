package Backtracking;

public class SudokuSolver {
    public static void main(String [] args){
        // Create Sudoku
        int [][] board = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                          {5, 2, 0, 0, 0, 0, 0, 0, 0},
                          {0, 8, 7, 0, 0, 0, 0, 3, 1},
                          {0, 0, 3, 0, 1, 0, 0, 8, 0},
                          {9, 0, 0, 8, 6, 3, 0, 0, 5},
                          {0, 5, 0, 0, 9, 0, 6, 0, 0},
                          {1, 3, 0, 0, 0, 0, 2, 5, 0},
                          {0, 0, 0, 0, 0, 0, 0, 7, 4},
                          {0, 0, 5, 2, 0, 6, 3, 0, 0}};
        if(solve(board))
            displayBoard(board);
        else
            System.out.println("Cannot Solve!!");
    }

    static boolean solve(int [][]board) {
        int n = board.length;
        int row = -1;
        int col = -1;

        boolean emptyLeft = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 0) {
                    row = i;
                    col = j;
                    emptyLeft = false;
                    break;
                }
            }
            // if You found Some Empty Element in row then break
            if (!emptyLeft)
                break;
        }
        if (emptyLeft) {
            return true;
            // Sudoku is Solved
        }
        // backtrack
        for(int number=1; number<=9; number++) {
            if (isSafe(board, row, col, number)) {
                board[row][col] = number;
                if (solve(board)) {
                    // Found the Answer
                    return true;
                }
                // otherwise Backtrack
                else
                    board[row][col] = 0;
            }
        }
        return false;
    }

    static void displayBoard(int [][] board){
        for(int []row:board){
            for(int num:row)
                System.out.print(num + " ");
            System.out.println();
        }
    }

    static boolean isSafe(int [][] board, int row, int col, int num){
        // check the row
        for(int i=0; i < board.length; i++){
            // check if the Number is in the Row or Not
            if(board[row][col] == num)
                return false;
        }
        // Check for Columns
        for(int [] nums : board){
            // check if the Number is in the Col
            if(nums[col] == num)
                return false;
        }

        // take SquareRoot of length of board
        int sqr = (int)(Math.sqrt(board.length));
        int rowStart = row - (row%sqr);
        int colStart = col - (col%sqr);
        for(int r = rowStart; r < rowStart + sqr; r++){
            for(int c = colStart; c < colStart + sqr; c++){
                if(board[r][c] == num){
                    return false;
                }
            }
        }
        return true;
    }
}
