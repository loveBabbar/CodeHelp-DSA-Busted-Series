package com.company;

import java.util.Arrays;
public class SwapArrayElementsAtGivenIndex {
    public static void main(String [] args){

        // Creating array
        int [] arr = {1,2,3,4,5};

        // Printing Array Before Swapping
        System.out.print(" Array Before Swapping: ");
        System.out.println(Arrays.toString(arr));

        // Swapping Array Elements at Indices 1 and 3
        swap(arr,1,3);

        // Printing Array After Swapping
        System.out.print(" Array After Swapping: ");
        System.out.println(Arrays.toString(arr));
    }

    static void swap(int [] arr, int index1, int index2){
        int temp = arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = temp;
    }
}
