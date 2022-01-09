package com.company;

import java.util.Scanner;

public class TemperatureConversion {
    public static void main(String[] args) {

        // Creating Scanner Object to take Input From User
        Scanner sc = new Scanner(System.in);

        // Taking Temperature as a Input From User
        System.out.print(" Enter Temperature in Degree Celsius: ");
        float tempC = sc.nextFloat();

        // Converting Celsius input of Temperature in Degree Fahrenheit
        float tempF = (tempC * 9 / 5) + 32;

        // Printing Temperature in Degree Fahrenheit
        System.out.println(" Temperature in Degree Fahrenheit is : " + tempF + "°F");

        System.out.print(" Do You Want to see the Calculation Steps ? (Y or N) : ");
        String choice = sc.next();

       // Show Calculations if User Input Y or "y" otherwise Exit
        switch (choice) {
            case "y":
            case "Y":
                System.out.println(" Calculation Steps are Like this : ");
                System.out.println(" Temperature Input is ( In Degree Celsius ): " + tempC + "°C");
                System.out.println(" Formula Used For Converting Degree Celsius to Degree Fahrenheit is : ");
                System.out.println(" Y°F = ( X°C + 9/5 ) + 32");
                System.out.println("(" + tempC + " * " + "9/5" + ") " + " + " + 32);
                System.out.println("(" + (tempC * 9 / 5) + ") " + "+ " + 32);
                System.out.println(tempF + "°F");

            case "n":
            case "N":
                break;
            default:
                System.out.println(" Wrong Input! ");
                break;
        }
    }
}
