import java.lang.*;

class Solution {
    public boolean valid(char ch) {
        if( (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            return true;
        }
        
        return false;
    }
    
    public boolean checkPalindrome(String a) {
    int s = 0;
    int e = a.length()-1;

    while(s<=e) {
        if(a.charAt(s) != a.charAt(e))
        {
            return false;       
        }
        else{
            s++;
            e--;
        }
    }
    return true;
}

    public boolean isPalindrome(String s) {
        
        //faltu character hatado
        String temp = "";
        
        for(int j=0; j<s.length(); j++) {   
            if(valid(s.charAt(j))) {
                temp += Character.toLowerCase(s.charAt(j));
            }
        }
        //check palindrome
        return checkPalindrome(temp);
        
    }
}
