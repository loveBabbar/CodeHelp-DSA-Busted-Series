class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int row = matrix.length;
        int col = matrix[0].length;

        int start = 0;
        int end = row * col - 1;

        while(start <= end){
            int mid = start + (end - start)/2;

            if(matrix[mid/col][mid%col] == target)
                return true;

            if(matrix[mid/col][mid%col] < target){
                start = mid + 1;
            }
            else end = mid - 1;

        }
        return false;
    }
}
