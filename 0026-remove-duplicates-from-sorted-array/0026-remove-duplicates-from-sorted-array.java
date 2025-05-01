class Solution {
    public int removeDuplicates(int[] nums) {
        //Two Pointer Approach
        int current = 1;
        int counter = 0;
        for(int i=1; i<nums.length; i++){
            if(nums[i] > nums[i-1]){
                nums[current] = nums[i];
                current++;
                counter++;
            }
        }
        return counter+1;
    }
}