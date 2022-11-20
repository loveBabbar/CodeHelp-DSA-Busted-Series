class Solution {
private:
    bool checkEqual(int a[26],int b[26]){   
        
        for(int i=0;i<26;i++){
            if(a[i]!=b[i]){
               return 0;
            }            
        }
        return 1;
    }
public:
    bool checkInclusion(string s1, string s2) {
        
        int i = 0;
        int cnt1[26] = {0};
        int cnt2[26] = {0};
        
        for(int i=0; i<s1.length();i++){
            int index = s1[i]-'a';
            cnt1[index]++;
        }
        
        while(i< s1.length() && i<s2.length()){
            int index = s2[i++] - 'a';
            cnt2[index]++;
        }
        
        if(checkEqual(cnt1,cnt2)){
            return 1;
        }
        
        while(i<s2.length()){
            char newCh = s2[i];
            int index = newCh - 'a';
            cnt2[index]++;
            
            char oldCh = s2[i-s1.length()];
            index = oldCh - 'a';
            cnt2[index]--;
            
            i++;
            
            if(checkEqual(cnt1,cnt2))
                return 1;            
        }
        
        return 0;
    }
};
