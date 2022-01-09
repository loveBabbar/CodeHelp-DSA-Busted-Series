package com.company;

import java.util.Arrays;

public class PrintArrayElements {
    // Printing Array Elements
    public static void main(String [] args){
        int [] arr = new int[4];
        arr[0] = 3;
        arr[1] = 7;

        System.out.println(Arrays.toString(arr));  // [3, 7, 0, 0]

        String [] arr1 = new String[5];
        arr1[0] = " Deep ";
        arr1[1] = " Deepak ";

        System.out.println(Arrays.toString(arr1));    // [ Deep ,  Deepak , null, null, null]
    }
}
