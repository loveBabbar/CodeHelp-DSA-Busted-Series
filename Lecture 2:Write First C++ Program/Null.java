package com.company;

public class Null {
    // Null is a Special Literal  --> Similar to none in Python
    // --> Used with non - primitive Type
    // Example String a = null ;
    // But int a = null ; --> ERROR!!!
    public static void main(String [] args){
        // Creating Integer Array
        int [] intArr = new int[2];
        /*
        By Default it is [0, 0]
        Before not being Initialised
         */

        System.out.println(intArr[0]);

        // Creating String Array of Non- Primitive Type
        String [] strArr = new String[2];
        // By Default all Values are null
        System.out.println(strArr[0]);

    }
}
