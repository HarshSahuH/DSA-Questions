//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &nums, int target) {
        // Your code goes here
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i = 0; i< n - 3; i++){
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            for(int j = i + 1; j < n-2; j++){
                if(j > i + 1 && nums[j] == nums[j - 1]){
                    continue;
                }
                
                int tSum = target - (nums[i] + nums[j]);
                int l = j + 1, h = n - 1;
                while (l < h){
                    if (nums[l] + nums[h] == tSum){
                        vector<int> oneAns = {nums[i], nums[j], nums[l], nums[h]};
                        ans.push_back(oneAns);
                        while(l < h && nums[l] == nums[l + 1]){
                            l++;
                        }
                        while(l < h && nums[h] == nums[h - 1]){
                            h--;
                        }
                        l++;
                        h--;
                    }
                    else if(nums[l] + nums[h] < tSum){
                        l++;
                    }
                    else{
                        h--;
                    }
                    
                }
                
            }
        }
          
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends