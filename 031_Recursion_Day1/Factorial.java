import java.util.Scanner;

public class Factorial {
	
	public static int factorial(int n) {
		if(n==0) {
			return 1;
		}
		return (n * factorial(n-1));
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int fact = Factorial.factorial(n);
	    System.out.println("Factorial of "+n+" is : "+fact);
	}
}
