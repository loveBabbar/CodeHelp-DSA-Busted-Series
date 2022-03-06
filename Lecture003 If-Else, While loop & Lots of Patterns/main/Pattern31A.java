package com.company;

import java.util.Scanner;

public class Pattern31A {
    // Pattern 31 A
    public static void main(String [] args){
        /*
        Pattern 31 A
                        0 0 0 0 0 0 0 0
                        0 1 1 1 1 1 1 0
                        0 1 2 2 2 2 1 0
                        0 1 2 3 3 2 1 0
                        0 1 2 3 3 2 1 0
                        0 1 2 2 2 2 1 0
                        0 1 1 1 1 1 1 0
                        0 0 0 0 0 0 0 0

         */
        // Creating Scanner Object For taking inputs from the USER
        Scanner sc = new Scanner(System.in);
        // Take Number of ROWS and COLUMNS from the USER
        System.out.print(" Enter Number of ROWS for the Pattern: ");
        int n = sc.nextInt();
        pattern(n);
    }
    static void pattern(int n){
        // Procedure to print the Required Pattern
           int rcSize = 2 * n - 1;   // Row Column SIZE
        for(int row =0; row <= rcSize; row++){
            for(int column = 0; column <= rcSize; column++){
                int atEveryIndex = Math.min(Math.min(row, column), Math.min(rcSize - row , rcSize  - column));
                System.out.print(atEveryIndex + " ");
            }
            System.out.println();
        }
    }
}
