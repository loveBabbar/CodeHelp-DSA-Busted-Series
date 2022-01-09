package com.company;

import java.util.Arrays;
import java.util.Scanner;
public class SearchIn2DArray {
    // Search in 2D Array
    public static void main(String [] args){
        // Creating Scanner Object for taking Inputs from the USER
        Scanner sc = new Scanner(System.in);
        // Take number of Rows and number of Columns from the USER
        System.out.print(" Enter Number of Rows and Columns of the 2D array: ");
        int noOfRows = sc.nextInt();
        int noOfColumns = sc.nextInt();
        // Declare 2D Array with Given SIZE
        int [][] arr = new int[noOfRows][noOfColumns];
        // Fill the Array by taking Inputs from the USER
        System.out.print(" Enter Elements Row Wise: ");
        for(int [] row: arr){
            for(int i=0; i<row.length ; i++){
                row[i] = sc.nextInt();
            }
        }
        // Display the 2D Array
        for(int []row: arr){
            System.out.println(Arrays.toString(row));
        }
        // Take Element that USER wants to Find in the 2D Array
        System.out.print(" Enter Element You want to Find: ");
        int key = sc.nextInt();

        if(keyFound(arr, key))
            System.out.println(key + " Found in the Given 2D Array ");
        else
            System.out.println(key + " Doesn't Found in the Given 2D Array");
    }

    static boolean keyFound(int [][] arr, int key){
        // Visit Every Element in the 2D Array
        // if Element Found in the Array return true
        // else return False
        for(int [] row: arr){    // For Every Row in the 2D Array
            for (int element : row) {   // iterate over columns in Each Row
                if (element == key)    // Check for Every Element in the 2D Array
                    return true;    // return true if Key Found
            }
        }
        // if Key is Not Found then return false
        return false;
    }
}
