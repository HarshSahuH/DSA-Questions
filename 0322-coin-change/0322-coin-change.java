class Solution {
    public int solve(int[]coins, int amount, int n,  int [][] t){
        int ans=0;
        if(amount < 0 || n < 0) return Integer.MAX_VALUE;

        if(amount == 0){
            return 0;
        }

        if(t[amount][n] != -1){
            return t[amount][n];
        }

        //choice diagram
        if(coins[n] <= amount){
            int include = solve(coins, amount-coins[n], n,t);
            int exclude = solve(coins, amount, n-1,t);
            
            if(include != Integer.MAX_VALUE && exclude != Integer.MAX_VALUE)
            ans = Math.min(include+1,exclude);

            else if(include == Integer.MAX_VALUE) ans= exclude;
            else ans = include+1;
        }
        else{
            ans = solve(coins, amount, n-1,t);
        }
        
        return t[amount][n] = ans;
    }
    public int coinChange(int[] coins, int amount) {
        int ans = 0; 
        int n = coins.length-1;
        int [][] t = new int[amount+1][n+1];

        for(int[] row : t){
            Arrays.fill(row,-1);
        }

        ans = solve(coins, amount, n,t);
        if(ans == Integer.MAX_VALUE) return -1;
        return ans;
    }
}