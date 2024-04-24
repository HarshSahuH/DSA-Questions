class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;
        int row = matrix.size();
        int col = matrix[0].size();
        
      
        unordered_map<int,int> mp;
        
        //minimum of each row
        for(int i=0; i<row; i++){
            int minn = INT_MAX;
            for(int j=0; j<col; j++){
              minn = min(matrix[i][j],minn);
            }
           mp[minn]++;
        }
       
        //maximum of each col
        for(int j=0; j<col; j++){
            int maxx = INT_MIN;
            for(int i=0; i<row; i++){
              maxx = max(matrix[i][j],maxx);
            }
            mp[maxx]++;
        }
        
        
       for(auto x: mp){
           if(x.second > 1){
               ans.push_back(x.first);
           }
       }
        return ans;
    }
};