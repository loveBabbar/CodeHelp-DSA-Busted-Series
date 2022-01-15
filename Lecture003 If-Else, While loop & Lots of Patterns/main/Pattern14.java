package com.company;

import java.util.Scanner;

public class Pattern14 {
    // Pattern 14
    public static void main(String [] args){
        /*
        Pattern 14
                     *********
                      *     *
                       *   *
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
        int inSpace =  2 * n - 1 - 4;
        for(int row =1; row <= n ; row++){
            for(int spaces = 1; spaces<= row - 1; spaces++){
                System.out.print(" ");
            }
            int totalColumns = row != n ? 2 : 1 ;
            if(row == 1){
                totalColumns = 2 * n - 1;
            }
            for(int column = 1; column <= totalColumns ; column++){
                System.out.print("*");
                if(row >= 2 && row != n){
                    for(int space = 1; space <= inSpace ; space++){
                        System.out.print(" ");
                    }
                    inSpace -= 1;
                }
            }
            System.out.println();
        }
    }
}
