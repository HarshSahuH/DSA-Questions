class Solution {
    public int singleNonDuplicate(int[] nums) {
        int n = nums.length;    

        if(n == 1) return nums[0];
        if(n == 2) return nums[0];


        int s = 0;
        int e = nums.length-1;
        while(s<=e){
            if(nums[s] == nums[s+1]) {
                s = s+2;
            }
            else{
                return nums[s];
            }

            if(nums[e] == nums[e-1]){
                e = e-2;
            }else{
                return nums[e];
            }
        }
        return -1;
    }
}