import java.util.Scanner;

public class Power {
	
	public static int power(int n) {
		if(n==0) {
			return 1;
		}
		return (2*power(n-1));
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int power = Power.power(n);
		System.out.println("2 raise to the power "+n+" is : "+power);
	}
}
