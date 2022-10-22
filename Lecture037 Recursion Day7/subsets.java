class Solution {
	private void solve(int[] a,int index,List<Integer> output,List<List<Integer>> ans){
		if(index >= a.length){
			ans.add(new ArrayList<>(output));
			return;
		}
		solve(a,index+1,new ArrayList<>(output),ans);
		int ele = a[index];
		output.add(ele);
		solve(a,index+1,output,ans);
		
	}
	
	List<List<Integer>> subsets(int[] A) {
	    // add your logic here
		List<List<Integer>> ans = new ArrayList<>();
		List<Integer> output = new ArrayList<>();
		int index = 0;
		solve(A,index,output,ans);
		return ans;
	}
}
