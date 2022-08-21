#include <iostream>
#include <map>
using namespace std;

bool detectLoop(Node* head) {

    if (head == NULL)
    {
        return false;
    }

    map<Node*, bool> visited;

    Node* temp = head;

    while (temp != NULL)
    {
        // cycle is present
        if (visited[temp] == true)
        {
            return true;
        }
        
        visited[temp] = true;
        temp = temp -> next;
    }
    
    return false;
    
}

int main(int argc, char const *argv[])
{
    
    

    return 0;
}
