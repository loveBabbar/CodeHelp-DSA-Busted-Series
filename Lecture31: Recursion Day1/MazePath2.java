package Backtracking;

import java.util.ArrayList;

public class MazePath2 {
    // print all the possible Maze Paths Include Diagonals also
    public static void main(String[] args) {
        System.out.println("H -> Horizontally     V -> Vertically     D -> Diagonally");
//        mazeDiagonal("", 3, 3);
        System.out.println(mazeDiagonal2("", 3, 3));
    }

    static void mazeDiagonal(String p, int r, int c) {
        if (r == 1 && c == 1) {
            System.out.println(p);
            return;
        }

        if(r > 1 && c > 1){
           mazeDiagonal(p + 'D', r-1, c-1);
        }
        if (r > 1) {
            mazeDiagonal(p + 'D', r - 1, c);
        }
        if (c > 1) {
            mazeDiagonal(p + 'R', r, c - 1);
        }
    }

    static ArrayList<String> mazeDiagonal2(String p, int r, int c) {
        if (r == 1 && c == 1) {
            ArrayList<String> list = new ArrayList<>();
            list.add(p);
            return list;
        }

        ArrayList<String> list = new ArrayList<>();

        if(r > 1 && c > 1){
            list.addAll(mazeDiagonal2(p + 'D', r-1, c-1));
        }
        if (r > 1) {
            list.addAll(mazeDiagonal2(p + 'V', r - 1, c));
        }
        if (c > 1) {
            list.addAll(mazeDiagonal2(p + 'H', r, c - 1));
        }
        return list;
    }
}

