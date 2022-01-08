import java.util.Scanner;

class pattern10 {
    public static void main(String[] args) {
        int n;

        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        n = sc.nextInt();
        sc.close();

        for (int row = 1; row <= n; row++) {
            // print spaces(1st triangle)
            for (int col = n - row; col >= 1; col--) {
                System.out.print(" ");
            }

            // print 2nd triangle
            for (int col = 1; col <= row; col++) {
                System.out.print(col);
            }

            // print 3rd triangle
            for (int col = row - 1; col >= 1; col--) {
                System.out.print(col);
            }

            System.out.println();
        }
    }
}
