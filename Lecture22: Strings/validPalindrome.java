import java.util.Scanner;
public class validPalindrome {
    static boolean isPalindrome(String str){
        int i = 0, j = str.length() - 1;
        while (i < j) {
            if (str.charAt(i) != str.charAt(j))
                return false;
            i++;
            j--;
        }
        return true;
    }
    public static void main(String[] args){
		Scanner in = new Scanner(System.in);
        String str = in.next();
        if (isPalindrome(str))
            System.out.println("It is Valid Palindrome");
        else
            System.out.println("Not Valid Palindrome");
    }
}
