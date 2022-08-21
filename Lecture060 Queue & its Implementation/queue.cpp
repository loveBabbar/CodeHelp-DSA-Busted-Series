#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char const *argv[])
{
    // create a queue

    queue <int> q;

    q.push(11);
    cout << "front of queue is : " << q.front() << endl;
    q.push(15);
    cout << "front of queue is : " << q.front() << endl;
    q.push(13);
    cout << "front of queue is : " << q.front() << endl;
    
    cout << "size of queue is : " << q.size() << endl;

    q.pop();
    
    cout << "size of queue is : " << q.size() << endl;
    
    if (q.empty())
    {
        cout << "queue is empty" << endl;
    }
    else {

        cout << "queue is not empty" << endl;
    }


    
    return 0;
}
