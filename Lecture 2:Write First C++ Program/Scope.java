package com.company;

public class Scope {
    public static void main(String [] args){
        /*
        Scope Basically Means where we can Access variable in the Program
        REMEMBER :
               Anything Declared INSIDE can't Access OUTSIDE
               Anything Declared OUTSIDE can be Accessed INSIDE
         */

        int mark = 3000;
        student(mark);

        {
            int numbers = 900;
            mark = 800;  // --> Declared Already outside the Block so we can't declare again but we can initialize again and use it
                        // Inside the Block Original Reference Variable will be change
            // Block Scope
            // values initialized inside the Block will remain in the Block
            System.out.println(" Numbers in Block Scope: " + numbers);
            System.out.println(" Marks in Block Scope: " + mark);
        }

        System.out.println(" Marks outside the Block: " + mark);
       //  number = 90; --> ERROR!    Cannot Use outside the Block


        // Loop Scope
        for(int i=0;i<3;i++){
            System.out.println(i);
        }

       //  System.out.println(i);  // ERROR --> Can't Access Outside the LOOP

        int i = 90; // POSSIBLE
    }

    public static void student(int marks){

        // Function Scope
        int number = 89;
        System.out.println(" Numbers in Function Scope are: " + number);
        System.out.println(" Marks in Function Scope are: " + marks);
    }
}
