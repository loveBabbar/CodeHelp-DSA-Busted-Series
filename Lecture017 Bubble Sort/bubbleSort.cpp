#include<vector>
using namespace std;
void bubbleSort(vector<int>& arr, int n)
{   
    for(int i = 1; i<n; i++) {
        //for round 1 to n-1
        bool swapped = false;
        
        for(int j =0; j<n-i; j++) {
            
            //process element till n-i th index
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
            
        }
        
        if(swapped == false) {
            //already sorted
            break;
        }
           
    }
}


/********************* Another way without using vector *********************/
#include<iostream>
using namespace std;
void bubbleSort(int arr[], int n)
{   
    for(int i = 1; i < n; i++ ) {
        
        for(int j = 0 ; j< n-i ; j++) {
            
            if(arr[j] < arr[j+1]){
            
        
        swap(arr[j], arr[j+1]);
      }
    }
  }
}
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
} 
int main()
{
 int n ;
 cin >> n;
 int arr[] = {6,2,8,4,7};
 bubbleSort(arr, n); 
    cout << "Bubbled array: \n"; 
    printArray(arr, n); 
    return 0; 
} 
