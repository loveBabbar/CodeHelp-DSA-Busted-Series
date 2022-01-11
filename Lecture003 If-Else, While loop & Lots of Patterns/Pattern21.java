package com.company;

import java.util.Scanner;

public class Pattern21 {
    // Pattern 21
    public static void main(String[] args) {
        /*
        Pattern 21
                           1
                           2  3
                           4  5  6
                           7  8  9  10
                           11 12 13 14 15
         */
        // Creating Scanner Object For taking inputs from the USER
        Scanner sc = new Scanner(System.in);
        // Take Number of ROWS and COLUMNS from the USER
        System.out.print(" Enter Number of ROWS for the Pattern: ");
        int n = sc.nextInt();
        pattern(n);
    }

    static void pattern(int n) {
        // Procedure to print the Required Pattern
        int number = 1;
        for (int row = 1; row <= n; row++) {
            for (int column = 1; column <= row; column++) {
                System.out.print(number + " ");
                number++;
            }
            System.out.println();
        }
    }
}
