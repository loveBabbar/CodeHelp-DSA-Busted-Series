package com.company;

import java.util.Scanner;

public class Swap {

    public static void main(String [] args){
        // Creating Scanner Object for Taking inputs from the User
        Scanner sc = new Scanner(System.in);

        // Taking Two Numbers as a Input From the User
        System.out.print(" Enter Two Numbers: ");
        int a = sc.nextInt();
        int b = sc.nextInt();

        // Passing Numbers to Swap Function
        swap(a,b);
       System.out.println( a +" " + b);

       String name = " Deepak Kumar";
       changeName(name);
       System.out.println(" NAme: " + name);
    }

    public static void swap(int a , int b){
        int temp = a;
        a = b;
        b = temp;
        System.out.println(" After Swapping Numbers are: " + a + " " + b);
    }

    static void changeName(String name){
        name = " Divans ";
    }
}
