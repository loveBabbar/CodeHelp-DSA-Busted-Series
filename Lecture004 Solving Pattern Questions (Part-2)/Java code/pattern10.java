import java.util.Scanner;
public class pattern10 {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int i=1;
         while(i<=n){
            int j=1;
            while(j<=i){
                char ch = ((char) + ('A'+i-1));
                System.out.print(ch+ " ");
                j++;
            }
            System.out.println();
            i++;
         }
    }
}

