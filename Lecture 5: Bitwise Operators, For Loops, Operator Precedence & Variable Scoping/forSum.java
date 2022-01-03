import java.util.Scanner;

class forSum {
    public static void main(String[] args) {

        int n;

        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the value of n: ");
        n = sc.nextInt();
        sc.close();

        int sum = 0;

        for (int i = 1; i <= n; i++) {
            sum += i;
        }

        System.out.println("Total Sum: " + sum);
    }
}
