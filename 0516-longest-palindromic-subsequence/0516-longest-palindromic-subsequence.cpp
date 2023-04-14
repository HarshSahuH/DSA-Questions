class Solution {
public:
    int LCS(string s, string rev, int n, int m){
        
        int t[n+1][m+1];
        for(int i=0; i<n+1; i++){
            for(int j=0; j<m+1; j++){
                if(i==0 || j==0){
                    t[i][j]=0;
                }
            }
        }
        
          for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){
                    if(s[i-1]==rev[j-1]){
                    t[i][j] = 1 + t[i-1][j-1]; 
                }
                
                else {
                    t[i][j] = max( t[i][j-1],t[i-1][j] );
                }
            }
          }
        return t[n][m];
        
    }
    int longestPalindromeSubseq(string s) {
        
        string rev = s;
        reverse(rev.begin(), rev.end());
        int n = s.size(), m=rev.size();
        return LCS(s,rev,n,m);
    }
};