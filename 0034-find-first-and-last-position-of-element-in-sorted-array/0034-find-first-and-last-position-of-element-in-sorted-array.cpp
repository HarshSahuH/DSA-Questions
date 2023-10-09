class Solution {
    int firstOccurance(vector<int>& nums, int target, int n){
        int start = 0;
        int end = n-1;
        int firstPostion = -1;
        
        while(start <= end){
          int mid = start + (end-start)/2;
            if(nums[mid] == target){
                firstPostion = mid;
                end = mid - 1;
            }
            else if(nums[mid] > target){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return firstPostion;
    }
    int lastOccurance(vector<int>& nums, int target, int n){
        int start = 0;
        int end = n-1;
        int LastPostion = -1;
        
        while(start<=end){
          int mid = start + (end-start)/2;
            if(nums[mid] == target){
                LastPostion = mid;
                start = mid + 1;
            }
            else if(nums[mid] > target){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        return LastPostion;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        return {firstOccurance(nums,target,n),lastOccurance(nums,target,n)};
    }
};