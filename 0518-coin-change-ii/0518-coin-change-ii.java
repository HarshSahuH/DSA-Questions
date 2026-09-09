class Solution {
    public int solve(int amount, int[] coins, int n, int[][]t) {
        int ways = 0;
        if(amount <0) return 0;

        if (amount == 0) {
            ways++;
            t[n][amount] = ways;
            return t[n][amount];
        }

        if (n == 0 && amount > 0) {
            return 0;
        }

        if(t[n][amount] != -1){
            return t[n][amount];
        }

        if (coins[n - 1] <= amount) {
            int include = solve(amount - coins[n - 1], coins, n,t);
            int exclude = solve(amount, coins, n - 1,t);
            t[n][amount] = include + exclude;

        } else {
            int exclude = solve(amount, coins, n - 1,t);
            t[n][amount] = exclude;
        }
        return t[n][amount];
    }

    public int change(int amount, int[] coins) {
        int ans = 0;
        int n = coins.length;
        int[][] t = new int[n + 1][amount + 1];

        for(int[] row : t){
            Arrays.fill(row, -1);
        }

        ans = solve(amount, coins, n, t);
        return ans;
    }
}