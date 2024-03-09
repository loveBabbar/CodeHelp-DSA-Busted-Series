public class SumCalc {
    public static void main(String[] args) {

        int[] arr = {2 ,4 ,15 ,15 ,15};
        int ans = calcSum(arr , 5);
        System.out.println(ans); // Ans is 51
    }

    public static int calcSum(int[] arr , int size){
        if(size == 1)
            return arr[0];
        return sumHelper(arr , 0 , size ,0);
    }

    public static int sumHelper(int[] arr , int idx , int size , int sum){
        //base case
        if(idx == size)
            return sum;
        int currSum = sum + arr[idx];
        return sumHelper(arr , idx + 1 , size , currSum);
    }
}
