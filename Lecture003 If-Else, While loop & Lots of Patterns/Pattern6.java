package com.company;

import java.util.Scanner;

public class Pattern6 {
    // Pattern 6
    public static void main(String [] args){
        /*
        Pattern 6
                     *
                    **
                   ***
                  ****
                 *****
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
        for(int row =1; row <= n ; row++){
            for(int spaces = 1; spaces<= n - row; spaces++){
                System.out.print("  ");
            }
            for(int column = 1; column <= row; column ++){
                System.out.print("* ");
            }
            System.out.println();
        }
    }
}
