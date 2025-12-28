class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] arr = {-1,-1};

        arr[0] = fristOccurance(nums,target);
        arr[1] = lastOccurance(nums,target);
        return arr; 
    }

    public int fristOccurance(int[] nums,int target){
        int start = 0;
        int end = nums.length -1;
        int index = -1;

        while(start <= end){
            int mid = start + end-start/2;
            if(nums[mid] == target){
                index = mid;
                end = mid -1; 
            }
            else if(nums[mid] > target){
                end = mid -1; 
            }
            else{
                start = mid + 1;
            }
        }
        return index;
    }

    public int lastOccurance(int[] nums, int target){
        int start = 0;
        int end = nums.length -1;
        int index = -1;

        while(start <= end){
            int mid = start + (end - start)/ 2;
            if(nums[mid] == target){
                index = mid;
                start = mid+1;
            }
            else if(nums[mid] > target){
                end = mid-1;
            }
            else{
                start = mid + 1;
            }
        }
        return index;
    }
}