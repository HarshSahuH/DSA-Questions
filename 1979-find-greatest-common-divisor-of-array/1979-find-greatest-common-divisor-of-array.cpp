class Solution {
    int GCD(int A,int B){
        //if(A==0) return B;
        //else if(B==0) return A;
        //else if(A==B) return A;
        //else if(A>B) return GCD(A-B,B);
        //else return GCD(A,B-A);
        
        if(A==0) return B;
        return GCD(B%A,A);
    }
    
public:
    int findGCD(vector<int>& nums) {
        
        int smallest = INT_MAX, largest = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            smallest = min(smallest,nums[i]);
            largest = max(largest,nums[i]);
        }
        
        return GCD(smallest,largest); 
    }
};