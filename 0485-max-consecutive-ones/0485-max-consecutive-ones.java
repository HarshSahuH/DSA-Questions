class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int n = nums.length; 
       int maxStrike = Integer.MIN_VALUE; 
       int currStrike = 0;
    
       for(int i=0; i<n; i++){
            if(nums[i] == 1){
                currStrike++;
            }else{
                currStrike = 0;
            }
            maxStrike = Math.max(currStrike, maxStrike);
       } 

       return maxStrike;
    }
}