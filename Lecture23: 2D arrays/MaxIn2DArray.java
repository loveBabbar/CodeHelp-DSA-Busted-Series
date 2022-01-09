package com.company;

import java.util.Scanner;
import java.util.Arrays;
public class MaxIn2DArray {
    // Find Maximum Element in 2D array
    public static void main(String [] args){
        // Creating 2D Array
        int [][] arr = {{1,2,3,4,5,6},
                        {7,8,9,98},
                        {5,7,9,90,76}};
        // Creating Scanner Object for taking Inputs from the USER
        Scanner sc = new Scanner(System.in);
        //Display the Array
        for(int [] row: arr){
            System.out.println(Arrays.toString(row));
        }
        // Take Element that USER want to Find
        System.out.print(" Enter Element that you want to Find: ");
        int key = sc.nextInt();
        // Display the Indices where key Exist in the Array
        System.out.println(key + " Found At Index: " + Arrays.toString(findKey(arr, key)));
    }

    static int[] findKey(int [][] arr, int key){
        // Iterate over 2D Array
        for(int row =0; row< arr.length; row++){
            for(int col= 0; col < arr[row].length; col++){
                if(arr[row][col] == key)
                    return new int[]{row, col};
            }
        }
        return new int[]{-1, -1};
    }
}
