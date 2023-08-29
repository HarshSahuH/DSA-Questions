class Solution {
public:
    //brute force T.C. O(N) + O(N) , S.C. O(N)
    void rotate(vector<int>& nums, int k) {
        
                int n = nums.size();
        if (n == 1 || k % n == 0) {
            return;
        }
        
        k = k % n;  // Adjust k to be within the range of array size
        
        vector<int> arr(n);
        int j = 0;
        
        for (int i = n - k; i < n; i++) {
            arr[j++] = nums[i];
        }
        
        for (int i = 0; i < n - k; i++) {
            arr[j++] = nums[i];
        }
        
        for (int i = 0; i < n; i++) {
            nums[i] = arr[i];
        }
    }
};