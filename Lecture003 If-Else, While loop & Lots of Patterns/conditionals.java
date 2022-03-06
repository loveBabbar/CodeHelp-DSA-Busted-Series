import java.util.Scanner;

class conditionals {
    public static void main(String[] args) {
        int a;

        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the value of a: ");

        a = sc.nextInt();

        sc.close();

        if (a > 0) {
            System.out.println("A is positive.");
        } else if (a < 0) {
            System.out.println("A is negative.");
        } else {
            System.out.println("A is zero.");
        }
    }
}
