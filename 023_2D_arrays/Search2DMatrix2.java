class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int rows = matrix.length;
        int col = matrix[0].length;

        int rowIdx = 0;
        int colIdx = col - 1;

        while(rowIdx < rows && colIdx >= 0){
            int val = matrix[rowIdx][colIdx];

            if(val == target){
                return true;
            }
            if(val < target){
                rowIdx++;
            }
            else colIdx--;
        }

        return false;
    }
}
