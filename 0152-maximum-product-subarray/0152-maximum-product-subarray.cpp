class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currProduct =1;
        int maxProduct = INT_MIN;
        
        for(int i=0; i<nums.size(); i++){
            currProduct *= nums[i]; 
            maxProduct = max(currProduct, maxProduct);
            
            if(currProduct == 0){
                currProduct = 1;
            }
        }
        
        currProduct = 1;
        for(int i=nums.size()-1; i>=0; i--){
            currProduct *= nums[i];
            maxProduct = max(currProduct,maxProduct);
            
            if(currProduct == 0){
                currProduct = 1;
            }
        }
        return maxProduct;
    }
};