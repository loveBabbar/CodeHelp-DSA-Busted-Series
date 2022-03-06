import java.util.*;
class evenOddFunc {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int num = sc.nextInt();

        if(isEven(num)) System.out.println("Even no.");
        else System.out.println("Odd no.");
    }
    
    // 1 -> Even
    // 0 -> Odd
    static boolean isEven(int a) {
        if((a&1) == 1) return false;
        return true;
    }
}
