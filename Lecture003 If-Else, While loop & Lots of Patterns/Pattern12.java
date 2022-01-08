package com.company;

import java.util.Scanner;

public class Pattern12 {
    // Pattern 12
    public static void main(String [] args){
        /*
        Pattern 12
                                 * * * * *
                                  * * * *
                                   * * *
                                    * *
                                     *
                                     *
                                    * *
                                   * * *
                                  * * * *
                                 * * * * *
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
        for(int row =1; row <= 2 * n ; row++){
            int totalSpaces = row > n ? n - (row - n) : row - 1;
            for(int spaces = 1; spaces<=totalSpaces; spaces++){
                System.out.print("  ");
            }
            int totalColumns = row > n ? row - n : n - row  + 1 ;
            for(int column = 1; column <= totalColumns; column++){
                System.out.print("*   ");
            }
            System.out.println();
        }
    }
}
