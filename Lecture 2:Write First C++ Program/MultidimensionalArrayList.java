package com.company;

import java.util.Scanner;
import java.util.ArrayList;
public class MultidimensionalArrayList {
    public static void main(String [] args){
        Scanner sc = new Scanner(System.in);

        ArrayList<ArrayList<Integer>> list = new ArrayList<>();   // --> ArrayList of ArrayList

        // Initialization :
        for(int i=0;i<3; i++){
            list.add(new ArrayList<>());
        }

        // Print List before Adding the Elements
        System.out.println(list);


        // Add Elements
        for(int i=0;i<list.size();i++){
            for(int j=0;j<list.size();j++){
                // Get List at Index i and then Add Elements to it
                list.get(i).add(sc.nextInt());
            }
        }

        // Print List
        System.out.println(list);
    }
}
