package com.company;

import java.util.Arrays;

public class VarArgs {
    // Variable length Argument --> varArgs : used when we don't know how many inputs we will be passing
    public static void main(String [] args){
     fun(2,34,5,6);
    }
    static void fun(int ...v){
        System.out.println(Arrays.toString(v));
    }
}
