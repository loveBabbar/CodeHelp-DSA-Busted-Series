package MathsForDSA;

public class FactorsOfANumber {
    // Find All the factors of a Number
    public static void main(String [] args){
        int num = 40;
        factors(num);
    }
    // Time Complexity O(N)
    static void factors(int num){
        for(int i=1; i<= num; i++){
            if(num % i == 0)
                System.out.print(i + " ");
        }
    }
}
