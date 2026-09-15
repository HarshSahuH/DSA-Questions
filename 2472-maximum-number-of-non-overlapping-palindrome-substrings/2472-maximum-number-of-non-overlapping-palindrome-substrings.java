class Solution {
    public boolean isPalindrome(String s, int start, int end){
        while(start < end){
            if(s.charAt(start) == s.charAt(end)){
                start++;
                end--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    public int solve(int idx, String s, int k, int[] dp, int n){
        //base case
        // if(idx == s.length()){
        //     return 0;
        // }
        dp[n] = 0;

        // if(dp[idx] != -1){
        //     return dp[idx];
        // }

        for(int i=n-1; i>=0; i--){
             int skip = dp[i+1];

             int take = 0;
             for(int j= i+k-1; j<s.length(); j++){
                if(isPalindrome(s,i,j)){
                    int currTake = 1+ dp[j+1];
                    take = Math.max(currTake,take);
                    break;
                }
             }
             dp[i] = Math.max(skip, take);
        }

        
        return dp[0];

        // //choice 1
        // int skip = solve(idx+1, s, k, dp, n);
        // //choice 2 
        // int take = 0;
        // // idx se aage ke saare ending points (j) par try karenge
        // for(int j=idx+k-1; j<s.length(); j++){
        //     // Agar s[idx ... j] palindrome hai:
        //     if(isPalindrome(s,idx,j)){
        //         // Agla jump 'j + 1' par lagega (kyunki j tak cover ho gaya)
        //         int currTake = 1+solve(j+1, s, k, dp, n);
        //         take = Math.max(currTake, take);
        //     }
        // }

        // dp[idx] = Math.max(skip,take);
        // return dp[idx];
    }

    public int maxPalindromes(String s, int k) {
        int n = s.length();
        int dp[] = new int[n+1];
        Arrays.fill(dp, -1);

        return solve(0, s, k, dp, n);
    }
}