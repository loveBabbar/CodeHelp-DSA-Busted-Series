package MathsForDSA;
import java.util.Scanner;

public class SquareRootOfANumber {
    // Find Square Root of a Number Using Binary Search
    public static void main(String [] args){
        // Creating Scanner Object for taking Input from the USER
        Scanner sc = new Scanner(System.in);
        // Take Any Number as a Input from the USER
        System.out.print(" Enter Any Number: ");
        int num = sc.nextInt();
        // Display the Square Root of Number
        System.out.println(" Square Root of " + num + " is: " + sqrt(num));
    }

    static int sqrt(int num){
        // Apply Simple Binary Search to Find the Square Root
        int start = 0;
        int end = num;
        while(start <= end){
            // Find Mid
            int mid = start + (end - start)/2;
            if(mid * mid == num)
                return mid;
            else if(mid * mid > num)
                end = mid - 1;
            else
                start = mid + 1;
        }
        // Otherwise return Floor Value of the Square Root
        return end;
    }
}
