#First method

class Solution {
public:
    int bitwiseComplement(int n) {
        
        int m = n;
        int mask = 0;
        
        if(n == 0)
            return 1;
        
        while( m!=0) {
            mask = (mask << 1) | 1;
            m = m >> 1;
        }
        
        int ans = (~n) & mask;
        
        return ans;
        
    }
};



#Second method

 class Solution {
 public:
     int bitswiseComplement(int n) {
         
          int mask = 1, temp = n;
         while(temp > 0) {
               mask = mask << 1;
              temp = temp >> 1;
          }
          return n^(mask-1);
     }
};
