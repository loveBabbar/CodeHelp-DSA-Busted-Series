package com.company;

import java.util.Scanner;

public class Pattern32A {
    // Pattern 32 A
    public static void main(String [] args){
        /*
        Pattern 32 A
                                5
                                4 5
                                3 4 5
                                2 3 4 5
                                1 2 3 4 5
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

            int number = n - row + 1;
            for(int column = 1; column <= row ; column++){
                System.out.print( number + " ");
                number ++;
            }
            System.out.println();
        }
    }
}
