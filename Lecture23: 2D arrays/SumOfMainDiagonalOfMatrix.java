package com.company;

import java.util.Scanner;
import java.util.Arrays;

public class SumOfMainDiagonalOfMatrix {
    // Sum of main Diagonal Elements of a Matrix
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
        // Now Calculating the Sum of Main Diagonal Elements
        int sum = 0;
        for(int i=0; i < matrix.length; i++){
            sum += matrix[i][i];
        }
        // Displaying the Sum of main Diagonal of Matrix
        System.out.println(" Sum of Main Diagonals of the Matrix is: " + sum);

    }
}
