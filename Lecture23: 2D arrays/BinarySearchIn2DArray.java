package com.company;

import java.util.Scanner;
import java.util.Arrays;
public class BinarySearchIn2DArray {
    // Binary Search in 2D Array
    public static void main(String [] args){
        /*
         This Program will work only for Following Type of Matrices
       Sorted in ROW as well COLUMN wise manner
          [ 10, 20, 30, 40 ]
          [ 15, 25, 35, 45 ]
          [ 28, 29, 37, 49 ]
          [ 33, 34, 38, 50 ]
         */
        // Creating scanner Object for taking Inputs from the USER
        Scanner sc = new Scanner(System.in);
        // take Number of Rows and Columns as a Input from the USER
        System.out.print(" Enter Number of ROWS and COLUMNS: ");
        int noOfRows = sc.nextInt();
        int noOfColumns = sc.nextInt();
        // Create 2D Array with Required SIZE
        int [][] arr = new int[noOfRows][noOfColumns];
        // Fill the Array By taking Inputs from the USER
        System.out.print(" Enter Elements Row Wise: ");
        for(int [] row: arr){
            for(int i=0; i<row.length;i++)
                row[i] = sc.nextInt();
        }
        // Display the 2D Array
        for(int []row: arr){
            System.out.println(Arrays.toString(row));
        }
        // Take Target Element as Input from the USER
        System.out.print(" Enter target Element that You Want to Find: ");
        int target = sc.nextInt();
        // Display is the target Found in 2D array
        System.out.println(target + " Found in Given 2D Array at Index " + Arrays.toString(search(arr, target)));
    }
    static int[] search(int [][] matrix, int target){
        int r = 0;
        int c = matrix[r].length -1;
        while(r < matrix[r].length && c >= 0){
            if(matrix[r][c] == target)
                return new int[]{r, c};
            if(matrix[r][c] < target)
                r++;
            else
                c--;
        }
        return new int[]{-1, -1};
    }
}
