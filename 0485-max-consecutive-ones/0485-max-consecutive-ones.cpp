class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        if(nums.size() == 1)
            return (nums[0] == 0) ? 0 : 1;
        
        int ans = 0;
        int counter = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]==1)
            {
                counter++;
                ans = max(ans,counter);
            }
            else{
                counter = 0;
            }
        }
        return ans;
    }
};