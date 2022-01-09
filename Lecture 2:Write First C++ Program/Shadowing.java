package com.company;

public class Shadowing {
    static int a = 20; // This will be Shadowed at line 11
    // Global Variable
    // Block scope inside class
    // *** a is Static because we want to use it in main method ***
    public static void main(String [] args){
        /*
        Shadowing Starts from the Place where we declared the variable
        Scope will begin when Value is Initialized
        Example
        int a; // Declaration
        System.out.println(a);  --> ERROR !
        a = 40;  --> Initialization
         */
        System.out.println(a);    // a = 20
        int a = 40;      // The Class Variable at line number 4 is shadowed by this
        System.out.println(a);    // a = 40
        func();
    }
    static void func(){
        /*
        No Local Variable inside the Function so
        print function will print the Value of Global Variable
         */
        System.out.println(a);    // a = 20
    }

}
