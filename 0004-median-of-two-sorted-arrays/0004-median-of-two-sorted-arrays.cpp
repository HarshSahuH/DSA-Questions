class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> combined;
        
        for(int i=0; i<nums1.size(); i++){
            combined.push_back(nums1[i]);
        }
        
        for(int i=0; i<nums2.size(); i++){
            combined.push_back(nums2[i]);
        }
        
        sort(combined.begin(),combined.end());
        int n = combined.size();
        if(n == 1) return combined[0];
        if(n%2 != 0){
            return combined[n/2];
        }
        else{
            return (combined[n/2] + combined[(n/2)-1])/2.0;
        }
    }
};