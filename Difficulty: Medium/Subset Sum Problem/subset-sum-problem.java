class Solution {
	public static boolean solve(int arr[], int sum, int n) {
		if (sum == 0) {
			return true;
		}
		
		if (n == 0) {
			return false;
		}
		// choice diagram
		// include kro
		if (arr[n - 1] <= sum) {
			return solve(arr, sum-arr[n - 1], n-1) || solve(arr, sum, n-1);
		}
		else {
			return solve(arr, sum, n-1);
		}
	}
	static boolean isSubsetSum(int arr[], int sum) {
		// code here
		int n = arr.length;
		
		return solve(arr, sum, n);
	}
}
