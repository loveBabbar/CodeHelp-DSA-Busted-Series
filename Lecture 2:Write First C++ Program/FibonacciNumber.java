package com.company;

import java.util.Scanner;
public class FibonacciNumber {
    public static void main(String [] args) {
        // Creating Scanner Object for Taking input from the user
        Scanner np = new Scanner(System.in);

        System.out.print(" Enter nth Number to Generate the Fibonacci Number: ");
        int num = np.nextInt();

        int term1 = 0;
        int term2 = 1;
        if (num >= 0) {
            if (num == 0)
                return;
            if (num == 1)
                System.out.print(" " + term1);
            else if (num == 2)
                System.out.print(" " + term1 + " " + term2);
            else
                System.out.print(" " + term1 + " " + term2);
            for (int i = 3; i <= num; i++) {
                int term3 = term1 + term2;
                System.out.print(" " + term3);
                term1 = term2;
                term2 = term3;
            }
        } else
            System.out.println(" Wrong Input !!! ");
    }
}
