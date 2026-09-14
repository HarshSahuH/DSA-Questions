class Solution {
    public static int LCS(String s1, String s2, int n, int m,int[][]t){
        //base case
        if(n ==0 || m == 0){
            return 0;
        }
        
        if(t[n][m] != -1 ){
         return t[n][m];   
        }
        
        if(s1.charAt(n-1) == s2.charAt(m-1)){
            t[n][m] =  1+ LCS(s1,s2,n-1,m-1,t);
        }
        else{
            t[n][m] =  Math.max(LCS(s1,s2,n-1,m,t), LCS(s1,s2,n,m-1,t));
        }
        
        return t[n][m];
        
    }
    public static int minSuperSeq(String s1, String s2) {
        // code here
        int n = s1.length();
        int m = s2.length();
        int [][]t = new int[n+1][m+1];
        
        for(int[] row : t){
            Arrays.fill(row,-1);
        }
        
        int lcsLength = LCS(s1,s2,n,m,t);
        
        return n+m-lcsLength;
    }
}