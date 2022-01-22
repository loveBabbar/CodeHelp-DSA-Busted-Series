package com.company;

import java.util.Scanner;

public class Pattern29 {
    // Pattern 29
    public static void main(String [] args){
        /*
        Pattern 29

                               *        *
                               **      **
                               ***    ***
                               ****  ****
                               **********
                               ****  ****
                               ***    ***
                               **      **
                               *        *
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
        int inSpaces =  2 * n - 2;
        int belowSpaces = 2;
        for(int row =1; row <= 2 * n - 1 ; row++){
            int totalColumns = row > n ? 2 * n - row: row;
            for(int column = 1; column <= totalColumns; column++){
                System.out.print("*");
            }
            if(row <= n) {
                for (int spaces = 1; spaces <= inSpaces; spaces++) {
                    System.out.print(" ");
                }
                inSpaces -= 2;
            } else{
                for (int spaces = 1; spaces <= belowSpaces; spaces++) {
                    System.out.print(" ");
                }
                belowSpaces += 2;
            }

            for(int column = 1; column <= totalColumns; column++){
                System.out.print("*");
            }

            System.out.println();
        }
    }
}
