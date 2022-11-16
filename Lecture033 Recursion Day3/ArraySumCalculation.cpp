#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int ArraySum(int arr[] , int size){

            int sum = 0;

            if(size == 1){      // Base Case......
                return arr[0];
            }

            return SumBuild(arr, 0, size, sum);

        }

        int SumBuild(int arr[], int index, int size, int sum){
            
            if(index == size){  //Base Case......
                return sum;
            }

            int curr = sum + arr[index];

            return SumBuild(arr, index + 1, size, curr);

        }
};

int main(){
    int arr[] = {5,13,3,7,9};

    Solution ob;

    int size = sizeof(arr)/ sizeof(arr[0]);

    cout << "Sum is = " << ob.ArraySum(arr, size);;

    return 0;
}
