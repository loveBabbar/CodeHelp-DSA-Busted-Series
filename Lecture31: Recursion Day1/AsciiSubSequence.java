package Recursion3;

import java.util.ArrayList;
import java.util.Scanner;

public class AsciiSubSequence {
    // Sub Sequence
    public static void main(String[] args) {
        // Take Any String From the USER
        Scanner sc = new Scanner(System.in);
        System.out.print(" Enter Any String: ");
        String str = sc.next();
        // Display Sub Sequence for a Given String
        System.out.println(subSeq(str, ""));
    }

    static ArrayList<String> subSeq(String str, String ans) {
        if (str.isEmpty()) {
//            System.out.print(" " + ans);
            ArrayList<String> list = new ArrayList<>();
            list.add(ans);
            return list;
        }

        char ch = str.charAt(0);
        // just take it or Ignore it
        ArrayList<String> first = subSeq(str.substring(1), ans + ch);
        ArrayList<String> second = subSeq(str.substring(1), ans);
        ArrayList<String> third = subSeq(str.substring(1), ans + (ch + 0));

        first.addAll(second);
        first.addAll(third);
        return first;
    }
}
