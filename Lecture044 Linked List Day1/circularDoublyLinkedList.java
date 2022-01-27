class Node{
  int data;
  Node next;
  Node prev;
  
  Node(int data){
    this.data = data;
    this.next = null;
    this.prev = null;
    
  }
}

public void print(Node head){
  Node curr = head;
  
  while(curr.next!=head){
    System.out.print(curr.data+" ");
    curr = curr.next;
  }
  
  System.out.println();
}

public Node insertAtHead(Node ptr,int data){
  Node newNode = new Node(data);
  
  if(ptr==null){
    newNode.next = null;
    newNode.prev = null;
    
    ptr = newNode;
    
    return ptr;
  }
  newNode.next = ptr;
  ptr.prev = newNode;
  newNode.prev = ptr;
  ptr.next = newNode;
  
  ptr = newNode;
  
  return ptr;
}

public Node insertAtTail(Node ptr,int data){
  Node newNode = new Node(data);
  
  if(ptr==null){
    newNode.next = null;
    newNode.prev = null;
    
    ptr = newNode;
    
    return ptr;
  }
  newNode.next = ptr;
  
  ptr.next = newNode;
  
  newNode.prev = ptr;
  
  ptr.prev = newNode;
  
  ptr = newNode;
  
  return ptr;
}

public void insertAtPosition(Node head,int pos,int value){
  Node curr = head,previous = null;
  
  if(pos==1){
    insertAtHead(head,value);
    return;
  }
  
  if(head.next==null){
    insertAtTail(head,value);
    return;
  }
  
  int i = 1;
  
  while(i<pos){
    previous = curr;
    curr = curr.next;
    i++;
  }
  
  Node newNode = new Node(value);
  
  newNode.next = previous.next;
  
  previous.next.prev = newNode;
  
  previous.next = newNode;
  
  newNode.prev = previous;
}

public void deleteNode(int pos,Node head){
  Node curr = head,previous = null;
  
  if(pos==1){
    head = null;
    return;
  }
 
  int i = 1;
  
  while(i<pos){
    previous = curr;
    curr = curr.next;
    i++;
  }
  
  previous.next = curr.next;
  
  curr.next.prev = previous;
}

public static void main(String[] args) {
    
    //created a new node
    Node node1 = new Node(10);
 
    
    //head pointed to node1
    Node head = node1; 
    
    print(head);

    head = insertAtTail(head, 12);

    print(head);

    head = insertAtHead(head, 12);
    print(head);
  
    insertAtPosition(head, 4, 22);
    print(head);    

    deleteNode(4, head);
    print(head);

}
