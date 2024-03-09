package BitManipulation;
import java.util.Scanner;

public class EvenOrOdd {
    // Find if a Number is Even or Odd
    public static void main(String [] args){
        // creating Scanner Object for taking input from the USER
        Scanner sc = new Scanner(System.in);
        // taking Any Number as a Inout from the USER
        System.out.print(" Enter Any Number: ");
        int n = sc.nextInt();
        /*
        CODE EXPLANATION :
             10 -->  1010                 9 --> 1001
                   & 0001                     & 0001
                   --------                   --------
                     0000 -> So EVEN            0001 -> So EVEN
         */
        if((n & 1) == 1)
            System.out.println(n + " is ODD ");
        else
            System.out.println(n + " is EVEN ");
    }
}
