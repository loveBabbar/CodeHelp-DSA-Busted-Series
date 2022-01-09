package com.company;

import  java.util.Scanner;
public class GreetName {
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);
        System.out.print(" Enter Your Name: ");
        String name = sc.nextLine();
        String greet = greeting(name);
//        System.out.println(greet);
//         greet = greeting("Divyansh");
        System.out.println(greet);
    }

    static String greeting(String name){
        String greet = " Hello " + name;
        return greet;
    }
}
