//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
        long long *temp = new long long[n+m];
        int i = 0, j = 0, k = 0;
        
        while (i < n && j < m) {
            if (arr1[i] <= arr2[j])
                temp[k++] = arr1[i++];
            else
                temp[k++] = arr2[j++];
        }
        
        while (i < n)
            temp[k++] = arr1[i++];
        
        while (j < m)
            temp[k++] = arr2[j++];
        
        
        for (i = 0; i < n; i++)
            arr1[i] = temp[i];
        
        for (j = 0; j < m; j++)
            arr2[j] = temp[n + j];
            
            delete[] temp;
        } 
        
};

//{ Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 

// } Driver Code Ends