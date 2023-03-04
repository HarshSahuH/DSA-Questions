//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalin (string s) {
        int start=0, end = 0, maxLen=1 , n = s.length();
        
        //odd length 
        for(int i=0; i<n-1; i++){
            int l = i-1, r =i+1;
            while(l>=0 && r<n){
                if(s[l]==s[r]){
                    l--, r++;
                }
                else
                    break;
            }
            int len = r-l-1;
            if(len > maxLen){
                maxLen = len ;
                start = l+1;
                end = r-1;
            }
            
        }
        
        //even
         for(int i=0; i<n-1; i++){
            int l = i, r =i+1;
            while(l>=0 && r<n){
                if(s[l]==s[r]){
                    l--, r++;
                }
                else
                    break;
            }
            int len = r-l-1;
            if(len > maxLen){
                maxLen = len ;
                start = l+1;
                end = r-1;
            }
            
        }
        
    
        return s.substr(start, maxLen);

       
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends