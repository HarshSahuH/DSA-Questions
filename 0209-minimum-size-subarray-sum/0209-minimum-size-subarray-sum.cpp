class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
      int min_len = INT_MAX;
      if(nums[0] > target) return 1;
      
      int start = 0, end = 0;
      int curr_sum = 0;
      int n = nums.size();
      while(end < n){
          
          while(curr_sum <target && end<n)
          curr_sum += nums[end++];
          
          while(curr_sum >= target && start < n){
             if(end-start < min_len) 
             min_len = end-start;
             
              curr_sum -=nums[start++];
          } 
      }
        
      return (min_len == INT_MAX)?0:min_len  ; 
    }
};

     /* //Brute force T.C. O(n^2) S.C. O(1)
        int n = nums.size();
        if( n==1 && target > nums[0] ) return 0;
        if(n==1 && target <= nums[0]) return 1;
        
        int min_size = INT_MAX;
        
        for(int i=0; i<n; i++){
            int sum = 0; 
            for(int j=i; j<n; j++)
            {
                sum += nums[j];
                int curr_size = j-i+1;
                if(sum >= target && curr_size < min_size ){
                    min_size = min(min_size , curr_size);
                }
            }
        }
     if(min_size == INT_MAX) return 0;
     else return min_size;*/