package com.company;

import java.util.Scanner;

public class Pattern22 {
    // Pattern 22
    public static void main(String[] args) {
        /*
        Pattern 22
                       1
                       0 1
                       1 0 1
                       0 1 0 1
                       1 0 1 0 1
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
        for (int row = 1; row <= n; row++) {
            for (int column = 1; column <= row; column++) {
                if((row + column) % 2 == 0)
                    System.out.print(0 + " ");
                else
                    System.out.print(1 + " ");
            }
            System.out.println();
        }
    }
}
