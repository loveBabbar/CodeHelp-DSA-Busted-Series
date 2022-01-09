package com.company;

import java.util.Scanner;
import java.util.Arrays;
public class LinearSearch {
    // Linear Search
    public static void main(String [] args){
        /*
        Linear Search --> In Linear Search we Visit All the Elements of the Array
        one by one and check is it the Same Element that we are Searching for
        if YES --> Then Print Element Found
        if NO  --> Then Print Element not Found
         */
        // Creating Scanner Object for taking Input From the USER
        Scanner sc = new Scanner(System.in);
        // take the SIZE of the Array from the USER
        System.out.print(" Enter SIZE of the Array: ");
        int n = sc.nextInt();
        // Declare the Array with Required SIZE
        int [] arr = new int[n];
        // Take Elements from the USER and Fill the ARRAY
        System.out.print(" Enter " + n + " Elements: ");
        for(int i=0 ; i<n ; i++){
            int element = sc.nextInt();  // Take Elements
            arr[i] = element;     // Store element in the Array
        }
        // Display the Array
        System.out.println(Arrays.toString(arr));
        // Take Element that USER want to Search in the Array
        System.out.print(" Enter Any Element that you want to Search: ");
        int key = sc.nextInt();
        // Display is the Element Found or NOT
        if(linearSearch(arr, key)){
            System.out.println(" Element " + key + " Found in the Array " + Arrays.toString(arr));
        } else
            System.out.println(" Element " + key + " NOT Found in the Array " + Arrays.toString(arr));
    }

    static boolean linearSearch(int [] arr, int key){
        //  Visit Each Element of the Array
        // if Element Found return true
        // Else Return false
        for(int element: arr){    // Visit Every Element in the Array
            if(element == key)
                return true;     // When Found --> return true
        }
        return false;           // Not Found --> Return false
    }

}
