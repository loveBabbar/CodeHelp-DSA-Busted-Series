package com.company;

import java.util.Arrays;
public class MaxElementInRangeInArray {
    public static void main(String [] args){
        int [] arr = {1,2,3,421,2,1};
         //  int [] arr = {};
        int maxElement = max(arr, 1,3);

        System.out.println(" Max Element in Array " + Arrays.toString(arr) + " Between range " + 1 + " and " + 3 + " is: " + maxElement);
    }

    static int max(int [] arr, int start, int end) {

        if (arr.length == 0) {
            return 0;
        } else {
            int maxElement = arr[start];
            for (int i = start; i <= end; i++) {
                if (arr[i] > maxElement)
                    maxElement = arr[i];
            }
            return maxElement;
        }
    }
}
