import java.util.Scanner;

class pattern9 {
    public static void main(String[] args) {
        int n;

        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        n = sc.nextInt();
        sc.close();

        for (int row = 1; row <= n; row++) {

            // print space
            for (int col = n - row; col >= 1; col--) {
                System.out.print(" ");
            }

            // print stars
            for (int col = 1; col <= row; col++) {
                System.out.print("*");
            }

            System.out.println();
        }
    }
}
