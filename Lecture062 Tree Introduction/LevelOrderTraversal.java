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
    
    public static void LevelOrder(Node root)
    {
        Queue<Node> qu = new ArrayDeque<>();
        qu.add(root);
        
        while(qu.size() > 0)
        {
            int count = qu.size();
            for(int i=0; i<count; i++)
            {
                Node temp = qu.remove();
                System.out.print(temp.data +" ");
                
                if(temp.left != null)
                {
                    qu.add(temp.left);    
                }
                
                if(temp.right != null)
                {
                    qu.add(temp.right);    
                }
            }
            System.out.println();
        }
        
    }

	public static void main(String[] args) 
	{
	   Node root = null;
	   root = BuildTree(root);
	   LevelOrder(root);
	    
	}
}



