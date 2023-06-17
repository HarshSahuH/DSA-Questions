class Solution {
public:
    int smallestEqual(vector<int>& nums) {
        int smallest = INT_MAX;
        
        for(int i=0; i<nums.size(); i++){
            if( i%10 != nums[i]){
                continue;
            }
            else if( i%10 == nums[i]){
                smallest = min(smallest,i);
            }
        } 
        if(smallest == INT_MAX){
            return -1;
        }
        else
        return smallest;    
    }
};