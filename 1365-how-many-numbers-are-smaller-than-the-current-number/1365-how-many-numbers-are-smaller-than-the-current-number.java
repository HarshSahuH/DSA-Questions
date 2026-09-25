class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];
        int k=0;

        for(int i = 0; i < n; i++){
            int smaller = 0;
            for(int j = 0; j<n; j++){
                if(nums[i] > nums[j] && j!=i){
                    smaller++;
                }
            }
            ans[k++] = smaller;
        }
        return ans;
    }
}