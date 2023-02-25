//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         
        if(intervals.size() <= 1){
            return intervals;
        }
        
        vector<vector<int>> res;
        
        // sort because what if this test case [[1,3],[8,10],[2,6],[15,18]]
        sort(intervals.begin(),intervals.end());
        
        // start curr with [1,3] and i with [2,6]
        vector<int> curr = intervals[0];
        for(int i=1; i<intervals.size(); i++){
            if(curr[1] < intervals[i][0]){
                res.push_back(curr);
                curr = intervals[i];
            }
            else{
             curr[1] = max(curr[1],intervals[i][1]);
            }
        }
        
         res.push_back(curr);
        return res;

    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends