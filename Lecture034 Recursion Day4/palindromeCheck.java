class palindromeCheck {
    static boolean palindrome(char[] t,int i,int j){
        if(i>j){
            return true;
        }
        if(t[i] != t[j]){
            return false;
        }
        else{
            System.out.println(i+" "+j);
            i++;
            j--;
            return palindrome(t,i,j);
        }
    }
    public static void main(String[] args) {
        // code here
        String S = "abba";
        char[] temp = S.toCharArray();
        boolean checkPal = palindrome(temp,0,temp.length-1);
        if(checkPal){
            System.out.println(1);
        }
        else{
            System.out.println(0);
        }
    }
}
