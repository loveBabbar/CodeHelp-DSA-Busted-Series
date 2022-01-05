package Lec32;
import java.util.*;

public class sayDigits {

    public static void sayDigitsFun(int n, String arr[]){
        if(n==0)
            return ;

        int digit = n%10;
        n /= 10;

        // System.out.println(arr[digit]);  prints in reverse order
        sayDigitsFun(n,arr);
        System.out.println(arr[digit]);  // prints from starting
    }
    public static void main(String[] args) {
       Scanner sc = new Scanner((System.in));
       int n = sc.nextInt();
       String[] arr = new String[]{"zero", "one", "two", "three",
                                    "four", "five", "six", "seven",
                                    "eight", "nine"};
       sayDigitsFun(n,arr);
    }
}
