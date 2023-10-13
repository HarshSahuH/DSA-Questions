
class Solution {
    int minCost(vector<int> &cost, int n,vector<int>& dp){
        if(dp[n] != -1) return dp[n];
        //base Condition
        if(n<=1) return dp[n] = 0;
        if(n == 2) return dp[n] = min(cost[0],cost[1]);
        
        return dp[n] = min( (minCost(cost,n-1,dp) + cost[n-1]), (minCost(cost,n-2,dp)+cost[n-2]) ); 
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,-1);
        
        minCost(cost,n,dp);
        return dp[n];
    }
};