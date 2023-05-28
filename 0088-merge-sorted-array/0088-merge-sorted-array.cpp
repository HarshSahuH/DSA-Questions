class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        vector<int> arr(m+n);
        int index1 = 0;
        int index2 = 0;
        int i=0;
        while(index1<m && index2 < n){
            if(nums1[index1] < nums2[index2]){
                arr[i++]=nums1[index1++];
            }
            else{
                arr[i++]=nums2[index2++]; 
            }
        }
        while(index1 < m){
            arr[i++] = nums1[index1++];
        }
        while(index2 < n){
            arr[i++] = nums2[index2++];
        }
        
        for(int i=0; i<arr.size(); i++){
            nums1[i] = arr[i];
        }
    }
};