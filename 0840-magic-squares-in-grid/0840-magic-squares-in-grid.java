class Solution {
    public boolean solve(int i, int j, int[][] grid){
        int[] rows = new int[3];
        int[] cols = new int[3];
        Set<Integer> s= new HashSet<>();

        for(int k=i; k<i+3; k++){
            for(int l=j; l<j+3; l++){
                if(grid[k][l] > 9 || grid[k][l] < 1 || s.contains(grid[k][l]) ){
                    return false;
                }
                s.add(grid[k][l]);
                rows[k-i] += grid[k][l];
                cols[l-j] += grid[k][l]; 
            }
        }

        //check sum
        int sum = rows[0];
        for(int n=0; n<3; n++){
            if(rows[n] != sum || cols[n] != sum){
                return false;
            }
        }

        //check diagnols
        int diagonalSum = 0;
        for(int k=0; k<3; k++){
            diagonalSum += grid[k+i][k+j];
        }
        if(diagonalSum != sum){
            return false;
        }

        //another Diagonal
        diagonalSum = 0;
        for(int k=0; k<3; k++){
            diagonalSum += grid[i+2 - k][k+j];
        }
        if(diagonalSum != sum){
            return false;
        }

        return true;
    }

    public int numMagicSquaresInside(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        int count = 0;

        for(int i=0; i<rows-2; i++){
            for(int j=0; j<cols-2; j++){
                if(solve(i,j,grid)){
                    count++;
                }
            }
        }
        return count; 
    }
}