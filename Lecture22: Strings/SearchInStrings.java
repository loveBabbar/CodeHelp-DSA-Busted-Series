package com.company;

import java.util.Scanner;
public class SearchInStrings {
    // Search character in String
    public static void main(String [] args){
        // Creating Scanner Object for taking Input from the USER
        Scanner sc = new Scanner(System.in);
        // Take Any String as a Input From the USER
        System.out.print(" Enter Any String: ");
        String str = sc.next();
        // Take Any Character that USER wants to Search in the String
        System.out.print(" Enter Any Character that you want to Search: ");
        char ch = sc.next().charAt(0);
        // If Character Found in the String then print --> Character Found
        // Else Print Character Not Found
        if(searchChar(str, ch))
            System.out.println(ch + " Found in the String " + str);
        else
            System.out.println(ch + " NOT Found in the String " + str);
    }

    static boolean searchChar(String str, char key){
        str = str.toLowerCase();
        key = (String.valueOf(key).toLowerCase()).charAt(0);
        // Visit Each Character in the String
//        for(int i=0; i<str.length(); i++){
//            if(str.charAt(i) == key)   // Check if Char at i in String is Equal to the key or not
//                return true;     // If Yes then return true
//        }
        for(char ch : str.toCharArray()){
            if(ch  == key)   // Check if Char at i in String is Equal to the key or not
                return true;     // If Yes then return true
        }
        return false;     // If not found --> return false
    }
}
