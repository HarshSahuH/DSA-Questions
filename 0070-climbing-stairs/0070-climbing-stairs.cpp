class Solution {
    int minCost(int n, vector<int>& dp){
        if(dp[n] != -1) return dp[n];
        if(n<=2) return n;
        
        return dp[n] = minCost(n-1,dp) + minCost(n-2,dp);
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        if(n<=2)return n;
        minCost(n,dp);
        return dp[n];
    }
};

//Recursive Code
        //Base Condition
        //if(n<=2) return n;
        
        //choice diagram
        //return climbStairs(n-1) + climbStairs(n-2);