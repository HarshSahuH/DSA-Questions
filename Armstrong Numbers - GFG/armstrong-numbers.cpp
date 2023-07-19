//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    int isArmstrongNumber(int n)
    {
        int temp = n;
        int digits = 0;
        while(temp) //jb tk temp 0 nahi chalte raho
        {
            digits++;
            temp=temp/10;
        }
        
        temp = n;
        int sum = 0;
        while(temp)
        {
            int last_digit = temp%10;
            sum += pow(last_digit,digits);
            temp = temp/10;
        }
        
        if(sum == n)
        return 1;
        else 
        return 0;
    }
  public:
    string armstrongNumber(int n){
        
        if(isArmstrongNumber(n))
        return "Yes";
        else
        return "No";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends