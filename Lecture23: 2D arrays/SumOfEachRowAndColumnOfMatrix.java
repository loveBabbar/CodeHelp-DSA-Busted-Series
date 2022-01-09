package com.company;

import java.util.Arrays;
import java.util.Scanner;

public class SumOfEachRowAndColumnOfMatrix {
    // Find the Sum of Each ROW and COLUMN of a Matrix
    public static void main(String [] args){
        // Creating Scanner Object for taking Inputs from the USER
        Scanner sc = new Scanner(System.in);
        // Take Number of Rows and Columns of Matrix
        System.out.print(" Enter Number of ROWS and COLUMNS of the Matrices: ");
        int noOfRows = sc.nextInt();
        int noOfColumns = sc.nextInt();
        // Creating Matrix of Required SIZE
        int[][] matrix = new int[noOfRows][noOfColumns];
        // Take Elements of Matrix
        System.out.println(" Enter Elements of Matrix Row Wise ");
        for (int[] row : matrix) {
            for (int i = 0; i < row.length; i++)
                row[i] = sc.nextInt();
        }
        // Displaying the Matrix
        for(int [] row : matrix)
            System.out.println(Arrays.toString(row));
        // Now Calculating the Sum of Minor Diagonal Elements
        int i = 1;
        for(int [] row : matrix){
            int sum = 0;
            for(int element : row){
                sum += element;
            }
            System.out.println(" Sum of " + i + "th Row is: " + sum);
            i++;
        }

        for(int column =0; column < matrix[0].length; column++){
            int row = 0;
            int sum = 0;
            while(row < matrix.length){
                sum += matrix[row][column];
                row++ ;
            }
            System.out.println(" Sum of " + (column + 1) + "th Column is: " + sum);
        }

    }
}