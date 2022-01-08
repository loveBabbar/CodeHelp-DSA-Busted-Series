import java.util.Scanner;
class switchomework {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println();
        System.out.print("Enter an amount: ");

        int amount = sc.nextInt();

        sc.close();

        switch(1) {
            case 1: System.out.println((amount/100) + " Rs100 notes needed");
            amount%=100;
            case 2: System.out.println((amount/50) + " Rs50 notes needed");
            amount%=50;
            case 3: System.out.println((amount/20) + " Rs20 notes needed");
            amount%=20;
            case 4: System.out.println((amount/1) + " Rs1 coin/s needed");
        }
    }    
}
