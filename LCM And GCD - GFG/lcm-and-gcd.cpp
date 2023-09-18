//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    long long GCD(long long A, long long B){
        
        if(A==0) return B;
        else if(B==0) return A;
        else if(A==B) return A;
        else if(A>B) return GCD(A-B,B);
        else return GCD(A,B-A);          //if (B>A) return GCD(A,B-A)
    }
    
    long long LCM(long long A,long long B){
        return A*B/GCD(A,B);
    }
    
  public:
    vector<long long> lcmAndGcd(long long A , long long B) {
        
        return {LCM(A,B),GCD(A,B)};
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends