// "static void main" must be defined in a public class.
public class Main {
    static class Node{
  int data;
  Node next;
  Node prev;
  
  Node(int data){
    this.data = data;
    this.next = null;
    this.prev = null;
    
  }
}

public static void print(Node head){
  Node temp = head;
    
//     if no nodes are present
    if(temp==null) return;
    
    System.out.println();
    
  do{
      System.out.print(temp.data+" ");
      temp = temp.next;
  }while(temp!=head);
}

public static Node insertAtHead(Node head,int data){
    Node newNode = new Node(data);
    
    if(head==null){
        newNode.next = newNode;
        newNode.prev = newNode;
        return newNode;
    }
    newNode.next = head;
    
    Node tail = head.prev;
    
    head.prev = newNode;
    
    tail.next = newNode;
    
    newNode.prev = tail;
    
    head = newNode;
    
    return head;
}

public static Node insertAtTail(Node head,int data){
    Node newNode = new Node(data);
    
    if(head==null){
        newNode.next = newNode;
        newNode.prev = newNode;
        return newNode;
    }
    Node tail = head.prev;
    
    tail.next = newNode;
    
    newNode.prev = tail;
    
    newNode.next = head;
    
    head.prev = newNode;
    
    tail = newNode;
    
    return tail;
    
}

public static void insertAtPosition(Node head,int pos,int value){
    if(head==null){
        Node newNode = new Node(value);
        head = newNode;
        newNode.next = newNode;
    }
    
    else{
        int count = 1;
        
        Node curr = head;
        
        while(count<pos-1){
            curr = curr.next;
            count++;
        }
        
        Node newNode= new Node(value);
        
        newNode.next = curr.next;
        
        curr.next = newNode;
    }
    
}

public static Node deleteNode(int pos,Node head){
    
    int i = 1;
    
    Node curr = head;
    
    while(curr!=null && i<pos-1){
        
        curr = curr.next;
        
        i++;
    }
    
//   if pos > no. of nodes present
    if(curr==null) return head;
    
    Node deleted = curr.next;
    
//     if single node present
    if(deleted==head){
        head = null;
        return head;
    }
    curr.next = deleted.next;
    
    deleted.next.prev = curr;
    
    return head;
}

public static void main(String[] args) {
    
    Node head = insertAtHead(null,10);
    
    insertAtTail(head,13);
    insertAtTail(head,14);

    print(head);

//     head = insertAtHead(head, 100);
//     head = insertAtHead(head, 101);
//     head = insertAtHead(head, 102);
//     head = insertAtHead(head, 103);
//     print(head);
  
//     insertAtPosition(head, 4, 22);
//     insertAtPosition(head, 9, 345);
//     print(head);    

//     deleteNode(4, head);
//     deleteNode(7, head);
//     deleteNode(2, head);
//     print(head);

}
}
