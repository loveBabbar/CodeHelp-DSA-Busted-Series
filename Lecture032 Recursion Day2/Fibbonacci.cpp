#include<iostream> 
using namespace std;

class Solution {
public:
    // Recursive function to calculate nth Fibonacci number
    int fibonacci(int n) {
        if (n == 0 || n == 1)
            return n;
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
};

int main() {

    Solution obj;
    int n;

    cout << "Enter a number: ";
    cin >> n;

    cout << "Fibonacci number at position " << n << " is: "
         << obj.fibonacci(n) << endl;

    return 0;
}