package com.company;

import java.util.Scanner;

public class HelloName {
    public static void main(String[] args) {

        // Creating Scanner Object for taking Input
        Scanner input = new Scanner(System.in);


        System.out.print(" Please Enter Your Name: ");
        // Taking name as a Input From User
        String name = input.next();  // Here Next Function will take only one Word from the input Line Example Deepak Kumar --> Deepak
        // Printing Hello + Name on the Screen
        System.out.println(" Hello " + name);
    }
}
