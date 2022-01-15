package com.company;

import java.util.Scanner;

public class Pattern26  {
    // Pattern 26
    public static void main(String [] args){
        /*
        Pattern 26
                      1 1 1 1 1 1
                      2 2 2 2 2
                      3 3 3 3
                      4 4 4
                      5 5
                      6
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
        int number = 1;
        for(int row =1; row <= n ; row++){

            for(int column = 1; column <= n - row +1 ; column++){
                System.out.print(number + " ");
            }

            number ++;
            System.out.println();
        }
    }
}
