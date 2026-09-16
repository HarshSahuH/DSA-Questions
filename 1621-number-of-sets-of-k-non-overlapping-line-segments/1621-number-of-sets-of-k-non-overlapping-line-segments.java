class Solution {
    int mod = 1000000007;

    // Standalone nCr method using DP (Pascal's Triangle)
    public int nCr(int n, int r) {
        if (r < 0 || r > n) return 0;
        if (r == 0 || r == n) return 1;

        int[][] dp = new int[n + 1][r + 1];

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= Math.min(i, r); j++) {
                if (j == 0 || j == i) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
                }
            }
        }

        return dp[n][r];
    }

    public int numberOfSets(int n, int k) {
        
        return nCr(n+k-1 , 2*k);

        
    }
}