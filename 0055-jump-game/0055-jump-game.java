class Solution {
    public boolean canJump(int[] nums) {
        int maxIdx = 0; // this is maxIndex I can reach

        for(int i=0; i<nums.length; i++){
            if(i > maxIdx){
                return false; // maxIndex tk tum pucnh sakte ho then tum usse aage kese puche, 
            }
            maxIdx = Math.max(maxIdx, nums[i]+i);
        }
        return true;
    }
}