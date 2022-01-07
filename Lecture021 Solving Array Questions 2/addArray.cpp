#include<iostream> 
#include<vector>
using namespace std; 


void reverse(vector<int> &arr){
    int s = 0, e = arr.size()-1;
    while (s<=e){
        swap(arr[s++],arr[e--]);
    }
}


vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	// Write your code here.
    int i = n-1, j = m-1;
    vector<int>ans;
    int carry = 0;
    while (i>=0 && j>=0){
        int sum = a[i--]+b[j--]+carry;
		carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
    }
    
    while(i>=0){
        int sum = a[i--]+carry;
        carry = sum/10;
        ans.push_back(sum%10);
    }
    
    while(j>=0){
        int sum = b[j--]+carry;
        carry = sum/10;
        ans.push_back(sum%10);
    }
    while(carry != 0){
        ans.push_back(carry%10);
        carry = carry/10;
    }
    reverse(ans);
    return ans;

}


int main(){
    vector<int>arr1 = {1,2,3,4,5};
    vector<int>arr2 = {9,8,7,6,0};
    vector<int>arr3 = findArraySum(arr1, arr1.size(), arr2, arr2.size());
    cout<<"Final array is ";
    for (int i:arr3){
        cout<<i<<' ';
    }
    return 0;
}