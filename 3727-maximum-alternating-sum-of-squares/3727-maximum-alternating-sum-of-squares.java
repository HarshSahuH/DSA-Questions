class Solution {
    public long maxAlternatingSum(int[] nums) {
        int n = nums.length;
        for(int i=0; i<n; i++){
            nums[i] = nums[i]*nums[i];
        }

        Arrays.sort(nums);

        int negativewant = n/2;

        long negativeSum = 0;
        long positiveSum = 0;

        for(int i=0; i<negativewant; i++){
            negativeSum += nums[i];
        }

        for(int i=negativewant; i<n; i++){
            positiveSum += nums[i];
        }

        return positiveSum-negativeSum;
    }
}