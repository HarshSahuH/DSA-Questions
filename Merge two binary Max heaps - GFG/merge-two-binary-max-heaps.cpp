//{ Driver Code Starts
// Initial Template for C++

// C++ program to merge two max heaps.

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    void heapify(vector<int>&ans,int size, int i)
    {
        int largest = i;
        int left_child = 2*i+1;
        int right_child = 2*i+2;
        
        if(left_child < size && ans[left_child] > ans[largest])
        largest = left_child;
        
        if(right_child < size && ans[right_child] > ans[largest])
        largest = right_child;
        
        if(largest != i)
        {
            swap(ans[largest],ans[i]);
            heapify(ans,size,largest);
        }
        
    }
    void buildheap(vector<int>&ans, int size){
        for(int i=size/2 -1; i>=0; i--)
        {
            heapify(ans,size,i);
        }
    }
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        
        vector<int> ans;
        
        //step 1
        for(auto i: a)
        {
            ans.push_back(i);
        }
        for(auto j:b)
        {
            ans.push_back(j);
        }
        
        int size = ans.size();
        buildheap(ans,size);
        
        return ans;
        
    }
};

//{ Driver Code Starts.

bool isMerged(vector<int> &arr1, vector<int> &arr2, vector<int> &merged){
    if (arr1.size() + arr2.size() != merged.size()){
        return false;
    }
    arr1.insert(arr1.end(),arr2.begin(),arr2.end());
    sort(arr1.begin(),arr1.end());
    vector<int> mergedCopy =merged;
    sort(mergedCopy.begin(),mergedCopy.end());
    if (arr1 != mergedCopy){
        return false;
    }
    for(int i = 1; i<merged.size(); i++){
        if(merged[i] > merged[(i-1)/2])
            return false;
    }
    return true;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        vector<int> a(n,0),b(m,0);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (i = 0; i < m; i++) {
            cin >> b[i];
        }
        vector<int> merged, copyA = a, copyB = b;
        Solution obj;
        merged = obj.mergeHeaps(a, b, n, m);
        bool flag = isMerged(copyA, copyB, merged);
        if(flag == false) cout<<0<<endl;
        else cout<<1<<endl;
    }
    return 0;
}

// } Driver Code Ends