class Solution {
    public int searchInsert(int[] nums, int target) {
        int start = 0;
        int end = nums.length -1;
        int index = -1;

        if(target > nums[end]){
            return end+1;
        }
        if (target < nums[start]){
            return start;
        }

        while(start<=end){
            int mid = (start + ((end - start)/2));
            if(nums[mid] >= target){
                end = mid - 1;
                index = mid;
            }
            else{
                start = mid + 1;
            }
        }
        return index;
    }
}