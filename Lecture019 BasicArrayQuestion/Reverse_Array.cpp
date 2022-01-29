#include<iostream>

using namespace std;

    int main(){

        int arr[] = {20, 5, 32, 65, 21};
        int size = sizeof(arr)/sizeof(arr[0]);
         
         int max = 0;

         for(int i = size - 1; i >= 0; i--){
          
          cout<<arr[i]<<" ";
             
         }
         
           

      return 0;
    }