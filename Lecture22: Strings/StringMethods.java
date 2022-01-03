package com.company;

import java.util.Arrays;

public class StringMethods {
    // String Methods
    public static void main(String [] args){
        String name = "Deepak Kumar";
        System.out.println(Arrays.toString(name.toCharArray()));

        System.out.println(name.toUpperCase()); // Here Original String will not Change Because Strings are immutable
        System.out.println(name);

        System.out.println(name.indexOf('a'));
        System.out.println(name.lastIndexOf('a'));

        System.out.println("     Deepak    ".strip());
    }
}
