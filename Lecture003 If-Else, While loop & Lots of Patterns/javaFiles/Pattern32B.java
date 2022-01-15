package com.company;

import java.util.Scanner;

public class Pattern32B {
    // Pattern 32B
    public static void main(String [] args){
        /*
        Pattern 32B
                            E
                            E F
                            E F G
                            E F G H
                            E F G H I
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

            int ch = 60 + n + 4;  // ( e.g E = 69 (in ASCII) so 60 + 5 + 4 )
            for(int column = 1; column <= row ; column++){
                System.out.print( (char)(ch) + " ");
                ch ++;
            }
            System.out.println();
        }
    }
}
