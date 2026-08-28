class Solution {
    public int countSubsetWithSum(int[] arr, int sum, int n) {
		// code here
		if( n == 0){
		    return (sum == 0) ? 1: 0;
		}

		if(arr[n-1] <= sum){
		    return countSubsetWithSum(arr,sum-arr[n-1],n-1) + countSubsetWithSum(arr,sum,n-1);
		}
		else{
		     return countSubsetWithSum(arr,sum,n-1);
		}
	}
	   public int countPartitions(int[] arr, int diff) {
	       // code here
	       int totalSum = 0;
	       int n = arr.length;

	       for(int i=0; i<n; i++){
	           totalSum += arr[i];
	       }

	       if(diff > totalSum || (diff + totalSum) % 2 != 0){
	           return 0;
	       }
	       //s1 sum of subset one
	       //s2 sum of subset two
	       int s1 = (diff + totalSum)/2;

	       //Agar (totalSum + diff) odd number hai (jaise $11/2 = 5.5$),
	       //toh array elements (integers) ka sum kabhi decimal nahi ho sakta.
	       // Target $S_1$ exist hi nahi karta, iska matlab 0 valid partitions hain. 
	       int s2 = totalSum - s1;

	       return countSubsetWithSum(arr,s1,n);

	   }
    public int totalWays(int[] arr, int target) {
        // code here
        
        return countPartitions(arr,target);
        
    }
}