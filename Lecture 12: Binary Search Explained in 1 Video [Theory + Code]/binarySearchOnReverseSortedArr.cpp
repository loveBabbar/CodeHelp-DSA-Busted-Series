#include <iostream>

using namespace std;

int reverseBinary(int arr[], int size, int find){
    int start = 0;
    int end = size;
    
    // loop
    while (start <= end) {

        // formula
        int mid = start + (end - start) / 2;
 
        if (find == arr[mid]) {
            // Return elements index
            return mid;
        }
        else if (find < arr[mid]) {
            // Search in right side
            start = mid + 1;
        }

        else {
            // Search in left side
            end = mid - 1;
        }

    }
    return -1;
}
int main()
{
   // binary Search on reverse sorted array

   int arr[] = { 6, 4, 3, 2, 1, 0 };
   int size = sizeof(arr)/sizeof(arr[0]);

   int find;
   cout << "Enter The Elemet" << endl;
   cin >> find;
   
   int ans = reverseBinary(arr,size,find);
   
   if(ans > -1)
   {
            // Return elements index
            cout<< "Eelemt Found on Index " << ans << endl;
   }
   else 
   {
       cout << "Not Found";
   }
   
 return 0;
}
