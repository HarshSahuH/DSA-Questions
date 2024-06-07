class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_map<int,int> M;
        
        for(int i = 0; i<nums.size(); i++){
            M[nums[i]]++;
        }
        
        for(auto x : M){
            if(x.second > 1){
                return true;
            }
        }
        return false;
    }
};