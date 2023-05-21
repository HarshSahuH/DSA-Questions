//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    void segregateElements(int arr[],int n)
    {
       vector<int> pos;
       vector<int> neg;
       
       for(int i=0; i<n; i++){
           if(arr[i]>0){
               pos.push_back(arr[i]);
           }
           else if(arr[i]<0){
               neg.push_back(arr[i]);
           }
       }
       
       int j=0;
       for(int k=0; k<pos.size(); k++){
           arr[j] = pos[k];
           j++;
       }
      
       for(int k=0; k<neg.size(); k++){
           arr[j] = neg[k];
           j++;
       }
       
    }
};




/* int l=0,r=n-1;
        
        while(l<r){
            
            if(arr[l]>0 && arr[r]>0){
                l++;
            }
            else if(arr[l]>0 && arr[r]<0){
                l++;
                r--;
            }
            else if(arr[l] <0 && arr[r]>0){
                swap(arr[l],arr[r]);
                l++;
                r--;
            }
            else {
                //arr[l]<0 && arr[r]<0
                r--;
            }
        }
        */

//{ Driver Code Starts.
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		ob.segregateElements(a,n);
		
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
		cout<<endl;
	}
}

// } Driver Code Ends