package com.company;

import java.util.Arrays;
import java.util.Scanner;
public class InputOutputInArray {
    // Input and Output an Array Elements
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);

        // Array of Primitives
        // Declaring the Array of Integers
        int [] arr = new int[5];  // Size --> 5     Index --> 0 to 4
        // Taking Inputs from the User
        for(int i=0; i < arr.length; i++){
            arr[i] = sc.nextInt();
        }

        // Displaying the Array Elements:
        for(int element: arr){      // For Every Element in the Array arr
            System.out.print(element + " ");  // Print the Element
        }

        System.out.println();

        // Another Way to Print Array Element
        System.out.println(Arrays.toString(arr));


        // Array of Objects
        String [] arr1 = new String[3];

        // Taking String Inputs from the User
        for(int i=0;i< arr1.length;i++){
            arr1[i] = sc.next();
        }

        // Printing Elements
        System.out.println(Arrays.toString(arr1));
    }
}
