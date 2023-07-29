class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        //edge case 
        if(n==1){
            return 0;
        }
        
        int Water_Trap_sum = 0;
        vector<int> mxLeft(n);
        vector<int> mxRight(n);
        vector<int> water(n);
        
        
         // this array will store maximum value in left of arr of that particular arr[i]
        mxLeft[0]=height[0];
        for(int i=1; i<n; i++){
            mxLeft[i] = max(height[i] , mxLeft[i-1]);
        }
        
        
         // this array will store maximum value in right of arr of that particular arr[i]
        mxRight[n-1] = height[n-1];
        for(int i=n-2; i>=0; i--){
            mxRight[i] = max(height[i] , mxRight[i+1]);
        }
        
        
        for(int i=0; i<n; i++){
         water[i] = (min(mxRight[i] , mxLeft[i])) - height[i];  
         Water_Trap_sum += water[i]; 
        }
        
       // for(int i=0; i<n; i++){
          //  Water_Trap_sum += water[i];  
        //}
         
   
        return Water_Trap_sum;
    }
};