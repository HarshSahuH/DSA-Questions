class Solution {
	public void subSetSum(boolean[][] dp, int n, int []nums, int sum) {
		for (int i = 0; i <= n; i++) {
			dp[i][0] = true;
		}
		for (int j = 1; j <= sum; j++) {
			dp[0][j] = false;
		}
		
		for (int i = 1; i<n + 1; i++) {
			for (int j = 1; j<sum + 1; j++) {
				if (nums[i - 1] <= j) {
					dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
				}
				else {
					dp[i][j] = dp[i - 1][j];
				}
			}
		}
	}
	public int minDifference(int nums[]) {
		// code here
		int n = nums.length;
		int sum = 0;
		for (int i = 0; i<n; i++) {
			sum += nums[i];
		}
		boolean [][]dp = new boolean[n + 1][sum + 1];
		
		subSetSum(dp, n, nums, sum);
		
		int ans = Integer.MAX_VALUE;
		for (int s1 = 0; s1 <= sum/2; s1++) {
			if (dp[n][s1]) {
				ans = Math.min(ans, (sum - 2*s1));
			}
		}
		return ans;
		
	}
}
