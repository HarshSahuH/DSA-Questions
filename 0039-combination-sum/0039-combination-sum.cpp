class Solution {
    void findCombination(int index, vector<int>& arr, vector<int>& ds,int target,vector<vector<int>>& ans)
    {
        if(index == arr.size())
        {
            if(target ==0) {
                ans.push_back(ds);
            }
             return;
        }
        
        //Pick the element 
        if(arr[index] <= target)
        {
            ds.push_back(arr[index]);
            findCombination(index, arr, ds, target-arr[index], ans);
            ds.pop_back();
        }
        
        findCombination(index+1, arr, ds, target, ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0,candidates,ds,target,ans);
        return ans;
    }
};