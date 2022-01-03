package com.company;

import java.util.Scanner;

public class Power {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // Scanner to read values from user

        int n = sc.nextInt(); // take input from user

        int ans = pow(n); // calling pow function to compute our 2 ^ n

        System.out.println(ans); // print the ans
    }

    public static int pow(int n){
        //base case 2 ^ 0 = 1 (we know)
        if(n == 0)
            return 1;

            int smallerProblem = pow(n - 1);
            int biggerProblem = 2 * smallerProblem;

            //can be simplified as
            // return 2 * pow(n - 1) gives same result

            return biggerProblem;
    }
}
