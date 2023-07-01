//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
    void Helper(int index, int sum, vector<int> &arr, int N, vector<int> &SumSubset)
    {
        if(index == N){
            SumSubset.push_back(sum);
            return;
        }
        
        //not Selecting the element 
        Helper(index + 1, sum, arr, N, SumSubset);
        //selecting the element
        Helper(index + 1, sum + arr[index],arr, N, SumSubset);
        

    }
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> SumSubset;
        
        Helper(0,0,arr,N,SumSubset);
        //sort(SumSubset.begin(),SumSubset.end());
        return SumSubset;
    }
};

//T.C. O(2^N) + O(2^N log 2^N) = O(2^N log 2^N)
//S.C. O(2^N)


//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends