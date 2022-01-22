package com.company;

import java.util.Scanner;

public class Pattern32C {
    // Pattern 32 C
    public static void main(String [] args){
        /*
        Pattern 32 C
                            E
                            E D
                            E D C
                            E D C B
                            E D C B A
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
                ch --;
            }
            System.out.println();
        }
    }
}
