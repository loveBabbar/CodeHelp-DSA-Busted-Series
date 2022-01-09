package com.company;

import java.util.Scanner;
public class SumOfNaturalNumbers {
    // Calculate the Sum of Natural Numbers
    public static void main(String [] args){
        /*
        Natural Numbers --> 1,2,3,4,.......... (Numbers starts from 1)
        Sum of N Natural Numbers can be Calculated as
            1 + 2 + 3 + ............... + N  = N(N+1)/2
         */
        // Creating Scanner Object for taking inputs from the USER
        Scanner sc = new Scanner(System.in);
        // Take Nth term from the USER
        System.out.print(" Enter Nth Term for the SUM of Natural Numbers: ");
        int n = sc.nextInt();
        // Now Calculate the SUM of N Natural Numbers
        int sum = (n*(n+1))/2;
        // Displaying the SUM on the Screen
        System.out.println(" SUM of " + n + " Natural Number are: " + sum);
    }
}
