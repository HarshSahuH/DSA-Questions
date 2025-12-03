class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {

        List<Integer> ans = new ArrayList<>();

        int rows = matrix.length;
        int cols = matrix[0].length;
        int firstRow = 0;
        int lastRow = rows - 1;
        int firstCol = 0;
        int lastCol = cols - 1;

        while (firstRow <= lastRow && firstCol <= lastCol) {

            // first row
            for (int col = firstCol; col <= lastCol; col++) {
                ans.add(matrix[firstRow][col]);
            }
            firstRow++;

            // last column
            for (int row = firstRow; row <= lastRow; row++) {
                ans.add(matrix[row][lastCol]);
            }
            lastCol--;

            if (firstRow <= lastRow) {
                // last row
                for (int col = lastCol; col >= firstCol; col--) {
                    ans.add(matrix[lastRow][col]);
                }
                lastRow--;
            }

            if (firstCol <= lastCol) {
                // first column
                for (int row = lastRow; row >= firstRow; row--) {
                    ans.add(matrix[row][firstCol]);
                }
                firstCol++;
            }
        }

        return ans;
    }
}
