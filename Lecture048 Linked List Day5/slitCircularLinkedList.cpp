#include<iostream>
#include <utility>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node() {
        this->data = 0;
        next = NULL;
    }

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    Node(int data, Node* next) {
        this->data = data;
        this->next = next;
    }
};

Node* middle(Node* head) {
    if (head == NULL || head->next == head) {
        return head;
    }
    Node* slow = head;
    Node* fast = head->next;
    while (fast != head && fast->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

pair<Node*, Node*> splitCircularList(Node* head) {
    pair<Node*, Node*> ans;
    if (head == NULL || head->next == head) {
        ans = make_pair(head, nullptr);
        return ans;
    }
    Node* newhead = middle(head);
    Node* temp = newhead;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newhead;
    Node* temp2 = head;
    while (temp2->next != newhead) {
        temp2 = temp2->next;
    }
    temp2->next = head;

    ans.first = head;
    ans.second = newhead;
    return ans;
}

// Function to print circular linked list
void printCircularList(Node* head) {
    if (!head) return;

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}
