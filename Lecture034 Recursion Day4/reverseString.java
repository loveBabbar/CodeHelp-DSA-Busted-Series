
public static void reverse(String str, int i, int j ) {
    
    System.out.println("call recieved for " +str);

    //base case
    if(i>j){
        System.out.println(str);
        return ;
    }

    swap(str,i,j);
    i++;
    j--;

    //Recursive call
    reverse(str,i,j);

}

public static void swap(String str,int i,int j){
  char temp;
  
  temp = str.charAt(i);
  str.charAt(i) = str.charAt(j);
  str.charAt(j) = temp;
}

public static void  main(String args[]) {

    String name = "abcde";

    reverse(name, 0 , name.length()-1 );
}
