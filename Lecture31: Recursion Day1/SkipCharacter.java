package Recursion3;
import java.util.Scanner;

public class SkipCharacter {
    // Skip a Character From a Given String
    public static void main(String [] args){
        // Take Any String From the USER
        Scanner sc = new Scanner(System.in);
        System.out.print(" Enter Any String: ");
        String str = sc.next();
        // Display the resultant String
        skip(str, " ");
    }

    static void skip(String str, String ans){
        if(str.isEmpty()){
            System.out.println(ans);
            return;
        }
        char ch = str.charAt(0);
        if(ch == 'a'){
            skip(str.substring(1), ans);
        } else{
            skip(str.substring(1), ans + ch);
        }
    }
}
