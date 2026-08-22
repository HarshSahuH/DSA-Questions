class Solution {
    
    public int solve(int w,int[]val, int[] wt, int n, int[][]dp){
        
        if(n==0 || w==0){
            return 0;
        }
        if(dp[n][w] !=-1){
            return dp[n][w];
        }
        if(wt[n-1] <= w){
            dp[n][w] = Math.max(
                    val[n-1] + solve(w-wt[n-1], val, wt, n-1,dp),
                    solve(w, val, wt, n-1,dp));
        }
        else{
            //( wt[n-1] > w)
            dp[n][w] = solve(w,val,wt,n-1,dp);
        }
        return dp[n][w];
    }
    public int knapsack(int W, int val[], int wt[]) {
        int n = wt.length;
        int rows = n+1;
        int cols = W+1;
        int[][] dp = new int[rows][cols];
        
        for(int[] row : dp){
            Arrays.fill(row,-1);
        }
        
        return solve(W,val,wt,n,dp);
    }
}
