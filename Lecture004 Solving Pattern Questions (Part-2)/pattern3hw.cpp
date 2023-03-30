// Home work (PDF-Questions)
// Q-3 

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int i = 1;
    int p = n * n;
    while (i <= n)
    {
        int j = 1;
        while (j <= n)
        {
            cout << p << " ";
            p = p - 1;
            j = j + 1;
        }
        cout << endl;
        i = i + 1;
    }
    return 0;
}
