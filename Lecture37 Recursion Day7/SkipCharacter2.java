package Recursion3;
import java.util.Scanner;

public class SkipCharacter2 {
    // Skip a Character From a Given String
    public static void main(String [] args){
        // Take Any String From the USER
        Scanner sc = new Scanner(System.in);
        System.out.print(" Enter Any String: ");
        String str = sc.next();
        // Display the resultant String
        System.out.println(skip(str));
    }

    static String skip(String str){
        if(str.isEmpty()){
            return " ";
        }
        char ch = str.charAt(0);
        if(ch == 'a'){
            return skip(str.substring(1));
        } else{
            return ch + skip(str.substring(1));
        }
    }
}
