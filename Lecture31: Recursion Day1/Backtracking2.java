package Backtracking;

import java.util.Arrays;

public class Backtracking2 {
    public static void main(String [] args){
        boolean [][] board = {{true, true, true},
                {true, true, true},
                {true, true, true}};
        allPaths("", board, 0, 0, new int[board.length][board[0].length], 1);
    }

    static void allPaths(String p, boolean [][] maze, int r, int c, int [][]path, int step) {
        if (r == maze.length - 1 && c == maze[0].length - 1) {
            // Because Last Step is also a Step
            path[r][c] = step;
            for(int [] arr: path) {
                System.out.println(Arrays.toString(arr));
            }
            System.out.println(p);
            System.out.println();
            return;
        }
        if (!maze[r][c])
            return;

        maze[r][c] = false;
        path[r][c] = step;
        // Going Down
        if (r < maze.length - 1)
            allPaths(p + 'D', maze, r + 1, c, path, step+1);
        // Going Right
        if (c < maze[0].length - 1)
            allPaths(p + 'R', maze, r, c + 1, path, step+1);
        // Going Up
        if (r > 0)
            allPaths(p + 'U', maze, r - 1, c, path, step+1);
        // Going Left
        if (c > 0)
            allPaths(p + 'L', maze, r, c - 1, path, step+1);

        maze[r][c] = true;
        path[r][c] = 0;
    }
}
