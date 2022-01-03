package Recursion3;

import java.util.Scanner;

public class SkipSubStringApple {
    // Skip a SubString Apple From a Given String
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

        if (str.startsWith("apple")) {
            return skip(str.substring(5));
        } else {
            return str.charAt(0) + skip(str.substring(1));
        }
    }
}

