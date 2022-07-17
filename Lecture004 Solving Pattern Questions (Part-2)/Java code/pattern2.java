import java.util.Scanner;
class pattern2{
    public static void main(String[] args){
        Scanner sc= new Scanner(System.in);
        int n= sc.nextInt();
        int i=1;
        int count =1;
        while(i<=n){
            int j=1;
            while(j<=n){
                System.out.print(count+" ");
                count++;
                j++;
            }
            System.out.println();
            i++;

        }
        
    }
}

