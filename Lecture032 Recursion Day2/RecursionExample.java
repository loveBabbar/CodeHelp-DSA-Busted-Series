public class RecursionExample {
    public static void main(String[] args) {
        int dest = 10;
        int src = 1;

        reachHome(src, dest);
    }
    public static void reachHome(int src , int dest){
        if(src == dest) {
            System.out.println("Reached Home Successfully!!!");
            return;
        }
        reachHome(src+1 , dest);
    }
}
