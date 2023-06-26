class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        int pair = 0;
        
        sort(nums.begin(), nums.end());
        int i=0;
        int j=1;
        
        while(i<n && j<n)
        {
            if(nums[j] - nums[i] == k){
                pair++;
                i++;
                j++;
                // Skip duplicates of nums[i]
                while (i < n && nums[i] == nums[i - 1])
                    i++;
                // Skip duplicates of nums[j]
                while (j < n && nums[j] == nums[j - 1])
                    j++;
            }
            else if(nums[j] - nums[i] < k){
                j++;
            }
            else{
                i++;
            }
            // Ensure i is always less than j
            if (i == j)
                j++;
        }
        return pair;
    }
};