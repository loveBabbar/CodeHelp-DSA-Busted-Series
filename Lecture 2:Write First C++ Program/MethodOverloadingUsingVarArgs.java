package com.company;

import java.util.Arrays;

public class MethodOverloadingUsingVarArgs {
    public static void main(String [] args){
        numbers(1,2,3,4,5);
        numbers("1","2","3","4","5");
      //  numbers();   --> Ambiguity
        // this is because at Compile Time it's difficult to Decide which one will RUN
    }

    static void numbers(String ...v){
        System.out.println(Arrays.toString(v));
    }

    static void numbers(int ...v){
        System.out.println(Arrays.toString(v));
    }
}
