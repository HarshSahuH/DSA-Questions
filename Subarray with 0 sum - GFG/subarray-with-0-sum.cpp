//{ Driver Code Starts
// A C++ program to find if there is a zero sum
// subarray
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        unordered_set<int> s;
        int prefix_sum = 0; 
        
        for(int i=0; i<n; i++){
            prefix_sum += arr[i];
            
            if(prefix_sum == 0){
                return true;
            }
            
            if(s.find(prefix_sum) != s.end()){
                return true;
            }
            else{
                s.insert(prefix_sum);
            }
        }
       return false;
    }
};

/* //Naive Approach T.C. O(n^2) S.C.O(1)
        for(int i=0; i<n; i++)
        {
            int curr_sum = 0;
            
            for(int j=i; j<n; j++)
            {
                  curr_sum += arr[j];
                  
                   if(curr_sum == 0){
                    return true;
                }
            }
        }
        return false;*/


//{ Driver Code Starts.
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    Solution obj;
	    	if (obj.subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}
// } Driver Code Ends