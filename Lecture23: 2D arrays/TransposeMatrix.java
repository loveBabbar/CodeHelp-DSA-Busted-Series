package com.company;

import java.util.Arrays;

public class TransposeMatrix {
    // Transpose Matrix
    public static void main(String[] args) {
        /*
        https://leetcode.com/problems/transpose-matrix/
        Given a 2D integer array matrix, return the transpose of matrix.

        The transpose of a matrix is the matrix flipped over its main diagonal,
         switching the matrix's row and column indices.
         */
        // Declaring and initializing 2D ARRAY
        int[][] matrix = {{1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}};

        System.out.println(" Original Matrix is: ");
        for (int[] rows : matrix) {
            System.out.println(Arrays.toString(rows));
        }

        System.out.println(" Transpose Matrix is: ");
        for (int[] row : transpose(matrix)) {
            System.out.println(Arrays.toString(row));
        }

    }

    public static int[][] transpose(int[][] matrix) {
        // Declaring New Array
        int[][] transposeMatrix = new int[matrix[0].length][matrix.length];
        // This is Because Transpose Matrix will be of SIZE Columns * Rows

        for (int row = 0; row < matrix.length; row++) {    // Loop for ROWS
            for (int column = 0; column < matrix[row].length; column++) {     // Loop for COLUMNS
                transposeMatrix[column][row] = matrix[row][column];
            }
        }
        return transposeMatrix;
    }
}

