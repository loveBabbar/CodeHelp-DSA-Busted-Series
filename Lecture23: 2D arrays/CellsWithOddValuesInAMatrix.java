package com.company;

import java.util.Scanner;
import java.util.Arrays;

public class CellsWithOddValuesInAMatrix {
    // Cells with Odd Values in a Matrix
    public static void main(String [] args){
        /*
        https://leetcode.com/problems/cells-with-odd-values-in-a-matrix/

            Input: m = 2, n = 3, indices = [[0,1],[1,1]]
            Output: 6
            Explanation: Initial matrix = [[0,0,0],[0,0,0]].
            After applying first increment it becomes [[1,2,1],[0,1,0]].
            The final matrix is [[1,3,1],[1,3,1]], which contains 6 odd numbers.
         */

        // Creating Scanner Object for taking Inputs From the User
        Scanner sc = new Scanner(System.in);
        // Now taking ROWS and COLUMNS from the USER for 2D Array
        System.out.print(" Enter Number of ROWS and COLUMNS: ");
        int noOfRows = sc.nextInt();
        int noOfColumns = sc.nextInt();

        // Now Declaring Array of Required Size
       // int [][] arr = new int[noOfRows][noOfColumns];   // By default All Values are 0

        // indices Array
        int [][] indices = {{0,1},
                            {1,1}};

        // Passing Number of Rows, Columns of Matrix and indices Matrix
        int oddNumberCount = oddCells(noOfRows, noOfColumns, indices);
        // Displaying Odd Cells Count
        System.out.println(" Number of Odd Cell Count: " + oddNumberCount);
    }
    public static int oddCells(int m, int n, int[][] indices) {
        // Now Initialising Array with Number of ROWS m and Number of Columns n
        int[][] arr = new int[m][n];

        // Iterate Over Indices Array
        for (int[] row : indices) { // loop For Every ROW
            for (int i = 0; i < row.length; i++) {   // For For Columns in the ROW
                // if i=0 we will get ri
                if (i == 0) {
                    int ri = row[i];
                    // Now for this ROW index in ARRAY increment Values by 1
                    for (int j = 0; j < n; j++) { // j -> For Iterating Over Columns
                        arr[ri][j] += 1;    // Incrementing the Elements
                        // Here ri --> IS FIXED it means for a Particular ROW increment Elements by 1
                    }
                } else if (i == 1) {
                    // Now if i= 1 we will get ColumnIndex (i.e ci )
                    int ci = row[i];
                    // For this Column Index in ARRAY increment Values BY 1
                    for (int j = 0; j < m; j++) {  // j -> For Iterating Over Rows
                        arr[j][ci] += 1;  // Incrementing the Elements
                        // Here ci -> IS FIXED it means for a Particular Column Increment Elements by 1
                    }
                }
            }
        }
        // Now Initially take Count of ODD elements as 0
        int count = 0;
        // Iterate Over Array
        for (int[] row : arr) {  // For Every ROW
            for (int j : row) {    // Iterate Over Columns
                if (j % 2 != 0) {   // If Element in ROW at index i is ODD (i.e Not Divisible by 2)
                    count++;            // Increment the COUNT
                }
            }
        }
        // At the END Return the Total Count of Odd Elements
        return count;
    }
}

