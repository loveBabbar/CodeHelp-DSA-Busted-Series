package com.company;

public class BinarySearchUsingRecursion {
    // Binary Search Using Recursion
    public static void main(String [] args){
        int [] arr = {1,2,3,4,5,6};
        int target = 5;
        int start = 0, end = arr.length - 1;
        int ansIndex = binarySearch(arr, target, start, end);
        System.out.print(target + " is Found at Index: " + ansIndex);
    }

    static int binarySearch(int [] arr, int target, int start, int end){
        if(start > end)
            return -1;
        // Find mid Index
        int mid = start + (end - start) / 2;
        if(arr[mid] == target)
            return mid;
        else if(arr[mid] > target)
            return binarySearch(arr, target, start, mid - 1);
        return binarySearch(arr, target, mid + 1, end);

    }
}
