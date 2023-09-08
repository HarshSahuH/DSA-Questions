class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        
        // Initialize the first row with a single element, which is 1
        ans[0] = {1};
        
        for(int i=1; i<numRows; i++){
            // Resize the current row to have 'i+1' elements
            ans[i].resize(i+1);
            // The first element in each row is always 1
            ans[i][0] = 1;
            for(int j=1; j<i; j++){
                // Calculate the middle elements using the previous row
                ans[i][j] = ans[i-1][j] + ans[i-1][j-1];
            }
             // The last element in each row is always 1
            ans[i][i] = 1;
        }
        return ans;
    }
};