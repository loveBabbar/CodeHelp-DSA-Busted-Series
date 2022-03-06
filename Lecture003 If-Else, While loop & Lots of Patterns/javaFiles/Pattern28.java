package com.company;

import java.util.Scanner;

public class Pattern28 {
    // Pattern 28
    public static void main(String [] args){
        /*
        Pattern 28
                  *
                 * *
                * * *
                 * *
                  *
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
        for(int row =0; row < 2*n ; row++){
            int totalColsInRow = row > n ? 2 * n - row : row ;
            int spaces = n - totalColsInRow;
            for(int i=0; i< spaces; i++){
                System.out.print(" ");
            }
            for(int column = 0; column < totalColsInRow; column ++){
                System.out.print("* ");
            }
            System.out.println();
        }
    }
}
