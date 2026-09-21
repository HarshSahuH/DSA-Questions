class Solution {
    public int[] getConcatenation(int[] nums) {
        int n = nums.length;
        int ans[] = new int[2*n];
        int m = 2*n; 

        for(int i=0; i<n; i++){
           ans[i] = nums[i];
        }

        int mid = (2*n)/2;
        int j = 0;
        for(int i=mid; i<m; i++){
            ans[i] = nums[j++];
        }

        return ans;
    }
}


/*



 */
