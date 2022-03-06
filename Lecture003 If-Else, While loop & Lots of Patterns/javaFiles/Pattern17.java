package com.company;

import java.util.Scanner;

public class Pattern17 {
    // Pattern 17
    public static void main(String [] args){
        /*
        Pattern 17
                    1
                  2 1 2
                3 2 1 2 3
              4 3 2 1 2 3 4
            5 4 3 2 1 2 3 4 5
              4 3 2 1 2 3 4
                3 2 1 2 3
                  2 1 2
                    1
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
        for(int row =1; row < 2*n ; row++){
            int c = row > n ? 2 * n - row : row ;
            int spaces = n - c;
            for(int i=0; i <  spaces; i++){
                System.out.print("  ");
            }

            for(int column = c; column >= 1; column--){
                System.out.print(column + " ");
            }
            for(int column = 2; column <= c; column++){
                System.out.print(column + " ");
            }
            System.out.println();
        }
    }
}
