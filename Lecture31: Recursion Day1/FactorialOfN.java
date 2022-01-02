package RecursionQues1;
import java.util.Scanner;
public class FactorialOfN {
    // Find Factorial of a Number Using Recursion
    public static void main(String [] args){
        // Creating Scanner for Taking Input from the USER
        Scanner sc = new Scanner(System.in);
        // take Any Number from the USER
        System.out.print(" Enter Any Number: ");
        int n = sc.nextInt();
        // Display Factorial of N
        System.out.println(" Factorial of " + n + " is: " + factorial(n));
    }

    static int factorial(int n){
        if(n == 0)
            return 1;
        return n*factorial(n - 1);
    }
}
