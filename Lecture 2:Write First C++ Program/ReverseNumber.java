package com.company;

import java.util.Scanner;
public class ReverseNumber {

    public static int reverseNumber(int number){
        int reverse = 0;
        while(number>0){
            int remainder = number % 10;
            reverse = (reverse * 10) + remainder;
            number = number/10;
        }
        return reverse;
    }

    public static void main(String [] args){
        // Creating Scanner Object For taking input from user
        Scanner sc = new Scanner(System.in);

        System.out.print(" Enter Any Number: ");
        int number = sc.nextInt();

        int result = reverseNumber(number);
        System.out.println(" Original Number is: " + number );
        System.out.println(" Reversed Number is: " + result );
    }
}
