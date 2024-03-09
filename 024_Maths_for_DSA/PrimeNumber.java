package MathsForDSA;
import java.util.Scanner;

public class PrimeNumber {
    // Check Whether a Given Number is Prime or Not
    public static void main(String [] args){
        // Creating Scanner Object for taking inputs from the USER
        Scanner sc = new Scanner(System.in);
        // Take any Number as a Input from the USER
        System.out.print(" Enter Any Number: ");
        int num = sc.nextInt();
        // Display is the Number Entered by USER is Prime or NOT
        System.out.println(num + " is: " + isPrime(num));
    }

    static String isPrime(int num){
        if(num == 0)
            return " Neither Prime Nor Composite ";
        if( num < 0 )
            return " Not Prime ";
        for(int i=2; i*i < num; i++){
            if(num % i == 0)
                return " Not Prime ";
        }
        return " Prime ";
    }
}
