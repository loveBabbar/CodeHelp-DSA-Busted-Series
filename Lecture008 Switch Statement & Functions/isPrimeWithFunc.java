import java.util.*;
class isPrimeWithFunc {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        if(isPrime(n)){
            System.out.println("It is Prime.");
        } else{
            System.out.println("Not Prime.");
        }
    }
    
    static boolean isPrime(int n) {
        for(int i=2; i<n; i++) {
            if(n%i == 0){
                return false;
            }
        }
        return true;
    }
}
