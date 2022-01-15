package com.company;

import java.util.Scanner;

public class Pattern33 {
    // Pattern 33
    public static void main(String [] args){
        /*
        Pattern 33
                           a
                           B c
                           D e F
                           g H i J
                           k L m N o
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
        int ch = 65;
        for(int row =1; row <= n ; row++){
            for(int column = 1; column <= row ; column++){
                if(ch % 2 == 0)
                    System.out.print((char)(ch) + " ");
                else
                    System.out.print((char)(ch + 32) + " ");
                ch ++;
            }
            System.out.println();
        }
    }
}
