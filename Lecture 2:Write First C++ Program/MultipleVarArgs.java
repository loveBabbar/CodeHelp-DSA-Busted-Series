package com.company;

import java.util.Arrays;

public class MultipleVarArgs {
    public static void main(String [] args){
        function(89,90,"Deep", "Deepak");
    }
    static void function(int a,int b, String ...v){
        System.out.println(Arrays.toString(v));
    }
}
