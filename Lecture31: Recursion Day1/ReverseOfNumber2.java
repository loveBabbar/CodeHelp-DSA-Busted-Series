package RecursionQues1;

import java.util.Scanner;

public class ReverseOfNumber2 {
    // Reverse a Given Number N
    public static void main(String [] args){
        // Creating Scanner for Taking Input from the USER
        Scanner sc = new Scanner(System.in);
        // take Any Number from the USER
        System.out.print(" Enter Any Number: ");
        int n = sc.nextInt();
        // Display Reverse of N
        System.out.println(" Reverse of " + n + " is: " + reverse(n));
    }
    static int reverse(int n){
        int digits = (int)(Math.log10(n)) + 1;
        return helper(n, digits);
    }
    static int helper(int n, int digits){
        // if a Number is One Digit Number Return the Number itself
        if(n%10 == n)
            return n;
        int rem = n%10;
        return rem * (int)(Math.pow(10, digits -1)) + helper(n/10, digits - 1);
    }
}