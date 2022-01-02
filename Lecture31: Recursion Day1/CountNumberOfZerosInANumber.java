package RecursionQues1;
import java.util.Scanner;

public class CountNumberOfZerosInANumber {
    // Check Number of Zeros in a Given Number
    public static void main(String [] args){
        // Creating Scanner for Taking Input from the USER
        Scanner sc = new Scanner(System.in);
        // take Any Number from the USER
        System.out.print(" Enter Any Number: ");
        int n = sc.nextInt();
        // Display the Count of Number of Zeros in n
        System.out.println(" Number of Zeros in " + n + " is: " + zeros(n, 0));
    }

    static int zeros(int n, int count){
        if(n%10 == 0)
            count++;
        if((n+"").length() == 1 && n == 0)
            return count-1;
        return zeros(n/10, count);
    }
}
