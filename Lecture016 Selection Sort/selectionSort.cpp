#include<iostream>
using namespace std;
void selectionSort(int arr[], int n)
{   
    for(int i = 0; i < n-1; i++ ) {
        int minIndex = i;
        
        for(int j = i+1; j<n; j++) {
            
            if(arr[j] < arr[minIndex]) 
                minIndex = j;
            
        }
        swap(arr[minIndex], arr[i]);
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
 selectionSort(arr, n); 
    cout << "Sorted array: \n"; 
    printArray(arr, n); 
    return 0; 
} 
    
    
    
    
    
    
    
    
    
    
    
