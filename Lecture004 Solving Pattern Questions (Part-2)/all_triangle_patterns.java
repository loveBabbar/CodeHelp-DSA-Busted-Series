import java.util.Scanner;

class all_triangle_patterns {
    public static void main(String[] args) {
        int no_of_pattern;

        Scanner sc = new Scanner(System.in);
        System.out.println("Select which pattern you want to print from below list:");
        System.out.println("1. Inverted & Reverse Same Number Triangle Pattern (H.W-1).");
        System.out.println("2. Inverted Same Number Triangle Pattern (H.W-2).");
        System.out.println("3. Inverted Continuous Number Triangle Pattern (H.W-3).");
        System.out.println("4. Inverted & Reverse Number Triangle Pattern (H.W-4).");
        System.out.println();
        System.out.print("Enter your choice: ");

        no_of_pattern = sc.nextInt();
        System.out.println();

        switch (no_of_pattern) {
            case 1:
                pattern1(sc);
                break;

            case 2:
                pattern2(sc);
                break;

            case 3:
                pattern3(sc);
                break;

            case 4:
                pattern4(sc);
                break;

            default:
                System.out.println("Invalid Number, please select a number from above given list :)");
                System.out.println();
        }

        sc.close();
    }

    static void pattern1(Scanner sc) {

        // Inverted Same Number Triangle Pattern
        System.out.println();
        System.out.println("You are going to see a inverted & reverse same number triangle pattern (H.W-1):- ");

        int height, i, j, k, value = 1;

        System.out.println();
        System.out.print("Enter height of the triangle: ");
        height = sc.nextInt();
        System.out.println();

        for (i = 1; i <= height; i++) {
            for (k = 1; k <= i; k++) {
                System.out.print("  ");
            }

            for (j = height; j >= i; j--) {
                System.out.print(value + " ");
            }

            System.out.println();
            value++;
        }
        System.out.println();
    }

    static void pattern2(Scanner sc) {
        // Inverted Same Number Triangle Pattern
        System.out.println();
        System.out.println("You are going to see a inverted same number triangle pattern (H.W-2):- ");

        int height, i, j, k, value = 1;

        System.out.println();
        System.out.print("Enter height of the triangle: ");
        height = sc.nextInt();
        System.out.println();

        for (i = 1; i <= height; i++) {
            for (k = 1; k <= (height - i); k++) {
                System.out.print("  ");
            }

            for (j = 1; j <= i; j++) {
                System.out.print(value + " ");
            }

            System.out.println();
            value++;
        }
        System.out.println();
    }

    static void pattern3(Scanner sc) {
        // Continuous Number Triangle Pattern
        System.out.println();
        System.out.println("You are going to see a inverted continuous number triangle pattern (H.W-3):- ");

        int height, i, j, k, value = 1;

        System.out.println();
        System.out.print("Enter height of the triangle: ");
        height = sc.nextInt();
        System.out.println();

        for (i = 1; i <= height; i++) {
            for (k = 1; k <= (height - i); k++) {
                System.out.print("  ");
            }

            for (j = 1; j <= i; j++) {
                System.out.print(value + " ");
                value++;
            }

            System.out.println();
        }
        System.out.println();
    }

    static void pattern4(Scanner sc) {
        // Continuous Number Triangle Pattern
        System.out.println();
        System.out.println("You are going to see a inverted & reverse continuous number triangle pattern (H.W-4):- ");

        int height, i, j, k, value;

        System.out.println();
        System.out.print("Enter height of the triangle: ");
        height = sc.nextInt();
        System.out.println();

        for (i = 1; i <= height; i++) {
            value = 1;
            for (k = 1; k <= i; k++) {
                System.out.print("  ");
            }

            for (j = height; j >= i; j--) {
                System.out.print(value + " ");
                value++;
            }
            System.out.println();
        }
        System.out.println();
    }
}
