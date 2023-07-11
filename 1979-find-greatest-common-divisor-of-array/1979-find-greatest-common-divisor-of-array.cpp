class Solution {
    int gcd(int a, int b)
    {
        //eukelidean  method 
        if(a == 0) return b;
        if(b == 0) return a;
        if(a == b) return a;
        
        if(a>b) 
            return gcd(a-b,b);
        return gcd(a,b-a);
    }
public:
    int findGCD(vector<int>& nums) {
        int small = INT_MAX;
        int large = INT_MIN;
        
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] < small) small = nums[i];
            if(nums[i] > large) large = nums[i];
        }
        
        return gcd(small,large);  
    }
};