//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    void heapify(vector<int>& arr, int n,int i)
    {
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i +2;
        
        if(left < n && arr[largest] < arr[left])
        largest = left;
        
        if(right < n && arr[largest] < arr[right])
        largest = right;
        
        if(largest != i)
        {
            swap(arr[largest], arr[i]);
            heapify(arr,n,largest);
        }
        return;
    }
public:
    void convertMinToMaxHeap(vector<int> &arr, int N){
     
     for(int i = N/2; i>=0; i--)
     heapify(arr,N,i);
    
    return;
         
    }
    
};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        obj.convertMinToMaxHeap(vec,n);
        for(int i = 0;i<n;i++) cout << vec[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends