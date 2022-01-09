package com.company;

import java.util.Scanner;

public class Sum {

    public static void main(String[] args) {

        System.out.println(" Program to Calculate Sum of Two Numbers ");
        // Creating Scanner Object For Taking Inputs From User
        Scanner sc = new Scanner(System.in);
        // Taking Input For First Number
        System.out.print(" Enter First Number: ");
        int num1 = sc.nextInt();

        // Taking Input For Second Number
        System.out.print(" Enter Second Number: ");
        int num2 = sc.nextInt();

        // Calculating Sum of Num1 and Num2
        int num3 = num1 + num2;

        // Printing Sum of These Numbers
        System.out.println(" Required Sum is : " + num3);
        System.out.print(" Do You Want to See The Calculation Part ? (Y or N) ");
        String showCalculation = sc.next();

        // Show Calculations if User Input Y or "y" otherwise Exit
        switch (showCalculation) {
            case "y":
            case "Y":
                System.out.println(" You Entered First Number as : " + num1);
                System.out.println(" You Entered Second Number as : " + num2);
                System.out.println(" Now Sum of " + num1 + " and " + num2 + " is :");
                System.out.println(" " + num1 + " + " + num2 + " = " + (num1 + num2));
                break;
            case "n":
            case "N":
                break;
            default:
                System.out.println(" Wrong Input!! ");
                break;
        }


    }
}
