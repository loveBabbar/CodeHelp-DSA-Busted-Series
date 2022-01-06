import java.util.*;
import java.lang.*;

public static char toLowerCase(char ch) {
    if(ch >='a' && ch <='z')
        return ch;
    else{
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

public static boolean checkPalindrome(char a[], int n) {
    int s = 0;
    int e = n-1;

    while(s<=e) {
        if(Character.toLowerCase( a[s] ) != Character.toLowerCase( a[e] ) )
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

public static void reverse(char name[], int n) {
    int s=0;
    int e = n-1;

    while(s<e) {
        swap(name,s,e);
        s++;
        e--;
    }
}

public static void swap(char[] arr,int i,int j){
  char temp;
  
  temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

public static int getLength(char name[]) {
    int count = 0;
    for(int i = 0; name[i] != '\0'; i++) {
        count++;
    }

    return count;
}

public static char getMaxOccCharacter(string s) {

    int arr [] = new int[26];


    //create an array of count of characters
    for(int i=0; i<s.length(); i++) {
        char ch = s[i];
        //lowercase
        int number = 0;
        number = ch - 'a';
        arr[number]++;
    }

    //find maximum occ character
    int maxi = -1, ans = 0;
    for(int i=0;i<26; i++) {
        if(maxi < arr[i]) {
            ans = i;
            maxi = arr[i];
        }
    }
    

    return 'a'+ans;

}

public static void main(String[] args ) {
  
   Scanner sc = new Scanner(System.in);
  
   string s = sc.nextLine();
    
    System.out.println(getMaxOccCharacter(s));
}
