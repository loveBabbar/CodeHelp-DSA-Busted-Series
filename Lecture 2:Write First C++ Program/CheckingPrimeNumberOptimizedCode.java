package com.company;

import java.util.Scanner;

public class CheckingPrimeNumberOptimizedCode {
    public static void main(String[] args) {

        // Creating Scanner Object for Taking input From User
        Scanner input = new Scanner(System.in);

        System.out.println(" Enter Any Number: ");
        // Taking Integer Number
        int number = input.nextInt();

        int c = 2;
        // Checking from 2 Till < number
        while(c*c <number){
            // If any number between 2 and that number divides the Number then it is not a Prime Number
            if (number % c == 0){
                System.out.println(number + " is Not a Prime Number" );
                // Once it is Clear that Number is not Prime then Exit the While Loop
                return;
            }
            c = c+1;
        }
        // Once we checked for all the number and No number Divides the number in between
        // then It is Sure that the Number is a Prime Number
        System.out.println(number + " is a Prime Number ");
    }
}
