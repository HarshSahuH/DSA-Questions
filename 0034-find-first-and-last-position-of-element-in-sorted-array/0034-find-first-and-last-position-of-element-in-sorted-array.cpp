class Solution {
    int firstOccurance(vector<int>& nums,int target,int size)
    {
        int first=-1;
        int s=0;
        int e = size-1;
        while(s<=e)
        {
         int mid = s+(e-s)/2;
            if(nums[mid] == target){
              first = mid;
              e = mid - 1;
            }
            else if(nums[mid] > target){
                e = mid - 1;
            }
            else {
                s = mid + 1;
            }
        }
        return first;
    }
int LastOccurnance(vector<int>& nums,int target,int size)
    {
        int last=-1;
        int s=0;
        int e = size-1;
        while(s<=e)
        {
         int mid = s+(e-s)/2;
            if(nums[mid] == target){
              last = mid;
              s = mid + 1;
            }
            else if(nums[mid] > target){
                e = mid - 1;
            }
            else {
                s = mid + 1;
            }
        }
        return last;
    }                   
                       
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2);
        int size = nums.size();
        
        int starting = firstOccurance(nums, target, size);
        int ending = LastOccurnance(nums, target, size);
        
        ans[0] = starting;
        ans[1] = ending;
        return ans;
        
    }
};