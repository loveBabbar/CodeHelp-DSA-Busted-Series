package com.company;

import java.util.Scanner;

public class Pattern4 {
    // Pattern 4
    public static void main(String [] args){
        /*
        Pattern 4
            1
            1 2
            1 2 3
            1 2 3 4
         */
        // Creating Scanner Object For taking inputs from the USER
        Scanner sc = new Scanner(System.in);
        // Take Number of ROWS and COLUMNS from the USER
        System.out.print(" Enter Number of ROWS for the Pattern: ");
        int noOfRows = sc.nextInt();

        // Procedure to Print the Required Pattern
        for(int row = 1; row <= noOfRows; row++){
            for(int column = 1; column <= row; column++){
                System.out.print(column  + " ");
            }
            System.out.println();
        }
    }
}
