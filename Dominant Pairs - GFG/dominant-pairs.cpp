//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int dominantPairs(int n,vector<int> &arr) /*{
        int ans =0;
        int i=0;
        int j=n/2;
        
        for(int i=0; i<n/2; i++){
            for(int j=n/2; j<n; j++){
             if ( (0<=i && i<n/2) && (n/2<=j && j<n) && (arr[i]>=5*arr[j]) ){
                ans++;
             }
            }
        }
        return ans;
    }*/
    {
         sort(arr.begin()+n/2,arr.end());
        int count=0;
        for(int i=0 ; i<n/2 ; i++){
            int target=arr[i];
            int l=n/2,r=n-1,index=0;
            if(target<5*arr[n/2]){
                continue;
            }
            else if(target>=5*arr[n-1]){
                count+=n/2;
                // cout<<count<<"else if"<<endl;
            }
            else{
                while(l<=r){
                    int m=(l+r)/2;
                    if(target==5*arr[m]){
                        index=m-(n/2)+1;
                        l=m+1;// means from n/2 to m ans is sure;
                    }
                    else if(target>5*arr[m]){
                        index=m-(n/2)+1;
                        l=m+1;
                    }
                    else{
                        r=m-1;
                    }
                }
                count+=index;
                // cout<<count<<"else"<<endl;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.dominantPairs(n,arr)<<endl;
    }
}
// } Driver Code Ends