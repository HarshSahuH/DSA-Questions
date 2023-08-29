//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    vector<int> removeDuplicate(int A[], int N) {
        
        unordered_map<int,int> um;
         vector<int> result;
        
        for(int i=0; i<N; i++){
                um[A[i]]++;
        }
        
        for(int i=0; i<N; i++){
            if(um[A[i]] != 0){
                result.push_back(A[i]);
                um[A[i]] = 0;
            }
        }
        return result;
    }
};

//{ Driver Code Starts.

// Driver method to test above method
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<int> v = ob.removeDuplicate(a, n);

        for (auto it : v) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends