package com.company;

import java.util.Scanner;
import java.util.Arrays;

public class ScalarMatrixMultiplication {
    // Perform Scalar Matrix Multiplication
    public static void main(String[] args) {
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

        // Take Any Scalar Quantity
        System.out.print(" Enter any Scalar Value: ");
        int k = sc.nextInt();
        int [][] result = new int[noOfRows][noOfColumns];
        for(int row = 0; row < matrix.length; row++){
            for(int column = 0; column< matrix[row].length ; column ++){
                result[row][column] = k * matrix[row][column];
            }
        }

        System.out.println(" Scalar Multiplication of Matrix is ");
        for(int [] row : result){
            System.out.println(Arrays.toString(row));
        }
    }
}
