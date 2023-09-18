//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
	public:
    int gcd(int A, int B) 
	{ 
	  if(A == 0) return B;
	    
	  else if(B==0) return A;
	  
	  else if(A==B) return A;
	  
	  else if(A>B) return gcd(A-B,B);
	  
	  else  return gcd(A,B-A); //B>A 
	} 
};

//{ Driver Code Starts.

int main() 
{
   	int t;
    cin >> t;
    while (t--)
    {
        int A, B;
        cin >> A >> B;
        Solution ob;
       	cout <<  ob.gcd(A, B) << "\n";
    }
    return 0;
}
// } Driver Code Ends