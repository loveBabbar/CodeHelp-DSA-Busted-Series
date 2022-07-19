class Solution {
private:
    void solve(vector<int> nums, vector<int> output, int index, vector<vector<int> >& ans) {
        //base case
        if(index >= nums.size()) {
            ans.push_back(output);
            return ;
        }
        
        //exclude
        solve(nums, output, index+1, ans);
        
        //include
        int element = nums[index];
        output.push_back(element);
        solve(nums, output, index+1, ans);
        
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int> > ans;
        vector<int> output;
        int index = 0;
        solve(nums, output, index, ans);
        return ans;
        
    }
};














// Faster approach
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> v;
        int i, j, k;
        for(i=0; i<(1<<n); i++){
            vector<int> temp;
            for(j=0; j<n; j++){
                if(i&(1<<j)){
                    temp.push_back(nums[j]);
                }
            }
            v.push_back(temp);
        }
        return v;
    }
};












