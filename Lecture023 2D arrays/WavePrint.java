public class Solution {
    public static int[] wavePrint(int arr[][], int nRows, int mCols) {
        // Write your code here.
        int[] ans = new int[nRows * mCols]; // array to store the values of wave and return

        int idx = 0; // index for traversing the ans indexes

        // Here i represents columns & j represents Rows
        for(int i = 0; i < mCols; i++){

            if(i % 2 != 0){ // bottom to top

                for(int j = nRows - 1; j >= 0; j--){
                    ans[idx++] = arr[j][i];
                }
            }
            else { // top to bottom
                for(int j = 0; j < nRows; j++){
                    ans[idx++] = arr[j][i];
                }
            }
        }

        return ans;
    }
}
