class Solution {
    bool checkToeplitz(int row, int col, vector<vector<int>> matrix){
        while(row < matrix.size()-1 && col < matrix[0].size()-1){
            if(matrix[row][col] != matrix[row+1][col+1]){
                return false;
            }
            row++;
            col++;
        }
        return true;
    }
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        for(int i=0; i<row; i++){
            if(checkToeplitz(i,0,matrix) == false){
                return false;
            }
        }
        
        for(int j=0; j<col; j++){
            if(checkToeplitz(0,j,matrix) == false){
                return false;
            }
        }
        
        return true;
    }
};