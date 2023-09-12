class Solution {
    bool SubsetSum(vector<int> &nums, long long sum, int n){
    
      int t[n+1][sum+1] ;
    
    
      for(int i=0 ; i<=n ; i++){
          t[i][0]=1 ; 
      }
      for(int i=0 ; i<=sum ; i++){
          t[0][i]=0 ;
      }
      
    //   this is case of when we take empty set 
      t[0][0]=1 ; 
      
      
      for(int i=1 ; i<=n ; i++){
          for(int j=1 ; j<=sum ; j++){
                if(nums[i-1]<=j){
                    t[i][j] = (t[i-1][j-nums[i-1]] || t[i-1][j]) ;
                }
                else{
                    t[i][j] = t[i-1][j] ;   
                }
          }
      }
      return t[n][sum] ;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        long long  sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
        }
        
        if(sum % 2 != 0){
            return false;
        }
        else{
            return SubsetSum(nums,sum/2,n);
        }
    }
};

//T.C. O(n^2)
//S.C. O(n*sum)