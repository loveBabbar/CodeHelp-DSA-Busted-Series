package Recursion3;

import java.util.Scanner;

public class SkipStringApp {
    // Skip a Sub String app Not apple
    public static void main(String[] args) {
        // Take Any String From the USER
        Scanner sc = new Scanner(System.in);
        System.out.print(" Enter Any String: ");
        String str = sc.next();
        // Display the resultant String
        System.out.println(skip(str));
    }

    static String skip(String str) {
        if (str.isEmpty()) {
            return " ";
        }

        if (str.startsWith("app") && !str.startsWith("apple")) {
            return skip(str.substring(3));
        } else {
            return str.charAt(0) + skip(str.substring(1));
        }
    }
}
