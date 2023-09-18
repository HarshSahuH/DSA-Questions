class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> ans(k); 
        
        set<pair<int,int>> st;
        for(int i=0; i<mat.size(); i++){
            int count1 = 0;
            for(int j=0; j<mat[0].size(); j++){
                if(mat[i][j] == 1){
                    count1++;
                }
                else{
                    break;
                }
            }
            st.insert({count1,i});
        }
        
        for(int i=0; i<k; i++){
            ans[i] = st.begin()->second;
            st.erase(st.begin()); // Remove the weakest row from the set
        }
        
        return ans;
    }
};