package com.company;

import java.util.Scanner;
public class RecursiveFibonacciNumber {

    public static int fib(int num){
        if (num == 0)
            return 0;
        if (num == 1)
            return 1;
        else
            return (fib(num - 1) + fib(num - 2));
    }

    public static void main(String [] args){
        // Creating Scanner Object for taking Input from the User
        Scanner sc = new Scanner(System.in);

        System.out.print(" Enter nth Term for Fibonacci Number: ");
        int num = sc.nextInt();

        if(num>= 0){
            int result = fib(num);
            System.out.println(" Fibonacci number is : " + result);
        } else {
            System.out.println(" Wrong Input !!!");
        }

    }
}
