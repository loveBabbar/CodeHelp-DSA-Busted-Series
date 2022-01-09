package com.company;

import java.util.Arrays;

public class MethodOverloading {
    public static void main(String [] args){
        /*
        Function Overloading:
                --> Functions with same NAME but different Parameters
                is Known as Function Overloading
                --> Function Overloading is determined at COMPILE TIME
        Function Overriding is the Concept of OOP
         */

        sum(2,3);
        sum(2,3,1);
        sum(2,1,1,4);
    }

    static void sum(int a, int b){
        int s = a+b;
        System.out.format(" Sum of %d and %d is: %d", a,b,s);
    }

    static void sum(int a, int b,int c){
        int s = a+b+c;
        System.out.format("\n Sum of %d, %d and %d is: %d\n", a,b,c,s);
    }

    static void sum(int ...v){
        System.out.println(Arrays.toString(v));
    }
}
