#include<stack>
int findMinimumCost(string str) {
  	
    //odd condition
    if(str.length()%2 == 1) {
        return -1;
    }
    
    stack<char> s;
    for(int i=0; i<str.length(); i++) {
        char ch = str[i];
        
        if(ch == '{') 
            s.push(ch);
		else
        {
            //ch is closed brace
            if(!s.empty() && s.top() == '{') {
                s.pop();
            }
            else
            {
                s.push(ch);
            }
        }
    }
    
        //stack contains invalid expression
        int a = 0, b = 0;
        while(!s.empty()) {
            if(s.top() == '{') {
                b++;
            }
            else
            {
                a++;
            }
            s.pop();
        }
        
		int ans = (a+1)/2 + (b+1)/2;
        return ans;
    
    
}


// approch 2 without using stack
// Time complexity: O(n), Space Complexity: O(1);
int findMinimumCost(string str) {
    if(str.size()%2 != 0){
        return -1;
    }
      int ob = 0;
       int cb = 0;
        for (int i = 0; i < str.size(); ++i) {            
            char ch = str[i];
            if(ch =='{'){
                ob++;
            }
            else{
                if(ob>0){
                    ob--;
                }
                else{
                    cb++;
                }
            }
        }
    return (ob+1)/2 +(cb+1)/2;
}
