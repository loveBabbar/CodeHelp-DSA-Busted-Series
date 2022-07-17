import java.util.Scanner;

public class pattern11 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int i=1;
        while(i<=n){
            int j=1;
            char start = ((char)('A'+n-i));
            while(j<=i){
                System.out.print(start);
                start++;
                j++;
            }
            System.out.println();
            i++;
        }
    }
}
