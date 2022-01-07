package MathsForDSA;

public class SieveOfEratosthenes {
    // Sieve of Eratosthenes
    // Time Complexity O(N * log(logN))
    // Space Complexity O(N)
    public static void main(String [] args){
        int n = 40;
        boolean [] primes = new boolean[n + 1];
        // By Default all the values in the Boolean Array are false
//        System.out.println(Arrays.toString(primes));
        sieve(n , primes);

    }
    // False in Array Means Number is Prime
    static void sieve(int n, boolean [] primes){
        for(int i=2; i*i <= n; i++){
            // if False then Make all Multiple of i to true
            if(!primes[i]){
                // Make all Multiples of i to True
                for(int j = i*2; j <= n ; j+= i){
                    primes[j] = true;
                }
            }
        }
        // if False then Print the Index
        for(int i=2; i<= n; i++){
            if(!primes[i])
                System.out.print(i + " ");
        }
    }
}
