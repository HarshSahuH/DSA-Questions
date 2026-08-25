class Solution {
	static int perfectSum(int[] arr, int target) {
		// code here
		int n = arr.length;
		int [][]dp = new int[n + 1][target + 1];
		
		dp[0][0] = 1;
		
		for (int i = 1; i<n + 1; i++) {
			for (int j = 0; j<target + 1; j++) {
				if (arr[i-1] <= j) {
					dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
					
				}
				else {
					dp[i][j] = dp[i-1][j];
				}
			}
		}
		
		return dp[n][target];
	}
}
