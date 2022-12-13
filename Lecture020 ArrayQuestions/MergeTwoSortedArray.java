import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class MergeTwoSortedArray {
    public static void main(String[] args) {
        Scanner input=new Scanner(System.in);
        int n=input.nextInt();
        int[] mergearray1=new int[n];
        for (int i = 0; i < n; i++) {
            mergearray1[i]=input.nextInt();
        }
        int m=input.nextInt();
        int[] mergearray2=new int[m];
        for (int i = 0; i < m; i++) {
            mergearray2[i]=input.nextInt();
        }
        System.out.println(Arrays.toString(merge(mergearray1,mergearray2)));
    }
    static int[] merge(int[] arr1,int[] arr2){
        Arrays.sort(arr1);
        Arrays.sort(arr2);
        int[] mergearray=new int[arr1.length+arr2.length];
        ArrayList<Integer> l=new ArrayList<>();
        for (int i = 0; i < arr1.length; i++) {
            l.add(arr1[i]);
        }
        for (int i = 0; i < arr2.length; i++) {
            l.add(arr2[i]);
        }
        for (int i = 0; i < l.size(); i++) {
            mergearray[i]=l.get(i);
        }
        return mergearray;
    }
}
