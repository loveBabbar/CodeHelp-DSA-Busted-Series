package com.company;

import java.util.Arrays;
public class PassingInFunctions {
    // Passing Arrays to Functions
    public static void main(String [] args){
        int [] nums = {1,2,3,4,5};
        System.out.println(Arrays.toString(nums));
        fun(nums);
        System.out.println(Arrays.toString(nums));
        int [] arr = func(nums);
        System.out.println(Arrays.toString(arr));
    }

    static void fun(int [] arr){
        arr[0]= 90;
    }

    static int [] func(int [] arr){
        arr[0] = 10;
        return arr;
    }
}
