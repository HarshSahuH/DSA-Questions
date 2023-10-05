class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
            if(mp[nums[i]] > n/3){
                result.push_back(nums[i]);
                mp[nums[i]]=-10000;
            }
        }
        return result;
    }
};