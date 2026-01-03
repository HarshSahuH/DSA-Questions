class Solution {
    public int findPeakElement(int[] nums) {
        int n = nums.length;
        int peak = Integer.MIN_VALUE;
        int peakIndex = 0;

        for(int i=1; i<=n-2; i++){
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1]){
                peak = Math.max(peak,nums[i]);
                peakIndex = i;
            }
        }

        if(nums[0] > nums[peakIndex]) return 0;
        else if (nums[n-1] > nums[peakIndex]) return n-1;
        else return peakIndex;
    }
}