class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        
        for(int i=0; i<nums.size(); i++)
        {
            if(mp[nums[i]] == 1)
            {
                return nums[i];
            }
        }
       return 0;   
    }
};
//T.C. O(N) where for inserting element in unordered map  + O(M) traversing the map 
//S.C. O(N) if there is all element are unique 
