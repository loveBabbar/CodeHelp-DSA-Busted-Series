

import java.util.Scanner;
import java.util.Arrays;

public class InsertionSort {
    // Insertion Sort
    public static void main(String[] args) {
        // Creating Scanner object for taking Inputs from the USER
        Scanner sc = new Scanner(System.in);
        // Take SIZE of 1D Array from the USER
        System.out.print(" Enter SIZE of 1D Array: ");
        int n = sc.nextInt();
        // Creating Array of Required SIZE
        int[] arr = new int[n];
        // Fill the Array by taking Inputs from the USER
        System.out.print(" Enter " + n + " Elements: ");
        for (int i = 0; i < arr.length; i++)
            arr[i] = sc.nextInt();
        // Display the Array Before Sorting
        System.out.println(" Array Before Sorting is: " + Arrays.toString(arr));
        // Applying Insertion Sort
        insertionSort(arr);
        // Display Array After Sorting
        System.out.println(" Array After Sorting is: " + Arrays.toString(arr));
    }

    // Method of Insertion Sort
    static void insertionSort(int[] arr) {
        // Outer Loop for Number of Passes
        for (int i = 0; i < arr.length - 1; i++) {
            // Inner Loop for Comparison
            for (int j = i + 1; j > 0; j--) {
                // Compare the Elements (i.e Element at Current Index and it's Previous Index)
                // if Previous Element is Greater than Current Element then Swap
                // otherwise Break the loop Because in that Case SubArray will Already Sorted
                if (arr[j] < arr[j - 1])
                    // Swap the Elements
                    swap(arr, j, j - 1);
                else
                    break;
            }
        }
    }

    // Method to Swap Two Elements of Array
    static void swap(int[] arr, int a, int b) {
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
}
