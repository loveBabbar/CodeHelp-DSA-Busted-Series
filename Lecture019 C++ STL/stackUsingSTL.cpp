#include <bits/stdc++.h>
#include <stack>  //headerfile for implementing stack as STL
using namespace std;

/*
stack can be understood by example of: dishes kept over one another.
i.e. it follows rule of: first-in last-out(FILO) and last-in first-out(LIFO)
we can't traverse through the stack.
*/

int main()
{
    stack <string> s;  //STL implementation of stack
    
    s.push("Hi");  //pushing elements into the stack
    s.push("Hello");
    s.push("Namaste");
    cout<<"top element of the stack is: "<<s.top()<<endl;  //for knowing top element of the stack
    
    s.pop();  //removing elements from the stack
    cout<<"top element of stack after pop is: "<<s.top()<<endl;  //printing top element pf the stack

    cout<<"size of stack: "<<s.size()<<endl;  //for knowing size of stack

    cout<<"empty or not: "<<s.empty()<<endl;  //for knowing if stack is empty or not (returns boolean value)
    
    return 0;
}
