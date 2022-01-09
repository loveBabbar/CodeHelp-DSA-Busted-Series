package com.company;

import java.util.Scanner;

public class SumFunction {

    // Sum Function
    public static int sumOfNumbers(int a, int b){
        return a+b;
    }

    public static void main(String [] args){
        // Q: Take input of Two Numbers and Print the SUM
        // Creating Scanner object for taking inout from the user
        Scanner sc = new Scanner(System.in);
        int num1,num2,sum;
        // Taking First Number
        System.out.print(" Enter First Number: ");
       num1 = sc.nextInt();
        // Taking Second Number
        System.out.print(" Enter Second Number: ");
        num2 = sc.nextInt();
        // Passing these Inputs to the Function Sum which will return Sum of these Numbers
       sum = sumOfNumbers(num1,num2);

        // Displaying Sum on the Screen
        System.out.println(" Sum of " + num1 + " and " + num2 + " is: " + sum);
    }
}
