//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int waitingTime(int N, int X){
        
        if(X >= 10){
            return 0;
        }
        
        return (10-X)*(N-1);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){
        int N, X;
        cin>>N>>X;
        
        Solution ob;
        cout<<ob.waitingTime(N, X)<<"\n";
    }
    return 0;
}
// } Driver Code Ends