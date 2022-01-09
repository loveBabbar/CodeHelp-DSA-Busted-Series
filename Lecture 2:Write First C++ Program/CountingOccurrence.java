package com.company;

import java.util.Scanner;
public class CountingOccurrence {
    public static  int occurrenceCount(int number, int digit){
        int count = 0;
        while(number>0){
            int remainder = number%10;    // Last Digit
            if(remainder == digit){
                count++;
            }
            number  /= 10;    // Equivalent to number = number/10
        }
        return count;
    }

    public static void main(String [] args){
        // Creating Scanner Object for taking input from user
        Scanner sc = new Scanner(System.in);

        System.out.print(" Enter Any Number: ");
        int number = sc.nextInt();

        System.out.print(" Enter that digit for which you want to find the Counting Occurrence: ");
        int digit = sc.nextInt();

        int count = occurrenceCount(number,digit);
        System.out.println(" For Digit "+ digit + " Counting Occurrence is: "+ count);
    }
}
