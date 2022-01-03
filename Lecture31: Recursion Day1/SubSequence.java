package Recursion3;
import java.util.Scanner;

public class SubSequence {
    // Sub Sequence
    public static void main(String[] args) {
        // Take Any String From the USER
        Scanner sc = new Scanner(System.in);
        System.out.print(" Enter Any String: ");
        String str = sc.next();
        // Display Sub Sequence for a Given String
        subSeq(str, " ");
    }

    static void subSeq(String str, String ans) {
        if (str.isEmpty()) {
            System.out.print(" " + ans);
            return;
        }

        char ch = str.charAt(0);
        // just take it or Ignore it
        subSeq(str.substring(1), ans + ch);
        subSeq(str.substring(1), ans);
    }
}