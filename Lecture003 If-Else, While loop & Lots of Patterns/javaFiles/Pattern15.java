package com.company;

import java.util.Scanner;

public class Pattern15 {
    // Pattern 15
    public static void main(String [] args){
        /*
        Pattern 15
                             *
                            * *
                           *   *
                          *     *
                         *       *
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
        int inSpace =  1;
        int inBelowSpace = 2 * n - 5 ;

        for(int row = 1; row <= 2 * n - 1; row++ ){
            int totalColumns = 1;
            if(row != 1 && row != 2 * n - 1 )
                totalColumns = 2;

            int totalSpaces = row > n ?  row - n : n - row;
            for(int space = 1; space <= totalSpaces ; space++) {
                System.out.print(" ");
            }

            for(int column = 1; column <= totalColumns; column ++){
                System.out.print("*");
                if(row > 1 && row <= n) {
                    for (int space = 1; space <= inSpace; space++) {
                        System.out.print(" ");
                    }
                    inSpace  += 1;
                }
                if(row > n) {
                    for(int space = 1; space <= inBelowSpace ; space ++) {
                        System.out.print(" ");
                    }
                    inBelowSpace --;
                }

            }
            System.out.println();
        }
    }
}
