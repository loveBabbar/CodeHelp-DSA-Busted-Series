import java.util.*;

class Node {
    int data;
    Node left;
    Node right;

    // Initialise data and nodes
    Node(int data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

public class BinaryTree {

    static Scanner sc = new Scanner(System.in);

    public static Node buildBinaryTree(Node root) {
        System.out.println("Enter data node: ");
        int data = sc.nextInt();
        root = new Node(data);

        // take -1 as a no node or as a points to null
        if (data == -1) {
            return null;
        }

        System.out.println("Enter data for left node of " + data);
        root.left = buildBinaryTree(root.left);

        System.out.println("Enter data for right node of " + data);
        root.right = buildBinaryTree(root.right);

        return root;
    }

    // to travese level order we need queue to easily access it.
    public static void levelOrderTraversal(Node root) {
        Queue<Node> queue = new LinkedList<>();
        queue.add(root);

        // to print data in form of tree we need a break point so we get that level is
        // complete
        // we take null as a flag
        queue.add(null);

        while (!queue.isEmpty()) {
            Node temp = queue.peek();
            queue.poll();
            if (temp == null) {
                System.out.println();
                if (!queue.isEmpty()) {
                    queue.add(null);
                }
            } else {
                System.out.print(temp.data + " ");
                if (temp.left != null) {
                    queue.add(temp.left);
                }
                if (temp.right != null) {
                    queue.add(temp.right);
                }
            }
        }
    }

    public static void reverseLevelOrderTraversal(Node root) {
        // level order tree input : 1, 3, 5, 7, 11, 17, -1, -1, -1, -1, -1, -1, -1

        // use quue to get tree values
        Queue<Node> queue = new LinkedList<>();
        queue.add(root);

        // use stack to reverse the tree
        Stack<Node> stack = new Stack<>();
        // to seperate level use null as a seperator
        queue.add(null);

        while (!queue.isEmpty()) {
            Node temp = queue.peek();
            queue.poll();
            stack.push(temp);

            if (temp == null) {
                if (!queue.isEmpty()) {
                    queue.add(null);
                }
            } else {
                if (temp.right != null) {
                    queue.add(temp.right);
                }
                if (temp.left != null) {
                    queue.add(temp.left);
                }
            }
        }
        // stack = [null, 17, 11, 7, null, 5, 3, null, 1]
        // handle 1st null
        stack.pop();
        while (!stack.isEmpty()) {
            Node temp = stack.peek();
            stack.pop();
            if (temp == null) {
                System.out.println();
            } else {
                System.out.print(temp.data + " ");
            }
        }
        System.out.println();
    }

    public static void inorderTraversal(Node root) {
        if (root == null) {
            return;
        }
        inorderTraversal(root.left);
        System.out.print(root.data + " ");
        inorderTraversal(root.right);
    }

    public static void preorderTraversal(Node root) {
        if (root == null) {
            return;
        }
        System.out.print(root.data + " ");
        preorderTraversal(root.left);
        preorderTraversal(root.right);
    }

    public static void postorderTraversal(Node root) {
        if (root == null) {
            return;
        }

        postorderTraversal(root.left);
        postorderTraversal(root.right);
        System.out.print(root.data + " ");
    }

    public static Node buildFromLevelOrderTraversal(Node root) {
        Queue<Node> queue = new LinkedList<>();
        System.out.println("Enter data for root");
        int data = sc.nextInt();
        root = new Node(data);
        queue.add(root);

        while (!queue.isEmpty()) {
            Node temp = queue.poll();

            System.out.println("Enter left node data for " + temp.data);
            int leftData = sc.nextInt();
            if (leftData != -1) {
                temp.left = new Node(leftData);
                queue.add(temp.left);
            }

            System.out.println("Enter right node data for " + temp.data);
            int rightData = sc.nextInt();
            if (rightData != -1) {
                temp.right = new Node(rightData);
                queue.add(temp.right);
            }
        }
        return root;
    }

    public static void main(String[] args) {
        // create root node
        Node root = null;
        // root = buildBinaryTree(root);

        root = buildFromLevelOrderTraversal(root);

        System.out.println("Printing the level order tracersal output ");
        levelOrderTraversal(root);

        System.out.println("Printing the reverse level order tracersal output ");
        reverseLevelOrderTraversal(root);

        // System.out.println("inorder traversal is: ");
        // inorderTraversal(root);
        // System.out.println();

        // System.out.println("preorder traversal is: ");
        // preorderTraversal(root);
        // System.out.println();

        // System.out.println("postorder traversal is: ");
        // postorderTraversal(root);
        // System.out.println();
    }
}
