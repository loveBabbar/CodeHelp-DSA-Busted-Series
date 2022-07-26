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
    
    public static void Inorder(Node root)
    {
        if(root == null)
        return;
        
        Inorder(root.left);
        System.out.print(root.data+" ");
        Inorder(root.right);
        
    }
    
    public static void Postorder(Node root)
    {
        if(root == null)
        return;
        
        Postorder(root.left);
        Postorder(root.right);
        System.out.print(root.data+" ");
        
    }
    
    public static void Preorder(Node root)
    {
        if(root == null)
        return;
        
        System.out.print(root.data+" ");
        Preorder(root.left);
        Preorder(root.right);
        
    }
    
	public static void main(String[] args) 
	{
	   Node root = null;
	   root = BuildTree(root);
	   //LevelOrder(root);
	   
	   System.out.println("Inorder Traversal is ");
	   Inorder(root);
	   System.out.println();
	   
	   System.out.println("Postorder Traversal is ");
	   Preorder(root);
	   System.out.println();

	   System.out.println("Postorder Traversal is ");
	   Postorder(root);
	   System.out.println();
	   
	   /*
	   For Ex Input -:
	   1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
	   */
	}
}



