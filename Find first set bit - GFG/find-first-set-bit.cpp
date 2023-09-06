//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find position of first set bit in the given number.
    unsigned int getFirstSetBit(int n)
    {
       string s = "";
       while(n>0){
           int remainder = n%2;
           s = s + to_string(remainder);
           n=n/2;
       }
       reverse(s.begin(),s.end());
       
       int length = s.length();
       int i = length;
       unsigned int postion = 0;
        for(int i=length-1; i>=0; i--){
          if(s[i] == '1'){
              postion = i;
              break;
          }
       }
       return length - postion;
    }
};


//{ Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin>>t; // testcases
    while(t--)
    {
        int n;
        cin>>n; //input n
        Solution ob;
        printf("%u\n", ob.getFirstSetBit(n)); // function to get answer
    }
	return 0;
}

// } Driver Code Ends