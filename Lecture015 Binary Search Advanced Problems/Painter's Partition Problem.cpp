#include<vector>
using namespace std;
bool isPossible(vector<int> &boards, int k,int mid,int n){
    int painterCount = 1;
    int partitionSum = 0;
    
    for(int i = 0;i<n;i++){
        if(partitionSum+boards[i] <= mid){
            partitionSum += boards[i];
        }
        else{
            painterCount++;
            if(painterCount > k || boards[i] > mid ){
                return false;
            } 
            partitionSum = boards[i];
        } 
    }
    return true;
}


int findLargestMinDistance(vector<int> &boards, int k)
{
    int s = 0;
    int sum = 0;
    int n =boards.size();
    
    for(int i = 0; i<n; i++){
        sum += boards[i];
    }
    int e = sum;
    int ans = -1;
    int mid = s+(e-s)/2;
    
    while(s<=e){
        if(isPossible(boards,k,mid,n)){
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return ans; 
}
