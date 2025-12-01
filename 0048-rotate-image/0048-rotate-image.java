class Solution {
    public void rotate(int[][] matrix) {

        int rows = matrix.length;
        int cols = matrix[0].length;

        //swap rows first
        for(int i=0; i<rows/2; i++){
            for(int j=0; j<cols; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[rows-i-1][j];
                matrix[rows-i-1][j] = temp;
            }
        }
        
        //swap the opsite diagnols
        for(int i=0; i<rows; i++){
            for(int j=0; j<i; j++){
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = temp;
                }
        }

    }
}