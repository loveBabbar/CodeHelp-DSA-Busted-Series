package com.company;

import java.util.Scanner;

public class Pattern20  {
    // Pattern 20
    public static void main(String [] args){
        /*
        Pattern 20
                           ****
                           *  *
                           *  *
                           *  *
                           ****
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
            int totalColumns = 2;
            if(row == 1 || row == n)
                totalColumns = n - 1;
            for(int column = 1; column <= totalColumns ; column++){
                System.out.print("* ");
                if(row > 1 && row < n){
                    for(int spaces = 1; spaces <= n - 3 ; spaces++)
                        System.out.print("  ");
                }
            }
            System.out.println();
        }
    }
}
