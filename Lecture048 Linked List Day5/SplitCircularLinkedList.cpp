#include <iostream>

using namespace std;

// Circular Singly linked list Using Class

class Node {
    public:
        int val;
        Node* next;
        Node(){
            val = 0;
            next = NULL;
        }
        Node(int v){
            val = v;
            next = NULL;
        }
        Node(int v, Node* p){
            val = v;
            next = p;
        }
};

class CircularLinkedList: protected Node{
    private:
        Node *tail;
    public:
        CircularLinkedList(){
            tail = NULL;
        }
        CircularLinkedList(Node *r){
            tail = r;
            tail->next = tail;
        }
        ~CircularLinkedList(){
            Node *root = tail->next; 
            while(root != tail){
                Node* temp = root->next;
                delete root;
                root = temp; 
            }
            delete tail;
        }
        void add(int v){
            if(tail == NULL){
                tail = new Node(v);
                tail->next = tail;
            }else{
                Node *n = new Node(v);
                n->next = tail->next;
                tail->next = n;
                tail = n;
            }
        }  
        void print(){
            if(tail == NULL){
                cout << endl;
                return;
            }
            Node *n = tail->next;
            do{
                cout << n->val << " ";
                n = n->next;
            } while(n != tail->next);
            cout << endl;
        }
        void insertAt(int pos, int x){
            Node *curr = tail->next;
            Node *prev = tail;
            if(pos == 0){
                Node *q = new Node(x);
                q->next = tail->next;
                tail->next = q;
                prev->next = q;
            }
            else{
                while(pos--){
                    prev = curr;
                    curr = curr->next;
                }
                Node *q = new Node(x);
                prev->next = q;
                q->next = curr;
                if(prev == tail){
                    tail = q;
                }
            }
        }
        void deleteNodeAt(int pos){
            Node* prev = tail;
            Node* curr = tail->next;
            while(pos--){
                prev = curr;
                curr = curr->next;
            }
            if(curr == prev){
                tail = NULL;
                delete curr;
                return;
            }
            if(curr == tail){
                tail = prev;
            }
            prev->next = curr->next;
            delete curr;
        }
        void removeValue(int x){
            Node* prev = tail;
            Node* curr = tail->next;
            while(curr->val != x){
                prev = curr;
                curr = curr->next;
                if(prev == tail) return;
            }
            if(curr == prev){
                tail = NULL;
                delete curr;
                return;
            }
            if(curr == tail){
                tail = prev;
            }
            prev->next = curr->next;
            delete curr;
        }
        CircularLinkedList SplitCLL(){
            Node* root = this->tail->next;
            Node* slow = root;
            Node* fast = root->next;
            while(fast != this->tail && fast != root){
                slow = slow->next;
                fast = fast->next->next;
            }
            CircularLinkedList newCLL(this->tail);
            newCLL.tail->next = slow->next;
            if(fast == this->tail){
                fast = root;
            }
            slow->next = fast;
            this->tail = slow;
            if(this->tail == newCLL.tail) newCLL.tail = NULL;
            return newCLL;
        }

};


int main(){
    CircularLinkedList list;
    list.add(16);
    list.add(8);
    list.add(19);
    list.insertAt(0, 3);
    list.add(11);
    list.insertAt(2, 22);
    list.insertAt(5, 212);
    list.add(1);
    list.add(100);
    list.insertAt(6, 99);
    list.print();
    CircularLinkedList newCLL = list.SplitCLL();
    cout << "First Split:" << endl;
    list.print();
    cout << "Second Split:" << endl;
    newCLL.print();
}
