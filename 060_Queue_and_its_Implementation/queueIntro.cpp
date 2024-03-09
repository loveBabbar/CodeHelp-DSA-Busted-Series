#include<iostream>
#include<queue>
using namespace std;

int main() {
    cout << (-1)%1<< endl;
    deque<int> d;

    d.push_front(12);
    d.push_back(14);

    cout << d.front() << endl;
    cout << d.back() << endl;

    d.pop_front();
    
    cout << d.front() << endl;
    cout << d.back() << endl;
    d.pop_back();

    if(d.empty()) {
        cout << "queue is empty" << endl;
    }
    else{
        cout << "queue is not empty " << endl;
    }

    /*
    //create a queue
    queue<int> q;

    q.push(11);
    cout << "front of q is: " << q.front() << endl;
    q.push(15);
    cout << "front of q is: " << q.front() << endl;

    q.push(13);
    cout << "front of q is: " << q.front() << endl;

    cout << "size of queue is : " << q.size() << endl;

    q.pop();
    q.pop();
    q.pop();

    cout << "size of queue is : " << q.size() << endl;

    if(q.empty()) {
        cout << "Queue is empty " << endl;
    }
    else{
        cout << "queue is not empty " << endl;
    }
    */


    return 0;
}