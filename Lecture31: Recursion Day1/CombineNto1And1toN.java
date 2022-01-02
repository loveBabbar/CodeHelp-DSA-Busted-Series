package RecursionQues1;

import java.util.Scanner;

public class CombineNto1And1toN {
    // Combine 1 to N As Well N to 1 Recursion
    public static void main(String [] args){
        // Creating Scanner Object for Taking Inputs from the USER
        Scanner sc = new Scanner(System.in);
        // take value of N from the USER
        System.out.print(" Enter Value of N: ");
        int n = sc.nextInt();
        funBoth(n);
    }

    static void funBoth(int n){
        if(n == 0) {
            System.out.println();
            return;
        }
        System.out.print(n + " ");
        funBoth(n -1);
        System.out.print(n + " ");
    }
}
