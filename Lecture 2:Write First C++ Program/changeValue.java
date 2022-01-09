package com.company;

import java.util.Arrays;

public class changeValue {
    public static void main(String [] args){
        // Creating an Array
        int [] arr  = new int[5];
        arr= new int[]{1, 2, 23, 4};
        change(arr);

        // Printing Array
        System.out.println(" Array is: " + Arrays.toString(arr));
    }

   public static void change(int [] nums){
        nums[0] = 99;
    }
}
