import java.util.Scanner;

class pattern7 {
    public static void main(String[] args) {
        int n;

        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        n = sc.nextInt();
        sc.close();

        // code written in for loop can also be done using while
        // using while loop here to demonstrate the same

        int row = 1;

        while (row <= n) {

            int col = 1;

            while (col <= row) {
                char ch = (char) ('A' + row + col - 2);
                System.out.print(ch + " ");
                col = col + 1;
            }

            System.out.println();
            row = row + 1;

        }
    }
}
