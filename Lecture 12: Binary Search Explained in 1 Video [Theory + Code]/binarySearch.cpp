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

// func to find the peak index in a mountain array(bitonic array)
// mountain or bitonic array is like: [1 2 3 4 5 4 2 1], it increases at first till some index then decreases

int findPeak(int arr[], int n) {

    int s = 0, e = n-1;
    int mid = s + (e-s)/2;
    while(s<e) {
        //cout<<" s " << s <<" e " << e << endl;
        if(arr[mid] < arr[mid+1]){
            // u r in increasing part as arr[mid+1] is greater than arr[mid]
            s = mid + 1;
        }
        else{
            // u r in decreasing part
            // this may be the answer but look at left
            // so e will not be equal to mid-1
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    // in the end start and end will be pointing to the max element
    // start and end are always trying to find the max element in above two
    // checks and hence when they are equal, then they must be pointing to the max element
    return s;
    
}
