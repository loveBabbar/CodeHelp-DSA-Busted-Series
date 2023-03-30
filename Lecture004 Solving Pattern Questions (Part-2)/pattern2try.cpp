// Try part (PDF-Questions)
// Q-2 Try print Pattern n = 3
// 9 8 7 
// 6 5 4 
// 3 2 1

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int i = 1;                           // i = row
    int p = n * n;
    while (i <= n)
    {
        int j = 1;                      // j = coloumn
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
