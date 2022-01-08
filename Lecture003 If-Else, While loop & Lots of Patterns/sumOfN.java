import java.util.Scanner;

class SumOfN {
    public static void main(String[] args) {
        int n;
        int sum = 0;

        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the value of n: ");

        n = sc.nextInt();

        sc.close();

        for (int i = 1; i <= n; i++) {
            sum += i; // shorthand notation of sum = sum + i
        }

        System.out.println("Value of sum is: " + sum);
    }
}
