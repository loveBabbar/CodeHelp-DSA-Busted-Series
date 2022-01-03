package com.company;

import java.util.Arrays;

public class StringsVarArgs {
    public static void main(String [] args){
        func(" Deep ", " Deepak ", " Deepak Kumar ");
    }
    static void func(String ...v){
        // All the Inputs passed to This Function Will be Stored as an Array in v
        System.out.println(Arrays.toString(v));
    }
}
