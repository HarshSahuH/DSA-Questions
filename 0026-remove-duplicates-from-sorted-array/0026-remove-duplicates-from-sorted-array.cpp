class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        //Approach 2 T.C. O(N) S.C.(1)
        
        int i=0;
        for(int j=1 ; j<nums.size(); j++)
        {
            if(nums[i] != nums[j]){
                //that means this is unique element form privious one
                nums[i+1] = nums[j];
                i++;
            }
        }
        return i+1;
    }
};