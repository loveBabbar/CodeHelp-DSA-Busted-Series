package com.company;

import java.util.Scanner;

public class Pattern1 {
    // Pattern 1
    public static void main(String [] args){
        /*
        Pattern 1
            *******
            *******
            *******
         */
        // Creating Scanner Object For taking inputs from the USER
        Scanner sc = new Scanner(System.in);
        // Take Number of ROWS and COLUMNS from the USER
        System.out.print(" Enter Number of ROWS and COLUMNS for the Pattern: ");
        int noOfRows = sc.nextInt();
        int noOfColumns = sc.nextInt();

        // Procedure to Print the Required Pattern
        for(int row = 1; row <= noOfRows; row++){
            for(int column = 1; column <= noOfColumns; column++){
                System.out.print("*");
            }
            System.out.println();
        }
    }
}
