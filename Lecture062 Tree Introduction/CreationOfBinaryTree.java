import java.util.*;
public class Main
{
    public static class Node{
    int data;
    Node left;
    Node right;
    
    Node(int d)
    {
        this.data = d;
        this.left = left;
        this.right = right;
    }
}

    public static Node BuildTree(Node root){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the data");
        int d = sc.nextInt(); 
        root = new Node(d);
        if(d == -1)
        {
            return null;
        }
        
        System.out.println("Enter the data you want to inset at Left of "+d);
        root.left = BuildTree(root.left);
        
        System.out.println("Enter the data you want to inset at right of "+d);
        root.right = BuildTree(root.right);
        
        return root;
        
    }

	public static void main(String[] args) 
	{
	   Node root = null;
	   root = BuildTree(root);
	}
}



