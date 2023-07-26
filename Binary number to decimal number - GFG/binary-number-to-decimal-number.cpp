//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int binary_to_decimal(string str) {
        
        int len = str.length();

        int ans = 0;
        int i= 0;
        
        while(len > i)
        {
            int rem = str[len-1-i] - '0';
            ans = ans + (rem * pow(2,i));
            i++;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.binary_to_decimal(str);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends