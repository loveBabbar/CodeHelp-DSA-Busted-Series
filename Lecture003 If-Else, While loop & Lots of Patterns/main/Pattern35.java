package com.company;

import java.util.Scanner;

public class Pattern35 {
    // Pattern 35
    public static void main(String [] args){
        /*
        Pattern 35
                                   1      1
                                   12    21
                                   123  321
                                   12344321
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
        int inSpaces = 2 * n - 2;
        for(int row =1; row <= n ; row++){

            for(int column = 1; column <= row ; column++){
                System.out.print(column);
            }

            // Printing Spaces In SIDE
            for(int spaces = 1; spaces <= inSpaces; spaces++){
                System.out.print(" ");
            }
            inSpaces = inSpaces - 2;

            for(int column = row; column >= 1; column--)
                System.out.print(column);
            System.out.println();
        }
    }
}
