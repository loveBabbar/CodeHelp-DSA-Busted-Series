package RecursionQues1;

import java.util.Scanner;

public class PalindromeOfANumberUsingTwoPointerMethod {
    // Check whether a Given Number is Palindrome or Not Using Two Pointer Method
    public static void main(String [] args){
        // Creating Scanner for Taking Input from the USER
        Scanner sc = new Scanner(System.in);
        // take Any Number from the USER
        System.out.print(" Enter Any Number: ");
        int n = sc.nextInt();

        if(isPalindrome(n))
            System.out.println(n + " is a Palindrome Number");
        else
            System.out.println(n + " is Not a Palindrome Number");
    }

    static boolean isPalindrome(int n){
        String num = n + "";
        int start = 0;
        int end = num.length() - 1;
        while(start <= end){
            if(num.charAt(start) != num.charAt(end))
                return false;
            start ++;
            end --;
        }
        return true;
    }
}
