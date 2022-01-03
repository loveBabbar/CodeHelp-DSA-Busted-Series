package com.company;

import java.util.Scanner;
import java.util.ArrayList;
public class InputElementsInArrayList {
    public static void main(String [] args){
        // Creating Scanner Object for taking Input From the User
        Scanner sc = new Scanner(System.in);

        // Creating ArrayList Object with reference name list
        ArrayList<Integer> list = new ArrayList< >();

        // Displaying Initial Size of the Array List on the Screen
        System.out.print(" Size of Array List: " + list.size() + "\n");

        // Asking User How Many Elements he/she wants to Add in the ArrayList
        System.out.print(" How Many Elements you want to Add: ");
        // Storing User Input in Variable n
        int n = sc.nextInt();

        // Now taking All Elements from the User as a Input
        System.out.print(" Enter " + n + " Elements to Add: ");
        for(int i=0;i<n; i++){
            list.add(sc.nextInt());  // After Taking Element add it to ArrayList
        }

        // Get Item at Any Index     list.get(index)
        for(int i=0;i<list.size();i++){
            // **** Pass Index Here List[index] Syntax will not work Here *****
            System.out.print(" " + list.get(i));
        }
        System.out.println();

        // Displaying ArrayList
        System.out.println(list);


          // Using Enhanced For Loop :
         for (Integer integer : list) {
            System.out.print(" " + integer);
        }



    }
}
