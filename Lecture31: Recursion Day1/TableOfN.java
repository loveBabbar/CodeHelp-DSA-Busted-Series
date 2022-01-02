package RecursionQues1;

import java.util.Scanner;

public class TableOfN {
    // Print Multiplication table of N Using Recursion
    public static void main(String [] args){
        // Creating Scanner Object for Taking Inputs from the USER
        Scanner sc = new Scanner(System.in);
        // take value of N from the USER
        System.out.print(" Enter Value of N: ");
        int n = sc.nextInt();
        table(n, 0);
    }
    static void table(int n, int i){
        System.out.format("%d * %d = %d \n", n, i, n*i);
        if(i == 10)
            return;
        table(n, i+1);
    }
}
