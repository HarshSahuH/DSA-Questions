class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        //Approach 1 T.C. O(N) S.C.(N)
        set<int> val;
        for(int i=0; i<nums.size(); i++)
        {
            val.insert(nums[i]);
        }
        
        int index = 0; 
        for(auto it : val)
        {
          nums[index++] = it;   
        }
        return index;
    }
};