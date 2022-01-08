import java.util.Scanner;

class pattern6 {
    public static void main(String[] args) {
        int n;

        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        n = sc.nextInt();
        sc.close();

        for (int row = 1; row <= n; row++) {
            for (int col = 1; col <= n; col++) {
                char ch = (char) ('A' + (row - 1));
                System.out.print(ch + " ");
            }

            System.out.println();
        }
    }
}
