package Recursion3;
import java.util.Collections;
import java.util.Scanner;
import java.util.ArrayList;

public class SubSequence2 {
    // Sub Sequence
    public static void main(String[] args) {
        // Take Any String From the USER
        Scanner sc = new Scanner(System.in);
        System.out.print(" Enter Any String: ");
        String str = sc.next();
        // Display Sub Sequence for a Given String
        ArrayList<String> list = new ArrayList<>();
        Collections.sort(subSeq(str, "", list));
        System.out.println(list);
    }

    static ArrayList<String> subSeq(String str, String ans, ArrayList<String> list) {
        if (str.isEmpty()) {
//            System.out.print(" " + ans);
            list.add(ans);
            return list;
        }

        char ch = str.charAt(0);
        // just take it or Ignore it
        subSeq(str.substring(1), ans + ch, list);
        subSeq(str.substring(1), ans, list);
        return list;
    }
}