import java.util.Scanner;

class whileLoop {
    public static void main(String[] args) {
        int n;
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter a number: ");
        n = sc.nextInt();
        sc.close();

        int i = 1;
        while (i <= n) {
            System.out.print(i + " ");
            i++; // shorthand for i = i + 1
        }
    }
}
