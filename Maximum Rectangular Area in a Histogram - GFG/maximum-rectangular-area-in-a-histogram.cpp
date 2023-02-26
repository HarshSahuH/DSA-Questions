//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    void NSL(vector<long long>& NSL_index ,long long heights[],int n){
        
        stack< pair<long long,long long> > s;
        long long pseudoindex = -1;
        
        for(int i=0; i<n; i++){
            while(s.size()>0 && s.top().first >= heights[i]){
                s.pop();
            }
            if(s.size()==0){
                NSL_index.push_back(pseudoindex);
            }
            else if(s.size()>0 && s.top().first < heights[i]) {
                 NSL_index.push_back(s.top().second);
            }
          s.push({heights[i],i});  
        }
     return;   
    }
    
    void NSR(vector<long long>& NSR_index , long long heights[],int n){
        
        stack<pair<long long,long long> > s;
        long long pseudoindex = n;
        
        for(int i=n-1; i>=0; i--){
            while(s.size()>0 && s.top().first >= heights[i] ){
                s.pop();
            }
            if(s.size()==0){
                NSR_index.push_back(pseudoindex);
            }
            else if(s.size()>0 && s.top().first < heights[i]) {
                NSR_index.push_back(s.top().second);
            }
         s.push({heights[i],i});     
        }
        
        reverse(NSR_index.begin(),NSR_index.end());
        return;
    }
        
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long heights[], int n)
    {
       
        
        vector<long long> NSL_index; 
        vector<long long> NSR_index;
        
        vector<long long> width(n);
        vector<long long> area(n);
        long long mx = INT_MIN;
        
        NSL(NSL_index,heights,n);
        NSR(NSR_index,heights,n);
        
         for(int i=0; i<n; i++){
            long long left = NSL_index[i];
            long long right = NSR_index[i];
        
            width[i]=(right - left - 1);    // width (right - left - 1 );
            area[i] = width[i]*heights[i];
            mx = max(mx,area[i]);
        }
      return mx;  
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends