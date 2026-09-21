class Solution {
    public int[] shuffle(int[] nums, int n) {
        int i=0;
        int j = (2*n)/2;
        int ans[] = new int[2*n];

        int k = 0;
        while(k<2*n){
            ans[k++] = nums[i++];
            ans[k++] = nums[j++];
        }

        return ans;
    }
}