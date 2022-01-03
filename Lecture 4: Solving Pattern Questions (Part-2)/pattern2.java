import java.util.Scanner;

class pattern2 {
    public static void main(String[] args) {

        int n;
        int count = 1;

        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");

        n = sc.nextInt();
        sc.close();

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                System.out.print(count + " ");
                count++; // shorthand for count = count + 1
            }

            System.out.println();
        }
    }
}
