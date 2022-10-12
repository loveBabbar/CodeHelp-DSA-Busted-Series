#include<vector>
using namespace std;

class Solution {
public:
  
    int find_pivot(vector<int> v) {
	int s = 0, e = v.size() - 1;
	int mid=(s + e) / 2;
	while (s < e)
	{
		if(v[mid] < v[mid+1])
     			s=mid+1;
    		else
      			e = mid;
    
		mid = (s + e) / 2;
	}
	return s;
    }
    int peakIndexInMountainArray(vector<int>& arr) {
        return find_pivot(arr);
    }
};





// Using Linear Search

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int ans = 0;
        
        for(int i = 0;i<arr.size()-1;i++){
            if(arr[i]>arr[i+1]){
                ans = i;
                break;
            }
        }
        return ans;
    }
};
