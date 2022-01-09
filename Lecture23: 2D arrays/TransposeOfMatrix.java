package com.company;

import java.util.Arrays;
import java.util.Scanner;

public class TransposeOfMatrix {
    // Transpose of a Matrix
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

            int [][] transpose = new int[noOfColumns][noOfRows];
            for(int row = 0; row < matrix.length; row++){
                for(int column = 0; column< matrix[row].length ; column ++){
                    transpose[column][row]  = matrix[row][column];
                }
            }

            System.out.println(" Transpose of Matrix is ");
            for(int [] row : transpose){
                System.out.println(Arrays.toString(row));
            }
    }
}
