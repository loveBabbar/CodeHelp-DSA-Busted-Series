package com.company;

import java.util.Scanner;
import java.util.Arrays;
public class SearchingInMatrices {
    // Searching Elements in Matrices
    public static void main(String [] args){
        // Creating Scanner Object for taking Input from the USER
        Scanner sc = new Scanner(System.in);
        // Take Number of Rows and Columns as a Input from the USER
        System.out.print(" Enter Number of ROWS and COLUMNS: ");
        int noOfRows = sc.nextInt();
        int noOfColumns = sc.nextInt();
        // Create 2D Array of Required SIZE
        int [][] arr = new int[noOfRows][noOfColumns];
        // fill the Array by taking Inputs ROW WISE
        for(int [] row: arr){
            for(int i=0; i<row.length; i++)
                row[i] = sc.nextInt();
        }
        // Display the 2D Array
        for(int []row: arr)
            System.out.println(Arrays.toString(row));
        // Take target Element to Find From the USER
        System.out.print(" Enter Target Element that you want to find: ");
        int target = sc.nextInt();
        if(search(arr, target))
            System.out.println(target + " Found in the Given ARRAY");
        else
            System.out.println(target + " NOT Found in the Gib=ven ARRAY");
    }

    static boolean search(int[][] arr, int target){
        for(int [] row: arr){     // For Every ROW in target
            for (int element : row) {    // for Every Element in that ROW
                if (element == target)   // check if target is Equal to that element or not
                    // if YES then return true
                    return true;
            }
        }
        // If target not Found then return false
        return false;
    }
}
