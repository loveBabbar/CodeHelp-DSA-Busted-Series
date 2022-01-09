package com.company;

import java.util.Arrays;
public class MaxElementInArray {
    public static void main(String [] args){
        int [] arr = {1,2,4,5,2,3};

        int max = arr[0];
        for(int i = 1;i<arr.length ; i++){
            if(arr[i]> max)
                max = arr[i];
        }

        System.out.println(" Maximum Element in Array "+ Arrays.toString(arr) + " is: " + max);
    }
}
