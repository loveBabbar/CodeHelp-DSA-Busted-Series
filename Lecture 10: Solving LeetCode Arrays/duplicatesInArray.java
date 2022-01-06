class Solution {
    public List<Integer> findDuplicates(int[] nums) {
    final List<Integer> duplicates = new ArrayList<Integer>();
        for(int i = 0; i < nums.length; i++) {
            final int n = Math.abs(nums[i]);
            if(nums[n - 1] < 0) {
                duplicates.add(n);
            } else {
                nums[n - 1] *= -1;
            }
        }
        return duplicates;
        
    }
}
