//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
    int CountOne(vector<vector<int> > arr , int i){
        int low = 0; 
        int high = arr[0].size()-1;
        
        int foithrow = arr[0].size(); //foithrow = first one in ith row 
        
        while(low <= high){
            int mid = (low+high)/2;
            
            if(arr[i][mid] == 1){
                foithrow = mid;
                high = mid-1;
            }
            else{
                low = mid + 1; 
            }
        }
        int No_of_count1_ith_row = arr[0].size() - foithrow;
        return No_of_count1_ith_row;
    }
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int omax = 0;
	    int r = -1;
	    
	    for(int i=0; i<n; i++){
	        int coir = CountOne(arr,i); //coir = count of one in ith row
	        
	        if(coir > omax){
	         omax = coir;
	         r = i;  
            }
	    }
	    return r;
	}
};
/*
T.C. O(N log(M) )
S.C O(1)
*/


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends