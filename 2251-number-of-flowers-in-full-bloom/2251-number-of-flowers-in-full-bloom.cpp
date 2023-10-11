class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> s,e;
        
        for (vector<int>& flower : flowers) {
            s.push_back(flower[0]);
            e.push_back(flower[1] + 1);
        }
        
        sort(s.begin(), s.end());
        sort(e.begin(), e.end());
        vector<int> ans;
        
        for (int person : people) {
            int i = upper_bound(s.begin(), s.end(), person) - s.begin();
            int j = upper_bound(e.begin(), e.end(), person) - e.begin();
            ans.push_back(i - j);
        }
        
        return ans;
    }
};