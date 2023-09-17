//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    int reversetheNumber(int n){
        int ans = 0;
        while(n){
            int lastdigit = n%10;
            ans = ans * 10 + lastdigit;
            n = n/10;
        }
        return ans;
    }
	public:
		string is_palindrome(int n)
		{
		    int reverseNumber = reversetheNumber(n);
		    if(reverseNumber == n){
		        return "Yes";
		    }
		    return "No";
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	Solution ob;
    	string ans = ob.is_palindrome(n);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends