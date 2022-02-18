// C++ program to interleave the first half of the queue
// with the second half
#include <bits/stdc++.h>
using namespace std;

void interLeaveQueue(queue<int> &q)
{
    stack<int> s;
    int n = q.size();

    //Putting first half of queue in stack
    for (int i = 0; i < n / 2; i++)
    {
        int element = q.front();
        q.pop();
        s.push(element);
    }

    //Putting the reversed first half back into queue
    while (!s.empty())
    {
        int element = s.top();
        s.pop();
        q.push(element);
    }
    //Queue now contains second half followed by reversed first half

    //Reallocating second half after reversed first half
    for (int i = 0; i < n / 2; i++)
    {
        int element = q.front();
        q.pop();
        q.push(element);
    }
    //Queue now contains reversed first half followed by second half

    //Pushing the reversed first half into stack
    for (int i = 0; i < n / 2; i++)
    {
        int element = q.front();
        q.pop();
        s.push(element);
    }

    //When we pop from stack now- we get actual order of first half of queue
    while (!s.empty())
    {
        int element = s.top();
        s.pop();
        //first half element
        q.push(element);
        element = q.front();
        q.pop();
        //second half element
        q.push(element);
    }
}

// Driver program to test above function
int main()
{
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);
    interLeaveQueue(q);
    int length = q.size();
    for (int i = 0; i < length; i++)
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}