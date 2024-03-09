package com.company;

import java.util.Scanner;

public class Pattern16 {
    // Pattern 16    --> PASCAL'S TRIANGLE    V.V. IMPORTANT
    public static void main(String [] args){
        /*
        Pattern 16  --> PASCAL'S TRIANGLE V.V. IMPORTANT
                          1
                        1   1
                      1   2   1
                    1   3   3   1
                  1   4   6   4   1

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
            int c = 1;
            for(int column = 1; column <= row ; column++){
                System.out.print( c  + "   ");
                c = c * (row - column)/ column;
            }
            System.out.println();
        }
    }
}
