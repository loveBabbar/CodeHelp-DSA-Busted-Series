#include <iostream>
#include <stack>

using namespace std;

class Stack {
    // properties
    public :
    int *arr;
    int top;
    int size;

    // behaviour
    // constructor
    Stack(int size) {
        this -> size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element) {

        // first check if there is space in array or not
        if (size - top > 1)
        {
            top++;
            arr[top] = element;
        }
        else 
        {
            cout << "Stack overFLow" << endl;
        }
        
    }

    void pop() {
        if (top >= 0)
        {
            top--;
        }
        else {
            cout << "Stack under flow" << endl;
        }
        
    }

    int peek() {
        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout << "Stack is empty" << endl;
            return -1;
        }

    }

    bool isEmpty() {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

};

int main(int argc, char const *argv[])
{
    Stack st(5);

    st.push(22);
    st.push(43);
    st.push(44);
    st.push(22);
    st.push(43);
    st.push(44);

    cout << st.peek() << endl;
    st.pop();
    cout << st.peek() << endl;
    st.pop();
    cout << st.peek() << endl;
    st.pop();
    cout << st.peek() << endl;

    if (st.isEmpty())
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        cout << "Stack is not empty " << endl;
    }
    

    // creation of stack
    // stack<int>s;

    // push operation
    // s.push(2);
    // s.push(3);

    // //pop
    // s.pop(); // 3 gets popped and only 2 is left in the stack\

    // cout << "Printing top element : " << s.top() << endl; // prints top element

    // if (s.empty())
    // {
    //     cout << "Stack is empty " << endl;
    // }
    // else 
    // {
    //     cout << "Stack is not empty " << endl;
    // }
    
    // cout << "Size of stack is " << s.size() << endl;
    
    /**********************
     * implementation of stack
     * ***********************/

    return 0;
}
