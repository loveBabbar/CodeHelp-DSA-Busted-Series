import java.util.*;
class functions {

    public static void main(String[] args) {
        int ans = power();
        System.out.println("answer is: " + ans);
    }
    
    static int power() {

        Scanner sc = new Scanner(System.in);

        int a, b, ans=1;
        a = sc.nextInt();
        b = sc.nextInt();

        for(int i=1; i<=b; i++){
            ans *= a;
        }
        return ans;
    }
}
