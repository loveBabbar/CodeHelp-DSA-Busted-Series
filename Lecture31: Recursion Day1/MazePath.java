package Backtracking;
import java.util.ArrayList;

public class MazePath {
    // print all the possible Maze Paths
    public static void main(String [] args){
        System.out.println("D -> Down     R -> Right");
//        path("", 3, 3);
        System.out.println(path2("", 3, 3));
    }

    static void path(String p, int r, int c){
        if(r == 1 && c == 1){
            System.out.println(p);
            return;
        }

        if(r > 1){
            path(p + 'D', r-1, c);
        }
        if(c > 1){
            path(p + 'R', r , c-1);
        }
    }

    static ArrayList<String> path2(String p, int r, int c){
        if(r == 1 && c == 1){
            ArrayList<String> list = new ArrayList<>();
            list.add(p);
            return list;
        }

        ArrayList<String> list = new ArrayList<>();
        if(r > 1){
            list.addAll(path2(p + 'D', r-1, c));
        }
        if(c > 1){
            list.addAll(path2(p + 'R', r , c-1));
        }
        return list;
    }
}
