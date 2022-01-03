import java.io.*;
import java.util.Scanner;

class reverseString {
    public static void main (String[] args) {
		String str1="";
        char ch;
        Scanner in = new Scanner(System.in);
        System.out.print("Enter your String: ");
	    String str = in.next();
	    for (int i=0; i<str.length(); i++){
			ch= str.charAt(i);
			str1= ch + str1;
		}
	    System.out.println("Reversed string: "+ str1);
    }
}
