class Solution {
private:
    void solve(vector<vector<int>>&ans,int ind,vector<int> nums,vector<int> output){
        
       if(ind>=nums.size())
       {
           ans.push_back(nums);
           return;
       }
        
        for(int i=ind;i<nums.size();i++){
            swap(nums[i],nums[ind]);
            solve(ans,ind+1,nums,output);
            swap(nums[i],nums[ind]);
        }
        
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int ind = 0;
        solve(ans,ind,nums,output);
        return ans;
    }
};