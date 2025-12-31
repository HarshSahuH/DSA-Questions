class Solution {
    public int search(int[] nums, int target) {
        int n = nums.length-1;
        int low = 0;
        int high = n;

        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target){
                return mid;
            }
            //left part sorted hai check kr lo
            if(nums[low] <= nums[mid]){
                if(nums[low] <= target && target <= nums[mid]){
                    high = mid - 1;
                }
                else{
                    low = mid +1;
                }
            }
            else{
                //right wala sorted hai
                if(target >= nums[mid] && target <= nums[high]){
                    low = mid + 1;
                }else{
                    high = mid -1;
                }
            } 
        }
        return -1;
    }
}