class SpiralPrint {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> al = new ArrayList<>();

        int row = matrix.length;
        int col = matrix[0].length;

        int total = row * col;
        int count = 0;

        // initialise the indexes;
        int startRow = 0;
        int endCol = col - 1;
        int endRow = row - 1;
        int startCol = 0;

        while(count < total){

            //print startRow
            for(int idx = startCol; count < total && idx <= endCol; idx++){
                al.add(matrix[startRow][idx]);
                count++;
            }
            startRow++;

            // print lastCol
            for(int idx = startRow; count < total && idx <= endRow; idx++){
                al.add(matrix[idx][endCol]);
                count++;
            }
            endCol--;

            // print lastRow

            for(int idx = endCol; count < total && idx >= startCol; idx--){
                al.add(matrix[endRow][idx]);
                count++;
            }
            endRow--;

            // print firstCol

            for(int idx = endRow; count < total && idx >= startRow; idx--){
                al.add(matrix[idx][startCol]);
                count++;
            }
            startCol++;
        }

        return al;
    }
}
