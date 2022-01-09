package com.company;

import java.util.Scanner;
import java.util.Arrays;

public class IdentityMatrix {
    // Display Identity Matrix
    public static void main(String [] args){
        // Creating Scanner Object for taking Inputs from the USER
        Scanner sc = new Scanner(System.in);
        // Take SIZE of Identity Matrix
        System.out.print(" Enter SIZE(no of ROWS and COLUMNS) of Identity Matrix: ");
        int noOfRow = sc.nextInt();
        int noOfColumn = sc.nextInt();
        // Create Identity Matrix of Required SIZE
        int [][] identityMatrix = new int[noOfRow][noOfColumn];
        int i=0;
        for(int [] row : identityMatrix){
                row[i] = 1;
                i++;
        }

        // Display the Identity Matrix
        for(int [] row : identityMatrix){
            System.out.println(Arrays.toString(row));
        }
    }
}
