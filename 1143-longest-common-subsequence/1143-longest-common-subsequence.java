class Solution {
    public int solve(int n, int m, String text1, String text2, int[][]t){
        //base case
        if(n == 0 || m == 0){
            return 0;
        }
        if(t[n][m] != -1){
            return t[n][m];
        }
        // choice diagram 
        if(text1.charAt(n-1) == text2.charAt(m-1)){
            t[n][m] = 1+solve(n-1,m-1,text1,text2,t);
        }else{
            t[n][m] = Math.max(solve(n-1,m,text1,text2,t), solve(n,m-1,text1,text2,t));
        }

        return t[n][m];
    }
    public int longestCommonSubsequence(String text1, String text2) {
        int n = text1.length();
        int m = text2.length();
        int [][]t = new int[n+1][m+1];

        for(int[] row : t){
            Arrays.fill(row,-1);
        }
        return solve(n,m,text1,text2,t);
        
    }
}