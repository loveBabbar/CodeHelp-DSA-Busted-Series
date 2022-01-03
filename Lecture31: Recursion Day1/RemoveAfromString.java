package Recursion3;
import java.util.Scanner;

public class RemoveAfromString {
    // Remove a from the GivenString Using Recursion
    public static void main(String [] args){
        // Take Any String from the USER
        Scanner sc = new Scanner(System.in);
        System.out.print(" Enter Any String: ");
        String str = sc.next();
        // Display the Resultant String After Removing a from it
        System.out.println(removeA(str, " ", 0));
    }
    static String removeA(String str, String ans, int index){
        if(index == str.length() || str.equals(""))
            return ans;
        if(str.charAt(index)!= 'a')
            ans += str.charAt(index);
        index++;
        return removeA(str, ans, index);
    }
}
