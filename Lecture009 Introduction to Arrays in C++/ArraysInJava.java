package com.company;

import java.util.Scanner;
public class ArraysInJava {
    // Arrays in Java
    public static void main(String [] args){
        /*
        Arrays in Java
        Syntax:
               dataType [] array_Name = new dataType[Size];
               dataType [] array_Name = {E1, E2, E3};

      ***  Declaration of an Array  ***
             int [] arr; --> Array of name arr is Declared . arr is getting Defined in the Stack
                         --> Currently its not Pointing to Any Object
             arr = new int[5]; --> Initialisation: Actually Here Object is Being Created in the Memory ( Heap Memory )

             new --> is a Keyword and Used to Create an Object
                 For Each Loop in JAVA
                int [] Numbers = {1,2,3,4};
                for(int i: Numbers){
                    System.out.println(i);
        }
        */

        /*
        When to Use Arrays
          Store Roll Number of a Student
             int roll_Number = 10;

           Store Name of the Student
           String name = " Deepak Kumar ";

           Store Roll Number of 6 Students
           --> Here it's Difficult to make 6 Different Variables to Store 6 Roll numbers
           --> So we user Array to Store them as a Single Entity
           --> Array Elements are of Same Data Type
           --> Stored in Continuous Memory Locations (in C/C++)
           --> JAVA has no Concept of POINTERS so we can't Access ARRAY using POINTER Arithmetic (i.e Addresses)
           --> But in Java may not be Continuous ( depends on JAVA Architecture )
           --> Arrays objects in JAVA are Stored in HEAP Memory
           --> And we Know that HEAP objects are not Continuous
           --> Dynamic Memory Allocation
           --> Hence ,
               int [] roll_Number = {1,2,3,4,5,6};
         */

        // Que: Ask User to Input his/her marks in 5 Different Subject and Calculate the Percentage
        Scanner sc = new Scanner(System.in);

        // Taking Number of Subjects User Have as a Input From the User
        System.out.print(" How Many Subjects You Have?: ");
        int n = sc.nextInt();

        // Creating Array of Size as that of Number Of Subjects User Have
        int [] marks = new int[n];
        // Taking Input From the User and Storing that into Array
        for(int i=0;i<n;i++){
            System.out.print(" Enter Marks in " + (i+1) + " Subject: ");
            marks[i] = sc.nextInt();
        }

        // Summing All the Marks in Different Subjects
        int sum = 0;
        for(int i:marks){
            sum += i;
        }
        // Here  we have the Sum of Marks in Different Subjects
        // Now Calculating Average of the Marks
        // Average Marks = Sum/n;
        float average = (float)sum/n;

        // Displaying Average Marks on the Screen
        System.out.println(" Average is: " + average);

        // Calculating Percentage Also
        float percentage = (float)sum/(100*n) * 100;

        System.out.println(" You Obtain: " + sum + "/" + (100*n));
        // Displaying Percentage on the Screen
        System.out.println(" Your Percentage is: " + percentage + "%");
    }
}
