package com.company;

import java.util.Scanner;

public class Pattern5A {
    // Pattern 5 A
    public static void main(String [] args){
        /*
        Pattern 5 A
        1
        1 2
        1 2 3
        1 2
        1
         */
        // Creating Scanner Object For taking inputs from the USER
        Scanner sc = new Scanner(System.in);
        // Take Number of ROWS and COLUMNS from the USER
        System.out.print(" Enter Number of ROWS for the Pattern: ");
        int n = sc.nextInt();
        pattern5(n);
    }
    static void pattern5(int n){
        // Procedure to print the Required Pattern
        for(int row =0; row < 2*n ; row++){
            int totalColsInRow = row > n ? 2 * n - row : row ;
            for(int column = 0; column < totalColsInRow; column ++){
                System.out.print( (column+1)+ " ");
            }
            System.out.println();
        }
    }
}
