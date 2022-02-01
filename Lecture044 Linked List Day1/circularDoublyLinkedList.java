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

public static head insertAtPosition(Node head,int pos,int value){
    
     if(pos==1){
        head = insertAtHead(head,value);
        
        return head;
    }
    
//   if pos > no. of nodes insert at last
    if(pos>getLength(tail)){
        
        head = insertAtTail(head,value);
        
        return head;
    }
    
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
    return head;
}

    
public static int getLength(Node tail){
    
    Node head = tail.next;
    
    int len = 1;
    
    while(head!=tail){
        head = head.next;
        len++;
    }
    
    return len;
}
    
public static Node deleteNode(int pos,Node head){
    
    if(pos==1){
        head.prev.next = head.next;
        head = head.next;
        return head;
    }
    
//     if pos of node to be deleted > no. of nodes return
    if(pos>getLength(head)) return head;
    
    int i = 1;
    
    Node curr = head;
    
    while(i<pos-1){
        
        curr = curr.next;
        
        i++;
    }
    

    
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
  
//     head = insertAtPosition(head, 4, 22);
//     head = insertAtPosition(head, 9, 345);
//     print(head);    

//     head = deleteNode(4, head);
//     head = deleteNode(7, head);
//     head = deleteNode(2, head);
//     print(head);

}
}
