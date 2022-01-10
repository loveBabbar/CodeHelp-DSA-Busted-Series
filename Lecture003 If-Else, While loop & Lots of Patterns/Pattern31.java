package com.company;

import java.util.Scanner;

public class Pattern31 {
    // Pattern 31
    public static void main(String [] args){
        /*
        Pattern 31
                             4 4 4 4 4 4 4
                             4 3 3 3 3 3 4
                             4 3 2 2 2 3 4
                             4 3 2 1 2 3 4
                             4 3 2 2 2 3 4
                             4 3 3 3 3 3 4
                             4 4 4 4 4 4 4

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
        int rcSize = 2 * n - 1; // Row Column SIZE
        for(int row =1; row <=rcSize; row++){
            for(int column = 1; column <= rcSize; column++){
                int atEveryIndex = n -  Math.min(Math.min(row - 1, column - 1), Math.min(rcSize  - row , rcSize  - column));
                System.out.print(atEveryIndex + " ");
            }
            System.out.println();
        }
    }
}
