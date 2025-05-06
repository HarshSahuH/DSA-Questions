//import java.util.Arrays;

class Solution {
    public int singleNumber(int[] nums) {
        int n = nums.length;
        if(n==1) return nums[0];
        int ans = -1;
        Arrays.sort(nums);
        
        for(int i=0; i<nums.length; i++){
            if(i==0){
                if(nums[i] == nums[i+1]){
                    continue;
                }
                else{
                    ans = nums[i];
                }
            }
            if(i<n-1 && i>0){
                if(nums[i-1] == nums[i] || nums[i] == nums[i+1]){
                    continue;
                }
                else{
                    ans = nums[i];
                }   
            }

            if(i==n-1){
                if(nums[i] == nums[i-1]){
                    continue;
                }
                else{
                    ans = nums[i];
                }
            }
        }
        return ans;
    }
}