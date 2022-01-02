package RecursionQues1;

import java.util.Scanner;

public class SumOfNnumbers {
    // Display Sum of N Numbers
    public static void main(String [] args){
    // Creating Scanner for Taking Input from the USER
    Scanner sc = new Scanner(System.in);
    // take Any Number from the USER
    System.out.print(" Enter Any Number: ");
    int n = sc.nextInt();
    // Display Factorial of N
    System.out.println(" Sum of " + n + " Numbers is: " + sum(n));
}

    static int sum(int n){
        if(n == 0)
            return n;
        return n + sum(n - 1);
    }
}
