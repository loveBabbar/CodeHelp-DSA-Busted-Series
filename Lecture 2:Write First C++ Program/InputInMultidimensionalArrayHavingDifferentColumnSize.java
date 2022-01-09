package com.company;

import java.util.Scanner;
import java.util.Arrays;
public class InputInMultidimensionalArrayHavingDifferentColumnSize {
    public static void main(String [] args){

        Scanner sc = new Scanner(System.in);

        // Taking number of Rows as a Input From the User
        System.out.print(" Enter Number of Rows for the Array: ");
        int rowSize = sc.nextInt();

        // Creating Array with number of rows Given by the User
        int [][] arr = new int [rowSize][7];

        for(int rows = 0; rows < arr.length ;rows++){
            // Taking the Length of the Column From the User
            System.out.print(" Enter length of the Column for the " + (rows+1) + " Row: ");
            int columnSize = sc.nextInt();
            for(int columns = 0; columns < columnSize; columns++){
                System.out.print(" Enter Value for arr["+ rows +"] ["+ columns + "] : ");
                arr[rows][columns] = sc.nextInt();
//                System.out.println(arr[rows][columns]);
            }
        }

        // Displaying the Array on the Screen
        System.out.println(" Array Elements are: ");
        for(int [] a : arr){
            System.out.println(Arrays.toString(a));
        }
    }
}
