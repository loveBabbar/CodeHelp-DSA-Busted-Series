package com.company;

import java.util.Scanner;

public class Pattern27 {
    // Pattern 27
    public static void main(String [] args){
        /*
        Pattern 27
                      1 2 3 4  17 18 19 20
                        5 6 7  14 15 16
                          8 9  12 13
                            10 11
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
        int secondHalf = (number * number) + 1;
        for(int row =1; row <= n ; row++){
            for(int spaces = 1; spaces <= row - 1; spaces++) {
                System.out.print("  ");
            }

            for(int column = 1; column <= n - row + 1; column++){
                System.out.print(number + " ");
                number ++;
            }

            for(int column = 1; column <=n - row + 1; column++ ){
                System.out.print(secondHalf + " ");
                secondHalf ++;
            }
            System.out.println();
        }
    }
}
