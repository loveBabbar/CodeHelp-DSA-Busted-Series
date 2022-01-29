#include<iostream>

using namespace std;

    int main(){

        int arr[] = {20, 5, 32, 65, 21};
        int n = sizeof(arr)/sizeof(arr[0]);
         
         int sum = 0;

         for(int i = 0; i<n; i++){

             sum += arr[i];
         }
         
          cout<<"The Sum of array is: "<<sum<<endl;

      return 0;
    }