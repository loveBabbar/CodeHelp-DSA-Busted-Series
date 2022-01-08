package com.company;

import java.util.Scanner;

public class Pattern18 {
    // Pattern 18
    public static void main(String [] args){
        /*
        Pattern 18
                                  **********
                                  ****  ****
                                  ***    ***
                                  **      **
                                  *        *
                                  *        *
                                  **      **
                                  ***    ***
                                  ****  ****
                                  **********
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
        int inSpaces = 2;
        int belowSpaces = 2 * n - 2;
        for(int row =1; row <= 2 * n ; row++){

            int totalColumns = row > n ? row - n: n - row + 1;
            for(int column = 1; column <= totalColumns; column++){
                System.out.print("*");
            }
            if(row <= n && row != 1) {
                for (int spaces = 1; spaces <= inSpaces; spaces++) {
                    System.out.print(" ");
                }
                inSpaces = inSpaces + 2;
            }
            if(row > n && row != 2 * n){
                for (int spaces = 1; spaces <= belowSpaces; spaces++) {
                    System.out.print(" ");
                }
                belowSpaces = belowSpaces - 2;
            }


            for(int column = 1; column <= totalColumns; column++){
                System.out.print("*");
            }

            System.out.println();
        }
    }
}
