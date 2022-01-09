package com.company;

public class Conditionals {
    public static void main(String [] args){
        /*

        Conditionals : Conditionals changes the flow of control of Program
            Syntax of if Statement
            if(condition){
                 // do this
            } else{
               // do this
            }
        */
//
        int salary = 25400;
//        if(salary > 10000) {
//            salary += 2000;
//        } else{
//            salary += 1000;
//        }
//        System.out.println(" New Salary: "+salary);

        // Multiple if-else statement or if else ladder
        if(salary > 10000){
            salary += 3000;
        } else if(salary > 2000){
            salary += 2000;
        } else{
            salary += 1000;
        }
        System.out.println(" Salary : " + salary );


    }
}
