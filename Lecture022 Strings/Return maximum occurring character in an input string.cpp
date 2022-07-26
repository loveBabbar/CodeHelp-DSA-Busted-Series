class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        int arr[26] = {0};
        for(int i=0; i<str.size(); i++){
            char ch = str[i];
            //lowercase
            int number = 0;
            if(ch >= 'a' && ch <= 'z')
                number = ch - 'a';
            else//uppercase
                number = ch -'A';
            arr[number]++;
        }
        int max = -1, ans = 0;
        for(int i = 0; i<26; i++){
            if(max < arr[i]){
                ans = i;
                max = arr[i];
            }
        }
        char finalAns = 'a' + ans;
        return finalAns;
    }
};
