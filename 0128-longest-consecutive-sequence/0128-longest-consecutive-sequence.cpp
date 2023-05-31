class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //edge case
        if(nums.size()==0){
            return 0;
        }
        
        unordered_set<int> s; //insertion and find will happen in O(1)
        int ans = INT_MIN;
        
        //putting all element into set 
        for(int i=0; i<nums.size(); i++){
           s.insert(nums[i]); 
        }
        
        //now traverse the array and if nums[i] - 1 is present in set 
        // then no need to check for further lesser than that element because 
        // that element will never.
        // check for higher one 
        for(int i=0; i<nums.size(); i++){
            
            if(s.find(nums[i]-1) != s.end()){
                continue;
            }
            else{
                //set mein nahi mila nums[i]-1 , iska mtlb this may be starting of                          consecutive sequence
                int count = 0;
                int curr = nums[i];
                while(s.find(curr) != s.end()){
                    count++;
                    curr++;
                    ans = max(ans , count);
                        
                }
            }
        }
        return ans;
    }
};