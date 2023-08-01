//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++

class data{
    public:
    int value;
    int arr_pos;
    int val_pos;
    data(int value,int arr_pos, int val_pos)
    {
        this->value = value;
        this->arr_pos = arr_pos;
        this->val_pos = val_pos;
    }
};

class mycompare{
    public:
    bool operator()(data &d1, data &d2){
        return d1.value > d2.value;
    }
};

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int> ans;
        priority_queue<data, vector<data>, mycompare> minHeap;
        
        //step1:
        for(int i=0; i<K; i++)
        {
            data temp(arr[i][0],i,0);
            minHeap.push(temp);
        }
        
        while(!minHeap.empty())
        {
            data curr = minHeap.top();
            minHeap.pop();
            ans.push_back(curr.value);
            int ap = curr.arr_pos, vp = curr.val_pos;
            
            if( vp+1 < arr[ap].size())
            {
                data next(arr[ap][vp+1],ap,vp+1);
                minHeap.push(next);
            }
        }
    return ans;    
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends