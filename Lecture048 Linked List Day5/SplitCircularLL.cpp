void InsertNode(Node* &tail, int element,int d){
    
    //empty list
    if( tail == NULL){
        Node* newNode = new Node(d);
        tail = newNode;
        newNode-> next = newNode;
    }else{
        //non-empty list
        //assuming that the element is present in the list 
        Node* curr = tail;
        while( curr->data != element){
            curr = curr -> next;
        }
        //element found ->curr is representing element wala node
        Node* temp = new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;

    }
}
void print(Node* tail){
    Node* temp = tail;
    if( tail == NULL){
        cout << "List is empty "<<endl;
    }
    do{
        cout << tail -> data << " ";
        tail = tail -> next;
    }while( tail != temp);
    cout<<endl;
}


void splitCircularList(Node* head)
{
    if( head == NULL) return;
    if( head->next == NULL) cout<< head->data;
    int len = 2;
    Node* temp = head;
    Node* tail = head;
    while( temp -> next != head){
        len++;
        tail = tail -> next;
        temp = temp -> next;
    }
    int mid = ceil(len/2);
    int cnt = 1;
    temp = head;
    while( cnt < mid){
        temp = temp -> next;
        cnt++;
    }
    Node* forward = temp -> next;
    temp -> next = tail -> next;
    tail -> next = forward;
    print(head);
    print(forward);
}


int main(){
    Node* tail = NULL;
    InsertNode(tail, 5 , 3);
    InsertNode(tail, 3 , 5);
    InsertNode(tail, 5 , 7);
    InsertNode(tail, 7 , 9);
    InsertNode(tail, 5 , 6);
    InsertNode(tail, 9 , 10);
    InsertNode(tail, 3, 4);

    splitCircularList(tail);
    return 0;
}
