package Backtracking;

public class Maze {
    // V.V. Imp for Google Interviews
    public static void main(String [] args){
        System.out.println(maze(3, 3));
    }

    static int maze(int r, int c){
        // base Condition
        if(r == 1 || c == 1)
            return 1;

        int left = maze(r-1, c);
        int right = maze(r, c-1);
        return left+right;
    }
}
