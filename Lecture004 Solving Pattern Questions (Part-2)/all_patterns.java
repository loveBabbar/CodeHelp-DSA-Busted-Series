import java.util.Scanner;

class AllPatterns {
    public static void main(String[] args) {

        int no_of_pattern;
        System.out.println("Select which pattern you want to print from below list:");
        System.out.println("1. Square Pattern.");
        System.out.println("2. Number Square Pattern.");
        System.out.println("3. Another Number Square Pattern.");
        System.out.println("4. Inverted Number Square Pattern.");
        System.out.println("5. Counting Square Pattern.");
        System.out.println("6. 90 Degree Triangle Pattern.");
        System.out.println("7. 90 Degree Counting Triangle Pattern.");
        System.out.println("8. 90 Degree Inverted Counting Triangle Pattern.");
        System.out.println("9. Alphabetic Square Pattern.");
        System.out.println("10. Alphabetic Triangle Pattern.");
        System.out.println("11. Inverted Alphabetic Triangle Pattern.");
        System.out.println("12. Right Angle Inverted Character Triangle Pattern.");
        System.out.println("13. Right Angle Reverse Character Triangle Pattern.");
        System.out.println("14. Number Pyramid Pattern.");
        System.out.println("15. Dabangg Pattern.");
        System.out.print("Enter your choice: ");

        Scanner sc = new Scanner(System.in);
        no_of_pattern = sc.nextInt();

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

            case 5:
                pattern5(sc);
                break;

            case 6:
                pattern6(sc);
                break;

            case 7:
                pattern7(sc);
                break;

            case 8:
                pattern8(sc);
                break;

            case 9:
                pattern9(sc);
                break;

            case 10:
                pattern10(sc);
                break;

            case 11:
                pattern11(sc);
                break;

            case 12:
                pattern12(sc);
                break;

            case 13:
                pattern13(sc);
                break;

            case 14:
                pattern14(sc);
                break;

            case 15:
                pattern15(sc);
                break;

            default:
                System.out.println("Invalid Number, please select a number from above given list :)");
                System.out.println();
        }

        sc.close();
    }

    static void pattern1(Scanner sc) {
        // Square Pattern
        System.out.println();
        System.out.println("You are going to see a square pattern:- ");
        System.out.print("Enter side of the square: ");

        int side, i, j;
        side = sc.nextInt();
        System.out.println();
        for (i = 1; i <= side; i++) {
            for (j = 1; j <= side; j++) {
                System.out.print("* ");
            }
            System.out.println();
        }
        System.out.println();
    }

    static void pattern2(Scanner sc) {
        // Number Square Pattern
        System.out.println();
        System.out.println("You are going to see a square pattern:- ");
        System.out.print("Enter side of the square: ");

        int side, i, j;
        side = sc.nextInt();
        System.out.println();
        for (i = 1; i <= side; i++) {
            for (j = 1; j <= side; j++) {
                System.out.print(i + " ");
            }
            System.out.println();
        }
        System.out.println();
    }

    static void pattern3(Scanner sc) {
        // Number Square Pattern - Part 2
        System.out.println();
        System.out.println("You are going to see another version of number square pattern:- ");

        int side, i, j;
        System.out.print("Enter side of the square: ");
        side = sc.nextInt();

        for (i = 1; i <= side; i++) {
            for (j = 1; j <= side; j++) {
                System.out.print(j + " ");
            }
            System.out.println();
        }
        System.out.println();
    }

    static void pattern4(Scanner sc) {
        // Inverted Number Square Pattern
        System.out.println();
        System.out.println("You are going to see inverted number square pattern:- ");

        int side, i, j;
        System.out.print("Enter side of the square: ");
        side = sc.nextInt();
        System.out.println();

        for (i = 1; i <= side; i++) {
            for (j = 1; j <= side; j++) {
                System.out.print((side - j + 1) + " ");
            }
            System.out.println();
        }
        System.out.println();
    }

    static void pattern5(Scanner sc) {
        // Counting Square Pattern
        System.out.println();
        System.out.println("You are going to see counting square pattern:- ");

        int side, i, j, counter = 1;
        System.out.println();
        System.out.print("Enter side of the square: ");
        side = sc.nextInt();
        System.out.println();

        for (i = 1; i <= side; i++) {
            for (j = 1; j <= side; j++) {
                System.out.print(counter + " ");
                counter++;
            }
            System.out.println();
        }
        System.out.println();
    }

    static void pattern6(Scanner sc) {
        // Right Angled Triangle Pattern
        System.out.println();
        System.out.println("You are going to see right angled triangle pattern:- ");

        int height, i, j;
        char ch;
        System.out.println();
        System.out.print("Enter height of the triangle: ");
        height = sc.nextInt();

        System.out.print("Enter the symbol of which you want to create the triangle also: ");
        ch = sc.next().charAt(0);
        System.out.println();

        for (i = 1; i <= height; i++) {
            for (j = 1; j <= i; j++) {
                System.out.print(ch + " ");
            }
            System.out.println();
        }
        System.out.println();
    }

    static void pattern7(Scanner sc) {
        // Right Angled Counting Triangle Pattern
        System.out.println();
        System.out.println("You are going to see right angled triangle pattern:- ");

        int height;
        char ch;

        System.out.print("Enter height of the triangle: ");
        height = sc.nextInt();

        System.out.print("Enter the symbol of which you want to create the triangle: ");
        ch = sc.next().charAt(0);
        System.out.println();

        for (int i = 1; i <= height; i++) {
            for (int j = 1; j <= i; j++) {
                System.out.print(ch + " ");
            }
            System.out.println();
        }
        System.out.println();
    }

    static void pattern8(Scanner sc) {
        // Right Angled Inverted Counting Triangle Pattern
        System.out.println();
        System.out.println("You are going to see right angled inverted triangle pattern:-");

        int height, i, j;
        System.out.println();
        System.out.print("Enter height of the triangle: ");
        height = sc.nextInt();
        System.out.println();

        for (i = 1; i <= height; i++) {
            for (j = 1; j <= i; j++) {
                System.out.print((i - j + 1) + " ");
            }
            System.out.println();
        }
        System.out.println();
    }

    static void pattern9(Scanner sc) {
        // Alphabetic Square Pattern
        System.out.println();
        System.out.println("You are going to see alphabetic square pattern:- ");

        int side, i, j;
        char ch = 'A'; // * (For printing same alphabets in the rows)
        System.out.println();
        System.out.print("Enter side of the square: ");
        side = sc.nextInt();
        System.out.println();

        for (i = 1; i <= side; i++) {
            // ! char ch = 'A'; (For Printing continuous aplhabetic order)
            for (j = 1; j <= side; j++) {
                System.out.print(ch + " ");
                // ! ch++;
            }
            System.out.println();
            ch++;
        }
        System.out.println();
    }

    static void pattern10(Scanner sc) {
        // Alphabetic Triangle Pattern
        System.out.println();
        System.out.println("You are going to see alphabetic triangle pattern:- ");

        int height, i, j;
        char ch = 'A'; // * (For printing same alphabets in the rows)
        System.out.println();
        System.out.print("Enter height of the triangle: ");
        height = sc.nextInt();
        System.out.println();

        for (i = 1; i <= height; i++) {
            // ! char ch = 'A'; // (For Printing continuous aplhabetic order)
            for (j = 1; j <= i; j++) {
                System.out.print(ch + " ");
                // ! ch++; // (For Printing continuous aplhabetic order)
            }
            System.out.println();
            ch++; // * (For printing same alphabets in the rows)
        }
        System.out.println();
    }

    static void pattern11(Scanner sc) {
        // Inverted Alphabetic Triangle Pattern
        System.out.println();
        System.out.println("You are going to see inverted alphabetic triangle pattern:- ");

        int height, i, j;
        char value, ch = 'A';
        System.out.println();
        System.out.print("Enter height of the triangle: ");
        height = sc.nextInt();
        System.out.println();

        for (i = 1; i <= height; i++) {
            value = (char) (ch + height - i);
            for (j = 1; j <= i; j++) {
                System.out.print(value + " ");
                value++;
            }
            System.out.println();
        }
        System.out.println();
    }

    static void pattern12(Scanner sc) {
        // Inverted Right Angle Character Triangle Pattern
        System.out.println();
        System.out.println("You are going to see inverted right angle triangle character pattern:- ");

        int height, i, j, k;
        char ch;
        System.out.print("Enter height of the triangle: ");
        height = sc.nextInt();

        System.out.print("Enter the symbol of which you want to create the triangle: ");
        ch = sc.next().charAt(0);
        System.out.println();

        for (i = 1; i <= height; i++) {
            for (k = 1; k <= (height - i); k++) {
                System.out.print("  ");
            }
            for (j = 1; j <= i; j++) {
                System.out.print(ch + " ");
            }
            System.out.println();
        }
    }

    static void pattern13(Scanner sc) {
        // Reverse Right Angle Character Triangle Pattern
        System.out.println();
        System.out.println("You are going to see reverse right angle triangle character pattern:- ");

        int height, i, j;
        char ch;
        System.out.println();
        System.out.print("Enter height of the triangle: ");
        height = sc.nextInt();

        System.out.print("Enter the symbol of which you want to create the triangle: ");
        ch = sc.next().charAt(0);
        System.out.println();

        for (i = 1; i <= height; i++) {
            /*
             * for (j = 1; j <= (height - i + 1); j++)
             * {
             * cout << ch << " ";
             * }
             */
            for (j = height; j >= i; j--) {
                System.out.print(ch + " ");
            }
            System.out.println();
        }
    }

    static void pattern14(Scanner sc) {
        // Number Pyramid Pattern
        System.out.println();
        System.out.println("You are going to see a number pyramid pattern:- ");

        int height, i, j, k, l;
        System.out.println();
        System.out.print("Enter height of the pyramid: ");
        height = sc.nextInt();
        System.out.println();

        for (i = 1; i <= height; i++) {
            for (k = 1; k <= (height - i); k++) {
                System.out.print("  ");
            }

            for (j = 1; j <= i; j++) {
                System.out.print(j + " ");
            }

            for (l = i - 1; l >= 1; l--) {
                System.out.print(l + " ");
            }

            System.out.println();
        }
    }

    static void pattern15(Scanner sc) {
        // Dabangg Pattern
        System.out.println();
        System.out.println("You are going to see dabangg pattern:- ");

        int height, i, j, k, l;
        System.out.println();
        System.out.print("Enter height of the pattern: ");
        height = sc.nextInt();
        System.out.println();

        for (i = 1; i <= height; i++) {
            for (j = 1; j <= (height - i + 1); j++) {
                System.out.print(j + " ");
            }

            for (k = 1; k <= (i - 1); k++) {
                System.out.print("* ");
            }

            for (k = (i - 1); k >= 1; k--) {
                System.out.print("* ");
            }

            for (l = (height - i + 1); l >= 1; l--) {
                System.out.print(l + " ");
            }

            System.out.println();
        }
    }

}