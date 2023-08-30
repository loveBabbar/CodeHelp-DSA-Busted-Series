#include<iostream>
#include<vector>
using namespace std;

class Solution {

private:
    void solve(vector<int> nums, vector<vector<int>> &ans,int index){

        if(index>=nums.size()){
            ans.push_back(nums);
            return;
        }
        
        for (int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            solve(nums,ans,index+1);
            swap(nums[index],nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index=0;
        solve(nums,ans,index);
        return ans;
    }
};

void test(vector<int> nums){
     Solution solution;
vector<vector<int>> result = solution.permute(nums);
    
    cout << "Permutations:" << endl;
    for (const vector<int> &perm : result) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }

}


int main(){

    vector<int> nums = {1, 2, 3};
    test(nums);
    return 0;
}