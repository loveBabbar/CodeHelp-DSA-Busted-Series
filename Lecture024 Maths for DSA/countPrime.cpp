// Leetcode solution 

class Solution {
public:
    int countPrimes(int n) {
      vector<bool> Prime(n+1, true); // Craeting a boolean function of all prime numbers

      Prime[0]=Prime[1]= false;

      int count=0;
      for(int i=2; i<n; i++){

          if(Prime[i]){
          count++;

          for(int j=2*i; j<n; j=j+i){ // Marking all the numbers in table of i as Prime
            Prime[j]=0;
          }
        }
      } 
      return count; 
    }
};

