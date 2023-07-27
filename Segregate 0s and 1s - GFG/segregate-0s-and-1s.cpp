//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    void segregate0and1(int arr[], int n) {
        
        int zeros = 0;
        int ones = 0;
        for(int i=0; i<n; i++)
        {
            if(arr[i] == 0)
            zeros++;
            else 
            ones++;
        }
        
        int i=0;
        while(zeros)
        {
            arr[i] = 0; 
            i++;
            zeros--;
        }
        
        while(ones)
        {
            arr[i] = 1;
            i++;
            ones--;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.segregate0and1(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends