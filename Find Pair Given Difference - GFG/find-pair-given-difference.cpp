//{ Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}
// } Driver Code Ends


bool findPair(int arr[], int size, int n){
 //Approach 2 T.C. O( N logN + N) = NlogN , S.C. O(1)
 sort(arr,arr+size);
 int i = 0; 
 int j = 1;
 
 while(i < size && j < size){
     if(arr[j] - arr[i] == n && i!=j){
         return true;
     }
     else if(arr[j] - arr[i] < n){
         j++;
     }
     else{
         i++;
     }
 }
 return false;
}



 /*
 Approach 1 Brute Force T.C.O(N^2) S.C. O(1)   
    for(int i=0; i<size; i++)
    {
        for(int j=i+1; j<size; j++)
        {
            if(abs(arr[i] - arr[j]) == n)
            return true;
        }
    }
    return false;
*/