#include<iostream>
using namespace std;

int binarySearch(int arr[], int size, int key) {

    int start = 0;
    int end = size-1;

    int mid = start + (end-start)/2;    // it can go out of limit of int so we write (start + end)/2 like this

    while(start <= end) {

        if(arr[mid] == key) {           // element found
            return mid;
        }

        //go to right wala part
        if(key > arr[mid]) {
            start = mid + 1;
        }
        else{ //key < arr[mid]
            end = mid - 1;
        }

        mid = start + (end-start)/2;    // updation of mid so that after each execution it will check the condition arr[mid] == key
    }
    
    return -1;
}


int main() { 

    int even[6] = {2,4,6,8,12,18};
    int odd[5] = {3, 8, 11, 14, 16};

    int evenIndex = binarySearch(even, 6, 6);

    cout << " Index of 6 is " << evenIndex << endl;

    int oddIndex = binarySearch(odd, 5, 14);

    cout << " Index of 14 is " << oddIndex << endl;


    return 0;
}

// func to calculate ceiling of a number in an array
// ceiling: find the smallest number in an array which is greater than or equal to a certain number(may be taken as input)

int findPeak(int arr[], int n) {

    int s = 0, e = n-1;
    int mid = s + (e-s)/2;
    if(n > arr[e]) return -1;   // because n is greater than the greatest element of array then ceiling can't be calculated
    while(s<e) {
        //cout<<" s " << s <<" e " << e << endl;
        if(arr[mid] < arr[mid+1]){
            s = mid+1; 
        }
        else{
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s;   // when element is not found, s will be pointing to the ceiling of the number(just do dry run and observe)
}
