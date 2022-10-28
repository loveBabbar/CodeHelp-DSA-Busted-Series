

import java.util.Scanner;
import java.util.Arrays;
public class BinarySearch {
    // Binary Search
    public static void main(String [] args){
        /*
        Binary Search :
        https://leetcode.com/problems/binary-search/
         */
        // Creating Scanner Object for taking Inputs from the USER
        Scanner sc = new Scanner(System.in);
        // Take the SIZE of the Array from the USER
        System.out.print(" Enter SIZE of the Array: ");
        int n = sc.nextInt();
        // Create Array of Required SIZE
        int [] arr = new int[n];
        // fill the Array By Taking n inputs from the USER
        System.out.print(" Enter " + n + " Elements: ");
        for(int i=0; i<n; i++)
            arr[i] = sc.nextInt();
        // Display the Array
        System.out.println(Arrays.toString(arr));
        // take the Target Element from the USER
        System.out.print(" Enter target Element to Find: ");
        int target = sc.nextInt();
        // Display if the Element Found or not
        System.out.println(target + " Found at Index: " + search(arr, target));
    }
    static int search(int[] nums, int target) {
        /*
        Binary Search Explanation:
        NOTE :   Binary Search can be Only Applied on Sorted Arrays
        let Array is -->  [1,2,3,4]      key = 4
        here,
                indices -->   0   1   2   3
                [ 1,  2,  3,  4 ]
                              /            \
        start          end
        mid = start + (end - start)/2  -->  0 + (3-0)/2   --> 3/2  --> 1
        Step1 :   arr[mid]  = arr[1] --> 2    Not Equal to 4 (key)
                Step2 :   arr[mid] > key   -->  2 > 4    FALSE
        Step3 :   arr[mid] < key   -->  2 < 4    TRUE   --> Search in Right Sub Array
        start --> mid + 1
                [ 1,  2,  3,  4 ]
        indices -->     0   1   2   3
                /   \
        start end
        Now , mid = 2 + (3-2)/2   --> 2 + 1/2  -->  2 + 0 --> 2
        step1 :  arr[mid] = arr[2] --> 3  Not Equal to 4 (key)
                step2 :  arr[mid] > key    --> 3 > 4   FALSE
        step3 :  arr[mid] < key    --> 3 < 4    TRUE  --> Search in Right SUb Array
        now,   start --> mid + 1
                [ 1,  2,  3,  4 ]
        indices -->     0   1   2   3
                /\
        start end
        Hence , mid = 3 + (3-3)/2  --> 3 + 0   --> 3
        step1:  arr[mid] = arr[3] -->  4   YES Equals to 4 (key)   --> return true
         */

        int start = 0;
        int end   = nums.length-1;
        while(start <= end){
            // find mid
            int mid = start + (end - start)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid]> target)
                end = mid-1;
            else
                start = mid +1;
        }
        return -1;
    }
}
