package com.company;

import java.util.Scanner;
public class SumUsingVarArgs {
    // Printing Sum of Numbers using Var Args
    public static void main(String [] args){

        Scanner sc = new Scanner(System.in);

        System.out.print(" Enter How Many Numbers You want to Sum: ");
        int n = sc.nextInt();

        int [] arr = new int[n];
        for(int i=0;i<n;i++){
            System.out.print(" Enter " + (i+1) + " Number: ");
            arr[i] = sc.nextInt();
        }

        sum(arr);
    }

    static void sum(int ...v) {
        int sum = 0;
        for(int i = 0 ;i<v.length;i++){
            sum += v[i];
        }
        // Displaying Sum on the Screen
        System.out.println(" Sum: " + sum);
    }
}
