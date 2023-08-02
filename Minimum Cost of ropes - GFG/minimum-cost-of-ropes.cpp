//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        
        priority_queue<long long, vector<long long>, greater<long long>> mnHeap;
        
        // minimum wali length ki ropes ko phele add karenge 
        for(int i=0; i<n; i++)
        {
            mnHeap.push(arr[i]);
        }
        
        long long cost = 0;
        
        while(mnHeap.size() > 1){
        long long  mn1 = mnHeap.top();
        mnHeap.pop();
        long long mn2 = mnHeap.top();
        mnHeap.pop();
        
        cost = cost + mn1+mn2;
        mnHeap.push(mn1+mn2);
        }
        
        
        return cost;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.minCost(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends