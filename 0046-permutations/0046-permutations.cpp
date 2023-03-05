class Solution {
    void permutation(vector<int>& nums, vector<vector<int>> &v ,int i){
        //base case
        if( i>=nums.size() ){
            v.push_back(nums);
            return;
        }
        
        for(int j=i; j<nums.size(); j++){
            swap(nums[i],nums[j]);
            permutation(nums,v,i+1);  //fixing the character 
            //backtacking 
            swap(nums[i],nums[j]);
        }
        
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
            int i=0;
		    vector<vector<int>> v;
		    permutation(nums,v,i);
		    return v;
    }
};