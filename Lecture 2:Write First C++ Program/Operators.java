package com.company;

import java.util.ArrayList;

public class Operators {
    // Operators
    public static void main(String [] args){
        System.out.println('a' + 'b');
        // Here Firstly 'a' and 'b' Are Converted into ASCII Values then Add them
        System.out.println('a' * 2);
        System.out.println("a" + "b");

        System.out.println("A" + 1);
        // This Will Same as After a few Steps "A" + "1"
        // After this these two Strings will be Concatenated and give A1 as a Output
        // int value will Converted into Integer (Wrapper Class) and then it will call toString Method

        System.out.println(" Deepak " + new int[]{1,2,3});
        System.out.println(" Deepak " + new ArrayList<>());

        // System.out.println(1 + new ArrayList<>());  // ERROR --> Operator + can't be Applied on integer and Array List
        System.out.println(1 + " " +  new ArrayList<>());
    }
}
