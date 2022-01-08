import java.util.*;
class ap {

    static int nthAPTerm(int n) {
        return ((3 * n) + 7);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.println(nthAPTerm(n));

    }    
}
