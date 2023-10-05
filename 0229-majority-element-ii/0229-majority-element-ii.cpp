class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
         unordered_map<int, int> mp;

        for(int i: nums){
            mp[i]++;
        }

        int x = nums.size() / 3;
        nums.clear();

        for(auto i : mp){
            if(i.second > x){
                nums.push_back(i.first);
            }
        }
        return nums; 
    }
};