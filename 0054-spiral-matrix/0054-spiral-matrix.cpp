class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int row_number = matrix.size();
        int col_number = matrix[0].size();
        int sRow = 0;
        int eRow = row_number - 1; 
        int sCol = 0;
        int eCol = col_number - 1;
        int total = row_number * col_number;
        int count = 0;
        vector<int> ans;
        
        while(sRow <= eRow && sCol <= eCol){
            
            //push first row
            for(int i = sCol; i<=eCol && count < total; i++){
                ans.push_back(matrix[sRow][i]);
                count++;
            }
            sRow++;
            
            //push last col
            for(int i = sRow; i <= eRow && count < total; i++){
                ans.push_back(matrix[i][eCol]);
                count++;
            }
            eCol--;
            
            //push last row
            for(int i = eCol; i >= sCol && count < total; i--){
                ans.push_back(matrix[eRow][i]);
                count++;
            }
            eRow--;
            
            //push first col
            for(int i = eRow; i>=sRow && count < total; i--){
                ans.push_back(matrix[i][sCol]);
                count++;
            }
            sCol++;
        }
        return ans;
    }
};