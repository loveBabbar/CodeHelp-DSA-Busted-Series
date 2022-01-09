package com.company;

import java.util.Scanner;
import java.lang.Math;
public class LargestNumber {
    public static void main(String [] args){
        // Find Largest of Three Numbers

        // Creating Scanner Object for taking inputs from the user
        Scanner sc = new Scanner(System.in);

        // Taking First Number From User
        System.out.print(" Enter First Number: ");
        int num1 = sc.nextInt();

        // Taking Second Number From User
        System.out.print(" Enter Second Number: ");
        int num2 = sc.nextInt();

        // Taking Third Number From User
        System.out.print(" Enter Third Number: ");
        int num3 = sc.nextInt();

        int largestNumber = num1 ;

        if(num2 > largestNumber){
            largestNumber = num2;
        }
        if (num3 > largestNumber){
            largestNumber = num3;
        }
        if((num1 == num2) && (num2 == num3)){
            System.out.println(" All Numbers are Equal ");
            return ;
        }
        System.out.println(" Largest Number is: " + largestNumber);



        // Using Max function
        int max = Math.max(num1,Math.max(num2,num3));
        System.out.println(" Largest Number is: " + max);
    }
}
