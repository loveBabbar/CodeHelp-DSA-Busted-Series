class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0;
        int res=0;
        int n=chars.size();
        while(i<n){
            int j=i+1;
            while(j<n && chars[i]==chars[j]){
               j++; 
            }
            //after traversing
            //after new char

            //store old char
            chars[res++]=chars[i];
            int count =j-i;
            if(count>1){
                //convert count to string
                string cnt=to_string(count);
                for(char ch:cnt){
                    chars[res++]=ch;
                }
            }
            i=j;
        }
        return res;
        
    }
};
