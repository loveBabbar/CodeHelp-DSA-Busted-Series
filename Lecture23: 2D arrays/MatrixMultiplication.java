package com.company;

import java.util.Arrays;
import java.util.Scanner;

public class MatrixMultiplication {
    // Subtract Two Matrices
    public static void main(String [] args){
        // Creating Scanner Object for taking Inputs from the USER
        Scanner sc = new Scanner(System.in);
        // Take Number of Rows and Columns of Matrix A
        System.out.print(" Enter Number of ROWS and COLUMNS of First Matrix: ");
        int noOfRows = sc.nextInt();
        int noOfColumns = sc.nextInt();
        // Creating matrix A of Required SIZE
        int [][] matrixA = new int[noOfRows][noOfColumns];
        // Take Number of Rows and Columns of Matrix B
        System.out.print(" Enter Number of ROWS and COLUMNS of Second Matrix: ");
        int noOfRows1 = sc.nextInt();
        int noOfColumns1 = sc.nextInt();
        int [][] matrixB = new int[noOfRows1][noOfColumns1];

        // Matrix Multiplication Condition
        if(noOfColumns != noOfRows1) {
            System.out.println(" Matrix Multiplication is Not Possible !! ");
            return;
        }

        // Take Elements of First Matrix
        System.out.println(" Enter Elements of First Matrix Row Wise ");
        for(int [] row : matrixA){
            for(int i=0; i<row.length; i++)
                row[i] = sc.nextInt();
        }
        System.out.println(" Enter Elements of Second Matrix Row Wise ");
        for(int [] row : matrixB){
            for(int i=0; i<row.length; i++)
                row[i] = sc.nextInt();
        }
        // Calculating Multiplication of Both the MATRICES
        int [][] mul = new int[noOfRows][noOfColumns];
        for(int row = 0; row<matrixA.length; row++){
            for(int column=0; column<matrixB[row].length ; column++){
                for(int k=0;k<matrixB.length;k++)
                {
                    mul[row][column]+=matrixA[row][k]*matrixB[k][column];
                }
            }
        }
        // Display the Resultant Matrix
        for(int [] row : mul){
            System.out.println(Arrays.toString(row));
        }
    }
}
