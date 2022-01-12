public class ReverseString {

    static void swap(char[] arr, int i, int j) {
        char temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static void reverse(char[] str, int i, int j) {
        if(i > j){
            return;
        }
        swap(str, i++, j--);
        reverse(str, i, j);
    }

    public static void main(String[] args) {

        char[] str = "kolkata".toCharArray();
        reverse(str, 0, 6);
        System.out.println(String.valueOf(str));

    }
}
