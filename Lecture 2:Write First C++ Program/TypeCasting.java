package com.company;

public class TypeCasting {
    public static void main(String[] args) {

        int num = (int) (3399.9f);      // Explicit Type Conversion  By Default Floats are Double(dataType)
        System.out.println(" Number: " + num);

        // Automatic Type promotions in Expressions
        int a= 257;
        byte b = (byte)(a);  // 256 % 257 = 1      Max range of Byte is 256
        System.out.println(" " + b);

        byte a1 = 40;
        byte b1= 50;
        byte c1 = 100;
        int d = a1*b1/c1;
        System.out.println(d);

        byte b3 = 50;
        // b3 = b3 * 2;   // Byte Evaluations are Converted into Int So Its and EROOR!
        b3 = (byte)(b3*2);
        System.out.println(b3);

        int number = 'a';
        System.out.println(number);   // ASCII value of 'a' is 97

        System.out.println("नमस्ते");   // UNICODE Values
        // Unicode is a universal international standard character encoding
        // that is capable of representing most of the world's written languages.
    }
}
