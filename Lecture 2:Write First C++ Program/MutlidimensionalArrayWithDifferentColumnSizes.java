package com.company;

import java.util.Arrays;
public class MutlidimensionalArrayWithDifferentColumnSizes {
    /*
    { {1,2,3,4}
       {5,6},
       {7,8,9}    }
     */
    public static void main(String [] args){

        int[][] arr = {{1,2,3,4},
                        {5,6},
                        {7,8,9}  };

        System.out.println(" ***** Printing Array Elements Using For Loops ***** ");

        for(int i=0;i<arr.length; i++){          // i --> Counter For Number of ROWS
            for(int j=0;j<arr[i].length;j++){    // j --> Counter For Number of COLUMNS
                // arr[i].length --> It will give us the Length of the Particular ROW
                System.out.print(" " + arr[i][j]);
            }
            System.out.println();
        }

        System.out.println(" ***** Printing Array Elements Using For Each Loop ***** ");
        // Another Way to print this Array
        for(int [] element : arr){
            System.out.println(Arrays.toString(element));
        }
    }
}
