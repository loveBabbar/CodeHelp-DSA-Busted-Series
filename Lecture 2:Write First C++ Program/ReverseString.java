package com.company;

import java.util.Scanner;
public class ReverseString {

    public static String reverseString(String string){
        String reverse = "";
        for(int i = string.length()-1; i>=0; i--){
            reverse += string.charAt(i);
        }
        return reverse;
    }

    public static void main(String [] args){
        // Creating Scanner Object For taking input from user
        Scanner sc = new Scanner(System.in);

        System.out.print(" Enter Any String: ");
        String string = sc.next();

        String result = reverseString(string);
        System.out.println(" Original String is: " + string );
        System.out.println(" Reversed String is: " + result );
    }
}