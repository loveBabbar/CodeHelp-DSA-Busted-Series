package com.company;

import java.util.*;
public class SetMatrixZeroes {
    //Set Matrix Zeroes
    public static void main(String [] args){
        /*
        https://leetcode.com/problems/set-matrix-zeroes/
         */
        // Creating Scanner Object for taking Input from the USER
        Scanner sc = new Scanner(System.in);

        // Take size of the Matrix from the USER
        System.out.print(" Enter Number of ROWS and COLUMNS: ");
        int noOfRows = sc.nextInt();
        int noOfColumns = sc.nextInt();
        // Declare the 2D Array with Required SIZE
        int [][] matrix = new int[noOfRows][noOfColumns];
        // Fill the Matrix with Elements
        System.out.print(" Enter Elements ROW Wise: ");
        for(int [] row: matrix){
            for(int i=0; i<row.length; i++){
                row[i] = sc.nextInt();
            }
        }
        // Display the Matrix
        for(int [] row: matrix){
            System.out.println(Arrays.toString(row));
        }
        setZeroes(matrix);
        //Display the Resultant Matrix
        for(int [] row: matrix){
            System.out.println(Arrays.toString(row));
        }
    }

    public static void setZeroes(int[][] matrix) {
        // Declare Two Lists
        /*
        Let Matrix is            0   1           <- Column Index
                              [[ 0 , 1 ]]  --> 0 <- Row Index
                  Here 0 is at (0, 0)
                  so    RowIndex --> 0   --> Store it in rowIndex List
                     ColumnIndex --> 0   --> Store it in columnIndex List
         */
        List <Integer> rowIndex = new ArrayList<>();
        List <Integer> columnIndex = new ArrayList<>();
        // Now Iterate Over the Array and store the Indices of Zeros in Lists
        for(int row = 0; row < matrix.length; row++){
            for(int column = 0; column < matrix[row].length ; column++){
                // Check is there any ZERO in the MATRIX
                if(matrix[row][column] == 0){
                    // Store the Indices in the LISTS
                    rowIndex.add(row);            // Store row index in rowIndex List
                    columnIndex.add(column);     // Store column index in columnIndex List
                }
            }
        }

//        System.out.println(rowIndex);
//        System.out.println(columnIndex);
        // Now set Zeros in ROWS and COLUMNS where 0 Found

        // SET Complete ROW to 0 for Each rowIndex
        for(int i= 0; i < rowIndex.size(); i++){    // Iterate over rowIndex List for getting Index of ROWS
            int row = rowIndex.get(i);              // Store row index in row variable
            for(int j=0; j< matrix[row].length; j++){  // j --> Counter for Iterate over different COLUMNS of the same ROW
                matrix[row][j] = 0;     // set Elements to 0
            }
        }

        // Now SET Complete COLUMN to 0 for Each columnIndex
        for(int i=0; i<columnIndex.size(); i++){ // Iterate over columnIndex List for getting Index of COLUMNS
            int column = columnIndex.get(i);
            for(int j = 0; j< matrix.length; j++){   // for Different ROWS set that column to 0
                matrix[j][column] = 0;    // Set Elements to 0
            }
        }

    }
}
