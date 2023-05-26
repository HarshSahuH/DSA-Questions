#include <unordered_map>
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
     
        int slow = nums[0];
        int fast = nums[0];
        
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
          }while(slow!=fast);
        
        fast = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return fast; 
    }
};

/* 
        Approach 1 T.C. O(N) S.C. O(N)
        int ans;
        unordered_map<int,int> m; 
        
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        
        for(int i=0; i<m.size(); i++){
            if(m[nums[i]]>1){
                ans =   nums[i];
                break;
            }
        }
        return ans;
        */