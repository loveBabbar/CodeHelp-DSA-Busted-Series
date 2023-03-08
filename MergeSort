import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class MergeSort1 {
    public static void main(String[] args) {
        ArrayList<Integer> a = new ArrayList();
        Scanner sc = new Scanner(System.in);
        int n= sc.nextInt();
        for(int i=0; i<n; i++)
        {
            int x = sc.nextInt();
            a.add(x);
        }

        MergeSort(a,0,a.size()-1);

    }
    public  static void MergeSort(ArrayList<Integer>a,int s, int e)

    {
        if(s<e)
            return ;
        int m = s +(e-s)/2;
        MergeSort(a,s,m);
        MergeSort(a,m+1,e);
        MERGE(a,s,e,m);
    }

    public static  void MERGE(ArrayList<Integer>a , int s , int e , int m)
    {
      ArrayList<Integer>b = new ArrayList<>();
       int i=m-s+1;
       int j=e-m;
       int k=s;
       while(i<=m && j<=e)
       {
           if(a.get(i)>=a.get(j))
           {
            b.set( j ,a.get(j));
            j++;

           }
           else
           {
               b.set( i ,a.get(i));
               i++;
           }
       }

        while(j<=e)
        {

            b.set( j ,a.get(j));
            j++;

        }

        while(i<=m)
        {

            b.set( i ,a.get(i));
            i++;

        }
     for(int y=0; y<b.size(); y++)
     {
         System.out.println(b.get(y));
     }

    }
}
