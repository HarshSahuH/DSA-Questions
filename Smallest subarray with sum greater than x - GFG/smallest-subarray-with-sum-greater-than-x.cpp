//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
      int min_len = INT_MAX;
      if(arr[0] > x) return 1;
      
      int start = 0, end = 0;
      int curr_sum = 0;
      
      while(end < n){
          
          while(curr_sum <=x && end<n)
          curr_sum += arr[end++];
          
          while(curr_sum > x && start < n){
             if(end-start < min_len) 
             min_len = end-start;
             
              curr_sum -=arr[start++];
          }
          
      }
      return min_len;
    }
};

/* Brute Force T.C. O(n^2) S.C. 0(1)
        if( n==1 && x > arr[0] ) return 0;
        if(n==1 && x < arr[0]) return 1;
        
        int min_size = INT_MAX;
        
        for(int i=0; i<n; i++){
            int sum = 0; 
            for(int j=i; j<n; j++)
            {
                sum += arr[j];
                int curr_size = j-i+1;
                if(sum > x && curr_size < min_size ){
                    min_size = min(min_size , curr_size);
                }
            }
        }
     return min_size;
*/

        
        

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}
// } Driver Code Ends