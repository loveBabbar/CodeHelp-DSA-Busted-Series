public static boolean checkPalindrome(String str, int i, int  j) {

    //base case
    if(i>j)
        return true;

    if(str.charAt(i) != str.charAt(j))
        return false;
    else{
        //Recursive call
        return checkPalindrome(str, i+1,j-1);
    }
}

public static void main(String[] args) {

    String name = "BookkooB";

    boolean isPalindrome = checkPalindrome(name, 0, name.length()-1 );

    if(isPalindrome) {
        System.out.println("Its a Palindrome ");
    }
    else {
        System.out.println("It's not a Palindrome ");
    }
}
