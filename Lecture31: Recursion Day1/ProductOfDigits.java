package RecursionQues1;

import java.util.Scanner;

public class ProductOfDigits {
    // Print Product of Individual Digits of N
    public static void main(String [] args){
        // Creating Scanner for Taking Input from the USER
        Scanner sc = new Scanner(System.in);
        // take Any Number from the USER
        System.out.print(" Enter Any Number: ");
        int n = sc.nextInt();
        // Display Factorial of N
        System.out.println(" Sum of Digits of " + n + " is: " + product(n));
    }
    // Time Complexity O(logN)
    static int product(int n){
        if(n == 0)
            return 1;
        return n % 10 * product(n/10);
    }
}