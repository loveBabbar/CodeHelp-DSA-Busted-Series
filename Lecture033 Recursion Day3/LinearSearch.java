package com.company;

public class LinearSearch {
    public static void main(String[] args) {

        int[] arr = {3, 5 ,1 ,2 , 6};
        int  ans = search(arr , 7 , 5);
        if(ans == -1)
            System.out.println("Not Found");
        else
            System.out.println("Element present at index " + ans);
    }

    public static int search(int[] arr , int key , int size){
        return helper(arr , key , 0 , size);
    }

    public static int helper(int[] arr , int key , int idx , int size){
        //base cases
        if(idx == size) // if reached here key is not present in array return -1;
            return -1;

        if(arr[idx] == key) // key found return index;
            return idx;

        // recurrence relation
        return helper(arr , key , idx + 1 , size); // element not present at current index do idx++;
    }
}
