import java.util.Scanner;

public class pattern9 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n =sc.nextInt();
        int i =1;
        while(i<=n){
            int j=1;
            while(j<=n){
                char ch = ((char)('A'+j-1));
                System.out.print(ch);
                j++;
            }
            System.out.println();
            i++;
        }
    }
}
