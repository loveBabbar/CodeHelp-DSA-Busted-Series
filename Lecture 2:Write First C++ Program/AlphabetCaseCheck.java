package com.company;

import java.util.Scanner;
public class AlphabetCaseCheck {
    public static void main(String [] args){
        //Creating Scanner Object for taking input from the user
        Scanner sc = new Scanner(System.in);

        // Taking Alphabet as a input from user
        System.out.print(" Enter any Alphabet: ");
        char ch= sc.next().trim().charAt(0);
        if(ch>='a' && ch<='z')
            System.out.println(ch + " is in Lowercase ");
        else if (ch >='A' && ch<= 'Z')
            System.out.println(ch + " is in UpperCase ");
        else
            System.out.println(ch + " is Not a Valid Character ");
    }
}
