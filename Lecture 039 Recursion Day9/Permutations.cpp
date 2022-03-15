class Solution {
    public:
    void push(vector<vector<int>>& ans,int index,vector<int>& nums)
    {
        //BASE CASE
        if(index>nums.size()-1)
        {
            ans.push_back(nums);
           
            return ;
        }
        
        for(int i=index;i<nums.size();i++)
        {
            swap(nums[i],nums[index]);
            push(ans,index+1,nums);//Recursive function
            //BACKTRACKING(putting string on the original condition as it was previously)
            swap(nums[i],nums[index]);
           
        }
        
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        
        int index=0;
        
        push(ans,index,nums);
        
        return ans;
    }
};