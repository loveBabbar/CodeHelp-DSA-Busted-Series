package RecursionQues1;

import java.util.Scanner;

public class ReverseOfNumber {
    // Reverse a Given Number N
    static int sum = 0;
    static int reverse(int n){
        if(n == 0)
            return sum;
        int rem = n%10;
        sum = sum*10 + rem;
        return reverse(n/10);
    }

    public static void main(String [] args){
        // Creating Scanner for Taking Input from the USER
        Scanner sc = new Scanner(System.in);
        // take Any Number from the USER
        System.out.print(" Enter Any Number: ");
        int n = sc.nextInt();
        // Display Reverse of N
        System.out.println(" Reverse of " + n + " is: " + reverse(n));
    }
}