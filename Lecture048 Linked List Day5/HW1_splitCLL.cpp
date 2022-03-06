#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(){};
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

class CLL{
    public:
    Node *head;
    CLL(){
        head = nullptr;
    };
    CLL(int d){
        head = new Node(d);
        head->next = head;
    }

    Node* insert(Node *h, int data){
        Node *newNode = new Node(data);
        if(h == nullptr){
            h = newNode;
            h->next = h;
            return h;
        }
        if(h->next == h){
            h->next = newNode;
            newNode->next = h;
            return h;
        }
        Node *temp = h;
        while(temp->next != h){
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = h;       
        return h;
    }

    void printCLL(Node *h){
        if(h==nullptr){
            cout << "No CLL element present ... " << endl;
            return;
        }
        Node *temp = h;
        while(temp->next != h){
            cout << temp->data << " --> ";
            temp = temp->next;
        }
        cout << temp->data << " --> "<< temp->next->data << endl;
        return;
    }

};





int main(){
    CLL *cll = new CLL(5);
    cll->head = cll->insert(cll->head, 14);
    cll->head = cll->insert(cll->head, 4);
    cll->head = cll->insert(cll->head, 9);
    cll->head = cll->insert(cll->head, 18);
    cll->head = cll->insert(cll->head, 25);
    cll->head = cll->insert(cll->head, 100);
    cll->head = cll->insert(cll->head, 87);

    cout << "Original CLL : " << endl;
    cll->printCLL(cll->head);

    Node *slow = cll->head;
    Node *fast = cll->head;

    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast = fast->next->next;

        if((fast == cll->head) || (fast->next == cll->head) || (fast->next->next == cll->head)){
            break;
        }
    }

    CLL *h1= new CLL();
    h1->head = cll->head;
    CLL *h2= new CLL();
    h2->head=slow->next;
    slow->next = nullptr;

    Node *temp=h1->head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next=h1->head;

    Node *temp1=h2->head;
    while(temp1->next != cll->head){
        temp1=temp1->next;
    }
    temp1->next = h2->head;

    cout << "After Split : " << endl << endl;
    cout << "First half : " << endl;
    h1->printCLL(h1->head);
    cout << endl;
    cout << "Second half : " << endl;
    h2->printCLL(h2->head);


}