#first method

class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        int ans = 1;
        
        for(int i = 0; i <= 30; i++) {
            
            //cout<<" ans "<<ans <<endl;
            if(ans == n)
            {
                return true;
            }
            if(ans < INT_MAX/2)
            ans = ans * 2;   
            
        }
        return false;
    }
};
    
    
    
#secomd method
    
    class Solution {
public:
	bool isPowerOfTwo(int n) {
		if(n <= 0){
			return false;
		}
		return log2(n) == int(log2(n));
	}
};
