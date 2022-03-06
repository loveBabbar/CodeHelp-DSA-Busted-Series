import java.util.*;

class calculator {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while(1 == 1) {

        System.out.println();
        System.out.print("Enter first number: ");
        int a = sc.nextInt();
    
        System.out.print("Enter second number: ");
        int b = sc.nextInt();

        System.out.println("Please select an operation from the menu below: ");
        System.out.println("1. Addition");
        System.out.println("2. Subtraction");
        System.out.println("3. Multiplication");
        System.out.println("4. Division");
        System.out.println("5. Modulus");
        System.out.println("6. Exit");

        System.out.print("Enter your choice: ");
        int choice = sc.nextInt();

        switch(choice) {
            case 1: System.out.println("Sum of " + a + " and " + b + " is: " + (a+b));
            break;

            case 2: System.out.println("Difference of " + a + " and " + b + " is: " + (a-b));
            break;

            case 3: System.out.println("Product of " + a + " and " + b + " is: " + (a*b));
            break;

            case 4: System.out.println("Division of " + a + " and " + b + " is: " + (a/b));
            break;

            case 5: System.out.println("Modulus of " + a + " and " + b + " is: " + (a%b));
            break;

            case 6: System.exit(-1);
            break;

            default: System.out.println("Invalid Input!");
        }

        }
    }    
}
