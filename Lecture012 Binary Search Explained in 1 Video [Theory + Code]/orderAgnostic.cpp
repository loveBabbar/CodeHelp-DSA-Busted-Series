// order-agnostic binary search
// when array is sorted but we don't know it is ascending or descending
#include <iostream>
using namespace std;

int binarySearch(int arr[], int len, int num){
    int start = 0;
    int end = len - 1;
    bool isAsc = arr[start] < arr[end];
    while(start <= end){
        // int mid = (start + end) / 2;    // may exceed the limit of int
        int mid = start + (end-start)/2;
        if (arr[mid] == num){
            return mid;
        }
        if (isAsc) {
            if (num > arr[mid]){
                // search right half
                start = mid + 1;
            }
            else {
                // search left half
                end = mid - 1;
            }
        }
        else{
            if (num < arr[mid]){
                // search right half
                start = mid + 1;
            }
            else {
                // search left half
                end = mid - 1;
            }
        }
    }
    return -1;  // not found
}

int main(){
    int arr[] = {-19,-2,-1,1,2,3,4,5,6,7};
    int ind = binarySearch(arr, sizeof(arr)/4, 0);
    cout << ind << endl;
}
