package com.company;

import java.util.Scanner;

public class MatrixEquality {
    // Check Whether Two matrices are Equal or Not
    public static void main(String [] args) {
        // Creating Scanner Object for taking Inputs from the USER
        Scanner sc = new Scanner(System.in);
        // Take Number of Rows and Columns of Matrix A
        System.out.print(" Enter Number of ROWS and COLUMNS of Matrices: ");
        int noOfRows = sc.nextInt();
        int noOfColumns = sc.nextInt();
        // Creating tow matrices of Required SIZE
        int[][] matrixA = new int[noOfRows][noOfColumns];
        int[][] matrixB = new int[noOfRows][noOfColumns];
        // Take Elements of First Matrix
        System.out.println(" Enter Elements of First Matrix Row Wise ");
        for (int[] row : matrixA) {
            for (int i = 0; i < row.length; i++)
                row[i] = sc.nextInt();
        }
        System.out.println(" Enter Elements of Second Matrix Row Wise ");
        for (int[] row : matrixB) {
            for (int i = 0; i < row.length; i++)
                row[i] = sc.nextInt();
        }

        // Display Matrices are Equal or Not
        System.out.println(" Are Matrices EQUAL ? " + matrixEquality(matrixA, matrixB));
    }

    static String matrixEquality(int [][] matrixA, int [][] matrixB){
        for(int row = 0; row <matrixA.length ; row++){
            for(int column = 0; column< matrixA[row].length; column++){
                if( matrixA[row][column] != matrixB[row][column] )
                    return "NO";
            }
        }
        return "YES";
    }
}
