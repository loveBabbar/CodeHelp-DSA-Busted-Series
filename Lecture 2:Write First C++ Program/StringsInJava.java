package com.company;

public class StringsInJava {
    // Strings in java
    public static void main(String [] args){
        int a = 10;
        // String is Class in JAVA starts with Capital letter
        String name = " Deepak ";
      //         /          \
      // Reference variable  object (in Heap)
        System.out.println(name);

        String A = " Deepak ";
        String B = " Deepak ";
        // == is Comparator and .equals() is a Method
        // == --> It Checks for both the Reference Variables are pointing to the Same Object or not
        System.out.println(A == B);
        // .equals() only Compares the Values not the References
        System.out.println(A.equals(B));

        String s1 = new String(" Deepak ");
        String s2 = new String(" Deepak ");
        // In this Case Two New Strings s1 and s2 are Created Outside the Pool (i.e String Pool)
        // In this two New Objects are Created and s1 and s2 Pointing to different Objects not the Same
        // == --> It Checks for both the Reference Variables are pointing to the Same Object or not
        System.out.println(s1 == s2);
        // .equals() only Compares the Values not the References
        System.out.println(s1.equals(s2));

        String studentName = "Deepak";
        System.out.println(studentName);
        studentName = "Kumar";
        System.out.println(studentName);

        String a1 = "Deepak";
        String a2 = a1;
        System.out.println(a1 +" " +  a2);
    }
}
