package com.company;

import java.util.Scanner;
public class SumOfNaturalNumbersUsingWhileLoop {
    // SUM of n Natural Numbers Using While Loop
    public static void main(String [] args){
        // Creating Scanner Object for taking Inputs from the USER
        Scanner sc = new Scanner(System.in);
        // Taking nth Term of the Natural Number as a Input From the USER
        System.out.print(" Enter Nth Term for SUM of the Natural Numbers: ");
        int n = sc.nextInt();
        int number = n;
        // Sum Numbers till n doesn't Equal to 1
        int sum = 0;
        while(n >= 1){
            sum += n;
            n--;
        }
        // Display the SUM of n Natural Numbers
        System.out.println(" SUM of " + number + " Natural Numbers are: " + sum);
    }
}
