class Solution {
    int countFreq(int[] arr, int target) {
        
        
       
        int first = firstOccurance(arr, target);
        if (first == -1) return 0;   // target not found

        int last = lastOccurance(arr, target);
        return last - first + 1;
        
    }
    
    public int firstOccurance(int[]arr,int target){
        int index = -1;
        int start = 0;
        int end = arr.length-1;
        
        while(start<=end){
            int mid = start + (end-start)/2;
            
            if(arr[mid] == target){
                index = mid;
                end = mid-1;
            }
            else if(arr[mid] > target){
                end = mid-1;
            }
            else{
                start = mid+1;
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
