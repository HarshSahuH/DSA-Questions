class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        unordered_map<int,int> UM;
        for(int i=0;i<nums.size(); i++){
            UM[nums[i]]++;
        }
        
        vector<int>result;
        for(auto x : UM){
            if(x.second >=2){
                result.push_back(x.first);
            }
        }
        return result;
    }
};