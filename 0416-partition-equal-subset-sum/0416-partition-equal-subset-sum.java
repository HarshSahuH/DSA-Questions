class Solution {
    public boolean SubArraySum(int[] nums, int halfSum, int n, Boolean[][] dp){
        if(n==0) return false;
        if(halfSum == 0) return true;

        //meoization
        if(dp[n][halfSum] != null){
            return dp[n][halfSum];
        }

        if(nums[n-1] <= halfSum){
            dp[n][halfSum] =  SubArraySum(nums,halfSum - nums[n-1],n-1,dp) || SubArraySum(nums,halfSum,n-1,dp);
        }
        else{
            dp[n][halfSum]  = SubArraySum(nums,halfSum,n-1,dp);
        }
        return dp[n][halfSum];
    }
    public boolean canPartition(int[] nums) {
        //check sum of array is even or odd
        //No need to count the eniter sum 
        //just check how many elements are even and odd
        //even + even = even 
        //even + odd = odd
        //odd + odd  = even

        int totalOdd = 0;
        int n = nums.length;
        int totalSum = 0;

        for(int i=0; i<n; i++){
            if(nums[i] % 2 != 0){
                totalOdd++;
            }
        }

        //now lets decide on the basis of total odd elements in nums array what will be the total sum of the nums array is it odd or is it even

        if(totalOdd % 2 != 0){
            //Total sum will be odd No partition possible
            return false;
        } 
        //sum will be even
        else{
            // Now we will required the sum because what we will do we will find is there is any sub array whose sum is equal to half of the total sum 
            for(int i =0; i<n; i++){
                totalSum += nums[i];
            }

            int halfSum = totalSum/2;
            Boolean [][] dp = new Boolean[n+1][halfSum+1];
            return SubArraySum(nums, halfSum, n, dp);
        }

    }
}