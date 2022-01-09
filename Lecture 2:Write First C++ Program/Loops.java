package com.company;


import java.util.Scanner;
public class Loops {
    public static void main(String[] args) {
        /*
        Loops are used for Repeating the task again and again
            // For Loop
            for(initialization ,testing/Condition, Incrementation/Decrementation ){
                // Statements
            }
         */

        // Print the First Ten Natural Numbers
        for (int number = 1; number <= 10; number++) {
            System.out.print(" " + number);
        }

        /*
        While Loop in Java
        // Syntax of While Loop
        while(condition){
        // Statement
        incrementation/ Decrementation
        }
         */
//        int number = 1;
//        while(number <=10){
//            System.out.print(" "+ number);
//            number++;
//        }

        /*
         Do while Loop in java
         Syntax
         do{
         // Statement
         Incrementation/ Decrementation
         }while(condition);
         */
        System.out.println();
        int number = 1;
        do{
            System.out.print(" "+ number);
            number++;
        }while(number<=10);

        // Print Odd numbers from 1 to 10
        System.out.println();
        for(int i = 1;i<=10; i+=2){
            System.out.println("Odd Numbers: "+ i);
        }

        // Print Numbers from 1 to n
        // Creating Scanner Object for taking input from the user
        Scanner in = new Scanner(System.in) ;

        System.out.print(" Enter nth Number for Sequence: ");
        int n = in.nextInt();
        for (number = 1;number<=n;number++){
            System.out.print(" "+ number);
        }

        for(int i=1, j =1; i<=10 || j<=20;i++,j++){
            System.out.println(" i: "+ i + " j: "+j );
        }
    }
}
