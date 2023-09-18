//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    int GCD(int A,int B){
        if(A==0) return B;
        return GCD(B%A,A);
    }
	public:
    int gcd(int N, int arr[])
    {
    	int ans=0;
        for(int i=0;i<N;i++){
            ans=GCD(ans,arr[i]);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;

        int arr[N];
        for(int i = 0; i < N; i++)
        	cin >> arr[i];
        Solution ob;
       	cout <<  ob.gcd(N, arr) << "\n";
   
    }
    return 0;
}
// } Driver Code Ends