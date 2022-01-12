public class Palindrom {
    static void swap(char[] arr, int i, int j) {
        char temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static boolean palindrom(char[] str, int i, int j) {
        if(i == j){
            return true;
        }
        if(str[i++] != str[j--]){
            return false;
        }
        palindrom(str, i, j);

        return true;
    }

    public static void main(String[] args) {

        char[] str = "abcdcba".toCharArray();
        System.out.println(palindrom(str, 0, 6));

    }
    
}
