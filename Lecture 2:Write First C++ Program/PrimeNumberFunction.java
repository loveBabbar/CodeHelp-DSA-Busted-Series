package com.company;

import java.util.Scanner;
public class PrimeNumberFunction {
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);

        // Taking Any Number as a Input From the User
        System.out.print(" Enter any Number: ");
        int number = sc.nextInt();


        if(isPrime(number)) {
            System.out.println(number + " is Prime ");
        } else{
            System.out.println(number + " is not Prime ");
        }
    }

    public static boolean isPrime(int number){
        if(number <= 1)
            return false;

        for(int i=2;i*i<number;i++){
            if(number % i == 0)
                return false;
        }
        return true;
    }
}
