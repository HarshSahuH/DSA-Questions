class Solution {
	public static boolean solve(int arr[], int sum, int n, Boolean[][] dp) {
		// 1. Base Cases (Turant return karein)
		if (sum == 0) {
			return  true;
		}
		if (n == 0) {
			return false;
		}
		
		// 2. Memoization Check (Hamesha top par hona chahiye)
		if(dp[n][sum] != null){
		    return dp[n][sum];
		}
		
		// 3. Choice Diagram & Store in Table
		if (arr[n - 1] <= sum) {
			dp[n][sum] = solve(arr, sum - arr[n - 1], n - 1,dp) || solve(arr, sum, n - 1,dp);
		}
		else {
			dp[n][sum] = solve(arr, sum, n - 1,dp);
		}
		
		//at the end last cell return kr do jisme answer hai 
		return dp[n][sum];
	}
	static boolean isSubsetSum(int arr[], int sum) {
		// code here
		int n = arr.length;
		Boolean dp[][] = new Boolean[n+1][sum+1];
		
		
		return solve(arr, sum, n, dp);
	}
}
