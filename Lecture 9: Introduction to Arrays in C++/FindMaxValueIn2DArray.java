package com.company;

import java.util.Scanner;
import java.util.Arrays;
public class FindMaxValueIn2DArray {
    // Find Maximum Value in 2D Array
    public static void main(String [] args){
        // Creating Scanner Object for taking Inputs from the USER
        Scanner sc = new Scanner(System.in);
        // Taking no of Rows and Columns from the USER
        System.out.print(" Enter Number of Rows and Columns: ");
        int noOfRows = sc.nextInt();
        int noOfColumns = sc.nextInt();
        // Declare the 2D Array of Required SIZE
        int [][] arr = new int[noOfRows][noOfColumns];

        // Fill the 2D Array by Taking Inputs from the USER
        System.out.print(" Enter Elements ROW wise: ");
        for(int [] row: arr){
            for(int i= 0; i< row.length; i++)
                row[i] = sc.nextInt();
        }
        // Display the 2D Array
        for(int [] row: arr)
            System.out.println(Arrays.toString(row));
        //Display the Maximum Element from the 2D Array
        System.out.println(" Maximum Element in Given Array is: " + maximum(arr));
    }

    static int maximum(int [][] arr){
        int max = Integer.MIN_VALUE;
        // Iterate over the 2D Array
        for(int [] row: arr){    // For Every Row in 2D ARRAY
            for(int element : row){   // For Every Element in row of 2D ARRAY
                if(element > max)  // If any Element is Greater than initial max Value
                    max = element;  // Update the max Value
            }
        }
        // Return the Maximum Value
        return max;
    }
}

