package Backtracking;

public class MazeWithRestrictions {
    // Maze With Obstacles
    public static void main(String [] args){
        boolean [][] board = {
                {true, true, true},
                {true, false, true},
                {true, true, true}};
        pathRestrictions("", board, 0, 0);
    }

    static void pathRestrictions(String p, boolean [][] maze, int r, int c){
        if(r == maze.length-1 && c == maze[0].length-1){
            System.out.println(p);
            return;
        }
        if(!maze[r][c])
            return;
        if(r < maze.length-1)
            pathRestrictions(p+'D', maze, r+1, c);
        if(c < maze[0].length-1)
            pathRestrictions(p+'R', maze, r, c+1);
    }
}
