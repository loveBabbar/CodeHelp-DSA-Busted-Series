import java.util.Scanner;

class binToDec {
    public static void main(String[] args) {
        int n;
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the value of n: ");
        n = sc.nextInt();
        sc.close();

        int ans = 0;
        for (int i = 0; n != 0; i++) {

            int digit = n % 10;

            if (digit == 1) {
                ans += Math.pow(2, i);
            }

            n /= 10; // shorthand of n = n/10

        }

        System.out.println("Answer: " + ans);
    }
}