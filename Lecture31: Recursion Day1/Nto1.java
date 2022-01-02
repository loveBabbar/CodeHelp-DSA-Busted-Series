package RecursionQues1;
import java.util.Scanner;

public class Nto1 {
    // Print Numbers from N to 1 Using Recursion
    public static void main(String [] args){
        // Creating Scanner Object for Taking Inputs from the USER
        Scanner sc = new Scanner(System.in);
        // take value of N from the USER
        System.out.print(" Enter Value of N: ");
        int n = sc.nextInt();
        fun(n);
    }

    static void fun(int n){
        System.out.print(n + " ");
        if(n == 1)
            return;
        fun(n -1);
    }
}
